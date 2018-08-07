#include "funciones.h"
#include "sub.h"

//creo la estructura que va a tener todos los subtitulos

struct arreglo_sub * abrir(void * s,FILE * entrada){
	struct arreglo_sub * sub;
	entrada = fopen ((char *)s,"r+");
	if(entrada == NULL){
		fprintf(stderr,"No se pudo abrir el archivo %s.\n",(char *)s);
	}
	sub = inicializar(entrada);
	fclose(entrada);
	return sub;
}

void salir(void * s,FILE ** salida){
	printf("El archivo de salida va a ser: %s\n",(char *) s);
	*salida = fopen ((char *)s,"w");
	if(*salida == NULL){
		fprintf(stderr,"No se pudo abrir el archivo %s.\n",(char *)s);
	}
}

void modificar_salida(FILE ** salida,struct arreglo_sub * arr_sub){
	crear_salida(arr_sub,salida);
	fclose(*salida);
}

struct arreglo_sub * borrar_indice(void * args,struct arreglo_sub * arr_sub){
	int *tmp = (int *) args;
	int indice = *tmp;
	int i = 1;
	while(i <= arr_sub->ocupado){
		if(arr_sub->a[i].indice == indice){
			break;
		}
		i++;
	}
	if(i >= arr_sub->ocupado && indice != arr_sub->a[i].indice){
		printf("No se encontro el indice a borrar.");
	}
	else{
		for (;i<arr_sub->ocupado;i++){
			arr_sub->a[i + 1].indice = i + 1;
			arr_sub->a[i] = arr_sub->a[i + 1];
		}

		arr_sub->ocupado = arr_sub->ocupado ;
	}
	return arr_sub;
}



struct arreglo_sub * insertar(void *args, struct arreglo_sub * arreglo){

	struct sub *dato = (struct sub *) args;
	int j;

	if(arreglo->ocupado == arreglo->tamanio){
    		arreglo->a = (struct sub *)realloc(arreglo->a, arreglo->tamanio * sizeof(struct sub) + 1 * sizeof(struct sub));
 	}

	if(dato->fin < arreglo->a[0].inicio){
		j = 0;
	}
	else{
		j = 1;
		while(j < arreglo->ocupado && dato->inicio > arreglo->a[j].fin){
			j++;
		}
	}
	if(j < arreglo->ocupado){
		for(int i = arreglo->ocupado; i >= j ; i--){
			arreglo->a[i].indice = arreglo->a[i].indice + 1;
			arreglo->a[i + 1] = arreglo->a[i];
		}
		dato->texto = realloc(dato->texto,strlen(dato->texto) + sizeof(char));
		strcat(dato->texto,"\n");
	}

	dato->indice = j + 1;
	arreglo->a[j] = *dato;
	arreglo->ocupado += 1;
	free(dato);
	return arreglo;
}


void validar(struct arreglo_sub * arr_sub){

	if ((arr_sub->a[0].indice) != 1){
		error(1, "El primer indice no es 1.");
	}

	//se trabaja con un sub
	for(int i = 0; i < arr_sub->ocupado; i++){
		int total_carac = procesar_texto (arr_sub->a[i].texto, arr_sub->a[i].indice);
		if(minimo_duracion_sub(arr_sub->a[i].inicio,arr_sub->a[i].fin) == 1){
			error(arr_sub->a[i].indice,"El subtitulo dura menos de 1 seg.");
		}

		if(maximo_duracion_sub(arr_sub->a[i].inicio,arr_sub->a[i].fin)){
			error(arr_sub->a[i].indice,"El subtitulo dura mas de 7 seg.");
		}

		if(chars_por_seg(total_carac,arr_sub->a[i].inicio,arr_sub->a[i].fin)){
			error(arr_sub->a[i].indice,"El subtitulo tiene demasiados caracteres por segundo.");
		}
		if(i != arr_sub->ocupado - 1){

			if((arr_sub->a[i].indice+1) != arr_sub->a[i+1].indice){
				error(arr_sub->a[i].indice,"Los indices no son consecutivos ordenados.");
			}

			if(solapados_sub(arr_sub->a[i].fin, arr_sub->a[i+1].inicio) == 1){
				error(arr_sub->a[i].indice,"El subtitulo esta solapado con el siguiente.");

			} else {

				if (separacion_sub(arr_sub->a[i].fin, arr_sub->a[i].inicio)) {
					error(arr_sub->a[i].indice,"Hay menos de 75 ms. entre el subtitulo y el siguiente.");
				}
			}
		}
	}

}


void procesar_operacion(struct arreglo_opciones *optargs) {
  	FILE * entrada = NULL, * salida = NULL;
	struct arreglo_sub * arr_sub;

for(int i = 0; i <= optargs->ocupado ;i++){
  switch (optargs->opciones[i].opcion) {

   case IN:
	printf("Abriendo archivo...\n");
	arr_sub = abrir(optargs->opciones[i].args,entrada);
	continue;
    case OUT:
	printf("Abriendo archivo de salida...\n");
	salir(optargs->opciones[i].args,&salida);
	continue;
   case BORRAR:
	if(salida != NULL){
      		printf("Borrando...\n");
      		arr_sub = borrar_indice(optargs->opciones[i].args,arr_sub);
	}
	else{
		printf("No se puede borrar, no hay archivo de salida.\n El argumento -o es obligatorio cuando hay opciones que modifican el archivo de entrada.");
	}
      	continue;
    case INSERTAR:
	if(salida != NULL){
      		printf("Insertando...\n");
		arr_sub = insertar(optargs->opciones[i].args,arr_sub);
	}
	else{
		printf("No se puede Insertar, no hay archivo de salida.\n El argumento -o es obligatorio cuando hay opciones que modifican el archivo de entrada.");
	}
	continue;
    case VALIDAR:
		printf("Validando...\n");
	      	validar(arr_sub);
      continue;
  }

}	if(salida != NULL){
		modificar_salida(&salida,arr_sub);
	}
	free(arr_sub->a);
	free(arr_sub);
}
