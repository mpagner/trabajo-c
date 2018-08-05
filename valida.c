int countar_saltos_linea (char* text){
    int salto;
    for(int i = 0; text[i] != '\0'; i++){
        if (text[i] == '\n'){
            salto++;
        }
    }
    return salto;
}

int contar_caracteres_en_linea(char *text){
    int caracteres;
    for(int i; text[i] != '\0'; i++){
       if (text[i] == '\n'){
          break;
       }
       caracteres++;
    }
    return caracteres;
}
