#ifndef SUBS_H
#define SUBS_H 1

#include "tiempo.h"

typedef struct {
  unsigned long indice;
  tm inicio;
  tm fin;
  char *texto;
} t_subtitulo;

void init_sub(t_subtitulo *sub, unsigned long indice,
              t_tiempo *tm_ini, t_tiempo *tm_fin,
              char *texto);

#endif
