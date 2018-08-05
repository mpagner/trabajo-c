#include "tiempo.h"

/*void init_tm(struct t_tiempo *tm, short hs,
               short mins, short segs, short msegs) {
  tm->tm_hh = hs;
  tm->tm_mm = mins;
  tm->tm_ss = segs;
  tm->tm_ms = msec;

}*/

size_t tm_to_millisec(short hs, short mins, short segs, short msegs) {

  size_t total = 0;
  if (hs != 0){
    total += hs * 60 * 60 * 1000;
  }
  if (mins != 0){
    total += mins * 60 * 1000;
  }
  if (segs != 0){
    total += segs * 1000;
  }
  return total += msegs;
}

void millisec_to_tm(struct t_tiempo *tm, size_t millis){

  int tmp;
  tm->hh = millis / 3600000;
  tmp = millis % 3600000;
  tm->mm = tmp / 60000;
  tmp = tmp % 60000;
  tm->ss = tmp / 1000;
  tm->ms = tmp % 1000;
}
