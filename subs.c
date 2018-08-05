#include "subs.h"
#include <stdlib.h>

void init_sub(t_subtitulo *sub, unsigned long indice,
              t_tiempo *tm_ini, t_tiempo *tm_fin,
              char *texto) {

  sub->indice = indice;
  sub->inicio = tm_ini;
  sub->fin = tm_fin;
  sub->texto = malloc(sizeof(char) * strlen(texto) + 1);
  strcpy(sub->texto, texto);

}
