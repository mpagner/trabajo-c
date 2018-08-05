#define _GNU_SOURCE
//#include "dyn_array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i_hh = 0, i_mm = 0, i_ss = 0, i_ms = 0,
               f_hh = 0, f_mm = 0, f_ss = 0, f_ms = 0;
    unsigned long indice;
    char *texto = NULL;
    char *buf = NULL;
    ssize_t nlinea;
    size_t len = 0;
    FILE *fp = fopen("./Going for Gold 2018 1080p WEBRip DDP5.1 x264-FGT.srt", "r");
    if (fp != NULL){
        fscanf(fp, "%lu\n", &indice);
        fscanf(fp, "%d:%d:%d,%d --> %d:%d:%d,%d\n",
               &i_hh, &i_mm, &i_ss, &i_ms,
               &f_hh, &f_mm, &f_ss, &f_ms);
        while ((nlinea = getline(&buf, &len, fp) != 2)){
            if (texto == NULL){
                texto = malloc(strlen(buf)+1);
            } else {
                texto = realloc(texto, strlen(texto) + strlen(buf)+1);
            }
        strcat(texto, buf);
        }
    }
    printf("%lu\n", indice);
    printf("%d:%d:%d,%d --> %d:%d:%d,%d\n",
            i_hh, i_mm, i_ss, i_ms,
            f_hh, f_mm, f_ss, f_ms);
    printf("%ld\n", nlinea);
    puts(texto);
    fclose(fp);
}
