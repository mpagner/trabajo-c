#include <stdio.h>
#include <stdlib.h>

void error(int indice, char *errstr);

int procesar_texto (char* text, int indice);

int solapados_sub(size_t fin_prev, size_t ini_sig);

int separacion_sub(size_t fin_prev, size_t ini_sig);

int minimo_duracion_sub(size_t ini, size_t fin);

int maximo_duracion_sub(size_t ini, size_t fin);

int chars_por_seg(int total_carac, size_t ini, size_t fin);
