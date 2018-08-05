#include "sub.h"
#include "tiempo.h"


//quiero crear la estructura para manejar los datos del archivo
struct arreglo_sub * init_arreglo(struct arreglo_sub *a, int initial_size) {
    a->array = (struct sub *)malloc(initial_size * sizeof(struct sub));
    a->tamanio = initial_size;
    a->ocupado = 0;
    return a;
}


struct arreglo_sub *insert_sub(struct arreglo_sub *a, struct sub * dato){
    if (a->ocupado == a->tamanio) {
        a->ocupado *= 2;
        a->array = (struct sub *)realloc(a->array, a->tamanio * sizeof(struct sub));
    }
    a->array[a->ocupado++] = *dato;
    return a;
}

struct arreglo_sub * inicializar(FILE * fp){
	struct arreglo_sub * arreglo = calloc(1,sizeof(struct arreglo_sub));
	arreglo = init_arreglo(arreglo,1);
	struct sub *dato;
    int i_hh = 0, i_mm = 0, i_ss = 0, i_ms = 0,
               f_hh = 0, f_mm = 0, f_ss = 0, f_ms = 0;
    int indice;
    char *texto = NULL;
    char *buf = NULL;
    ssize_t nlinea = 0;
    size_t len = 0, inicio, fin;

	//empiezo a leer
	while((fscanf(fp,"%d\n",&indice) != EOF) && (nlinea != -1)){
        dato = malloc(sizeof(struct sub));
        fscanf(fp, "%d:%d:%d,%d --> %d:%d:%d,%d\n",
               &i_hh, &i_mm, &i_ss, &i_ms,
               &f_hh, &f_mm, &f_ss, &f_ms);
        while ((nlinea = getline(&buf, &len, fp) != 2)){
            if (texto == NULL){
                texto = malloc(strlen(buf)+1);
            } else {
                texto = realloc(texto, strlen(texto) + strlen(buf)+1);
            }
        strcat(texto, buf);
		}
        inicio = tm_to_millisec(i_hh, i_mm, i_ss, i_ms);
        fin = tm_to_millisec(f_hh, f_mm, f_ss, f_ms);
        dato->indice = indice;
        dato->inicio = inicio;
        dato->fin = fin;
        dato->texto = texto;

        printf("%s",dato->texto);

		arreglo = insert_sub(arreglo,dato);
        if (nlinea == -1) printf("%s\n", "nlinea es -1.");

		//free(dato->texto);
		//free(dato);		Si hago el free de estos datos ahora no me deja usarlos en ningun lado posteriormente. averiguar por que? ***

	}
	printf("Salio");
	getchar();


	//quiero imprimir el indice de cada struct que guardo en la estrcutura   !!!!
	//for(int i = 0; i < dim_l; i++){
	//	printf("Indice:%d  \n Texto: %s \n",(arreglo + i * 8)->indice,(arreglo + i * 8)->texto);
		//printf("Dimension logica:%d.\n", dim_l);
	//}

	//dim = dim_l;

	return arreglo;
}


// CREO QUE NO ESTOY PUDIENDO METER LA INFORMACION EN EL ARCHIVO DE SALIDA PORQUE HAY INCOMPATIBILIDAD EN LA FORMA EN QUE LO GUARDE Y EN LA FORMA EN QUE ESTOY TRATANDO DE RECUPERAR LA INFORMACION(EN EL ARCHIVO DE SALIDA ME QUEDAN DIRECCIONES A LA INFORMACION NADA MAS)
void crear_salida(struct arreglo_sub * sub,FILE ** salida){
	printf("Entro a guardar la estructura.");
    struct t_tiempo *tm = (struct t_tiempo *)calloc(1, sizeof(struct t_tiempo));
	getchar();
	for(int i = 0; i < sub->ocupado - 1; i++){
		fprintf(*salida,"%d",sub->array[i].indice);
		fputc('\n',*salida);
        millisec_to_tm(tm, sub->array[i].inicio);
		fprintf(*salida,"%d",tm->hh);
		fputc(':',*salida);
		fprintf(*salida,"%d",tm->mm);
		fputc(':',*salida);
		fprintf(*salida,"%d",tm->ss);
		fputc(',',*salida);
		fprintf(*salida,"%d",tm->ms);
		fputc(' ',*salida);
		fputc('-',*salida);
		fputc('-',*salida);
		fputc('>',*salida);
		fputc(' ',*salida);
        millisec_to_tm(tm, sub->array[i].fin);
		fprintf(*salida,"%d",tm->hh);
		fputc(':',*salida);
		fprintf(*salida,"%d",tm->mm);
		fputc(':',*salida);
		fprintf(*salida,"%d",tm->ss);
		fputc(',',*salida);
		fprintf(*salida,"%d",tm->ms);
		//fputc('\t',*salida);
		fputc('\n',*salida);

		fprintf(*salida,"%s",sub->array[i].texto);
		fputc('\n',*salida);			// EDITAR FORMA DE ACCESO AL CAMPO PARA QUE FUNCIONE
	}
    free(tm);
	//en la salida quedan algunos errores

}
