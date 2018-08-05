#ifndef _SUB_H
#define _SUB_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tm{
    int tm_ml;			/* Milisegundos. [0-999]*/
    int tm_sec;			/* Seconds.	[0-60] (1 leap second) */
    int tm_min;			/* Minutes.	[0-59] */
    int tm_hour;		/* Hours.	[0-23] */
};


struct sub{
	int indice;
	size_t inicio;
	size_t fin;
	char *texto;

};

struct arreglo_sub{
	struct sub *array;
	int ocupado;
	int tamanio;
};

struct arreglo_sub * inicializar(FILE * entrada);

void crear_salida(struct arreglo_sub * sub,FILE ** salida);


#endif
