#ifndef ARGS_H
#define ARGS_H 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "sub.h"

#define BORRAR 		1
#define INSERTAR	2
#define VALIDAR		3
#define IN		4
#define OUT		5

enum{
	BORRAR_I,
	INSERTAR_I,
	VALIDAR_I,
	IN_I,
	OUT_I
};

struct arr{
	int opcion;
	void * args;
};

struct arreglo_opciones{
	struct arr *opciones;
	int tamanio;
	int ocupado;
};

struct arreglo_opciones *recuperar_args(int argc, char **argv);

#endif
