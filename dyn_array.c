#include <stdio.h>
#include <stdlib.h>
#include "dyn_array_int.h"

void dyn_array_init(dyn_array *array) {
  // inicializar tamaño y capacidad
  array->dim_l = 0;
  array->dim_f = DYNAMIC_ARRAY_INITIAL_CAPACITY;

  // alocar memoria para array->dato
  array->dato = calloc(array->dim_f, sizeof(t_subtitulo *));
}

int dyn_array_is_full(dyn_array *array) {
  if (array->dim_l >= array->dim_f) {
    return 1;
  } else {
    return 0;
  }
}

void dyn_array_duplicate(dyn_array *array) {
    // duplicar array->capacidad y agrandar el arreglo acordemente
    array->dim_f *= 2;
    array->dato = realloc(array->dato, sizeof(t_subtitulo *) * array->dim_f);
}

void dyn_array_append(dyn_array *array, t_subtitulo dato) {
  // asegurarse de que hay espacio para agregar
  if (dyn_array_is_full(array)) {
    dyn_array_duplicate(array);
  }

  // anexar valor e incrementar tamaño
  array->dato[array->dim_l++] = dato;
}

t_subtitulo dyn_array_get(dyn_array *array, unsigned long indice) {
  if (indice >= array->dim_l) {
    printf("Index %d out of bounds for array of size %d\n", indice, array->dim_l);
    exit(1);
  }
  return array->dato[indice];
}

void dyn_array_free(dyn_array *array) {
  free(array->dato);
}
