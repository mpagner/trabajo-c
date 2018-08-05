#include "subs.h"

#define DYNAMIC_ARRAY_INITIAL_CAPACITY 100

typedef struct {
	size_t dim_l;						// espacios efectivamente usados
	size_t dim_f;						// espacios disponibles en total
	t_subtitulo *dato[];		// arreglo de punteros a subtitulos
} dyn_array;

void dyn_array_init(dyn_array *array);

void dyn_array_duplicate(dyn_array *array);

void dyn_array_append(dyn_array *array, t_subtitulo dato);

t_subtitulo dyn_array_get(dyn_array *array, unsigned long indice);

/*void dyn_array_set(dyn_array *array, int indice, int valor);*/

void dyn_array_free(dyn_array *array);
