#ifndef TIEMPO_H
#define TIEMPO_H 1

#include <stdlib.h>

struct t_tiempo {
  short hh;    /* Horas. */
  short mm;    /* Minutos.	[0-59] */
  short ss;	  /* Segundos.	[0-59] (1 leap second) */
  short ms;		/* Milisegundos. [0-999]*/
};

/*void init_tm(t_tiempo *tm, short hh,
               short mm, short ss, short ms);
*/
size_t tm_to_millisec(short hs, short mins, short segs, short msegs);

void millisec_to_tm(struct t_tiempo *tm, size_t millis);

#endif
