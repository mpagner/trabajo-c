#include "valida.h"


void error(int indice, char *errstr){
    fprintf(stderr, "Indice %d:\n", indice);
    fprintf(stderr, "%s\n", errstr);
}

/*  procesar_texto: revisa la cantidad de lineas en el texto del subtitulo,
    la cantidad de caracteres por línea, y devuelve el total de caracteres.
*/

int procesar_texto (char* text, int indice){
    int total_carac = 0, salto = 0, carac_linea = 0, nueva_linea = 0;
    for(int i = 0; text[i] != '\0'; i++){
        if (text[i] == '\n'){
            salto++;
            nueva_linea = 1;
        } else {
            total_carac++;
        }
        if (!nueva_linea){
            carac_linea++;
        } else {
            if (carac_linea > 36){
                error(indice, "La linea tiene mas de 36 caracteres.\n");
            }
            carac_linea = nueva_linea = 0;
        }
    }
    if (salto > 2){
        error(indice, "El subtitulo tiene mas de 2 lineas.\n");
    }

    return total_carac;
}

int solapados_sub(size_t fin_prev, size_t ini_sig){
	if(fin_prev >= ini_sig){
		return 1;
	}
    return 0;
}

int separacion_sub(size_t fin_prev, size_t ini_sig){
        if((ini_sig - fin_prev) <= 75){
		return 1;
	}
	return 0;
}

int minimo_duracion_sub(size_t ini, size_t fin){
    if((fin - ini) < 999){
		return 1;
	}
	return 0;
}

int maximo_duracion_sub(size_t ini, size_t fin){
    if((fin - ini) > 7000){
		return 1;
	}
	return 0;
}
int chars_por_seg(int total_carac, size_t ini, size_t fin){
    float duracion_segs = (fin - ini) * 0.001;
    if((float)(total_carac / duracion_segs) > 25){
		return 1;
	}
	return 0;
}
