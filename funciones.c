#include "funciones.h"
#include "sub.h"

//aca creo la estructura que va a tener todos lso subtitulos
			//IDEA hacer punteros a funciones a esta funcion para reutilizar codigo
struct arreglo_sub * abrir(char * s,FILE * entrada){  //tengo que pasar la entrada por referencia????
	struct arreglo_sub * sub;
	entrada = fopen (s,"rb+");
	if(entrada == NULL){
		fprintf(stderr,"No se pudo abrir el archivo %s.\n",s);
	}
	sub = inicializar(entrada);
	return sub;
}

void salir(char * s,FILE ** salida){
	printf("El archivo de salida va a ser: %s",s);
	getchar();
	*salida = fopen (s,"a");
	if(*salida == NULL){
		fprintf(stderr,"No se pudo abrir el archivo %s.\n",s);
	}
}

void modificar_salida(FILE ** salida,struct arreglo_sub * arr_sub){
	crear_salida(arr_sub,salida);
	fclose(*salida);
}

struct arreglo_sub * borrar_indice(int indice,struct arreglo_sub * arr_sub){

	for(int i = 0; i <= arr_sub->ocupado; i++){
		printf("Indice:%d  \n Texto: %s \n",arr_sub->array[i].indice,arr_sub->array[i].texto);//(arr_sub + i * 8)->indice,(arr_sub + i * 8)->texto);
	}
	int i = 0;
	while(i <= arr_sub->ocupado){
		if(arr_sub->array[i].indice == indice){
			break;
		}
		i++;
	}
	if(i >= arr_sub->ocupado && indice != arr_sub->array[i].indice){
		printf("No se encontro el indice a borrar.");
	}
	else{
		for (;i<arr_sub->ocupado;i++){
			arr_sub->array[i] = arr_sub->array[i + 1];
		}
		//free((void * )arr_sub[dim_l]);	deberia liberar al sorete que quedo dando vueltas
	}
	for(int i = 0; i <= arr_sub->ocupado; i++){
		printf("Indice:%d  \n Texto: %s \n",arr_sub->array[i].indice,arr_sub->array[i].texto);//(arr_sub + i * 8)->indice,(arr_sub + i * 8)->texto);
	}

	return arr_sub;
}




/*int busquedaBinaria(struct sub *vector, int n, int indice) { // n va a ser dim_l
  	int centro,inf=0,sup=n-1;
   	while(inf<=sup){
      		centro=((sup-inf)/2)+inf;
      		if(vector[centro].indice==indice){
			return centro;
		}
      		else if(indice < vector[centro].indice){
				sup=centro-1;
			}
      		      else{
				inf=centro+1;
			}
  	 }
   	return -1;
}*/

/*
struct arreglo_sub * insertar(struct arreglo_sub * arreglo){

	int i = 0, pos;
	char *dato1 = malloc(sizeof(char) * 100);
	struct sub *dato = malloc(sizeof(struct sub)) ;
	printf("Ingresar informacion del dato:\n");
	scanf("%d",&dato->indice);
	scanf("%d",&dato->inicio.tm_hour);

		scanf("%d",&dato->inicio.tm_min);

		scanf("%d",&dato->inicio.tm_sec);

		scanf("%d",&dato->inicio.tm_ml);
		scanf("%d",&dato->fin.tm_hour);

		scanf("%d",&dato->fin.tm_min);

		scanf("%d",&dato->fin.tm_sec);

		scanf("%d",&dato->fin.tm_ml);
	dato->texto = malloc(sizeof(char) * 100);

	while(scanf("%s",dato->texto) != EOF){
		printf("%d",pos);
		//scanf("%s",dato->texto);
	}
	printf("Paso el while\n");
	getchar();
	/*if((pos = busquedaBinaria(arreglo,dim_l,dato->indice)) == -1){
		printf("No se encontro la posicion solicitada.\n");
	}
	else{
		//if()//hay espacio ??
		if((arreglo + dato->indice * 8)->indice != 0){ // no funciona esta parte
		for(dim_l; dim_l >= dato->indice;dim_l--){
			*(arreglo + (dim_l + 1) * 8 ) = *(arreglo + (dim_l + 1) * 8 );
		}
		*(arreglo + dato->indice * 8) = *dato;
		}
		else{	//esta parte (que inserta directamente) funciona
			*(arreglo + dato->indice * 8) = *dato;
		}
	//}

	if(arreglo->ocupado == arreglo->tamanio){
    		arreglo->tamanio *= 2;
    		arreglo->a = (struct sub *)realloc(arreglo->a, arreglo->tamanio * sizeof(struct sub));
 	 }
  	for(int i = arreglo->ocupado; i >= dato->indice - 1; i--){
		arreglo->a[i] = arreglo->a[i - 1];

	}
	arreglo->a[dato->indice - 1] = *dato;
	printf("Indice:%d  \n Texto: %s \n",arreglo->a[dato->indice].indice,arreglo->a[dato->indice].texto);
	//free(dato);
	return arreglo;
}
*/

long process_operation(struct arreglo_opciones *optargs) {
  	FILE * entrada = NULL, * salida = NULL;
	struct arreglo_sub * arr_sub;
	long tmp = 123;
for(int i = 0; i <= optargs->ocupado ;i++){
	printf("Entrada nro: %d",i);
	getchar();
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
      printf("Borrando...\n");
      	arr_sub = borrar_indice(4,arr_sub);	/*optargs->opciones[i].args aca deberia tener guardado el argumento oara mandar */
      	continue;
	/*
    case INSERTAR:
      printf("Insertando...\n");
	arr_sub = insertar(arr_sub);
	continue;
	*/
    /*case VALIDAR:

      continue;*/
  }

}
	modificar_salida(&salida,arr_sub);
	return tmp;

}
