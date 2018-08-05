#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "args.h"
#include "funciones.h"



int main(int argc,char * argv[]){
	long total;
	struct arreglo_opciones * arreglo = recuperar_args(argc,argv);
	printf("salio al main");
	getchar();
	for(int i = 0; i < arreglo->ocupado;i++){
		printf("%d",arreglo->opciones[i].opcion);
	}
	total = process_operation(arreglo);
	free(arreglo);
}
