#ifndef TIEMPO_H
#define TIEMPO_H 1

typedef struct {
  short hh;    /* Horas. */
  short mm;    /* Minutos.	[0-59] */
  short ss;	  /* Segundos.	[0-59] (1 leap second) */
  short ms;		/* Milisegundos. [0-999]*/
} t_tiempo;

void init_tm(t_tiempo *tm, short hh,
               short mm, short ss, short ms);

#endif
