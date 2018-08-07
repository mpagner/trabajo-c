#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "funciones.h"


int main(int argc,char * argv[]){
	struct arreglo_opciones * arreglo = recuperar_args(argc,argv);
	procesar_operacion(arreglo);
	free(arreglo);
}
