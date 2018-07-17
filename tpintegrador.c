#include <stdio.h>
#include <string.h>


void borrar_indice(){
	FILE * fp;
	char dato1[100];
	int indice,indice_borrar,pun,despl;	//Las ultimas dos variables van a ayudar a moverse dentro del archivo.

	fp = fopen ("unpath" ,"r+");		//unpath debe ser reemplazado por el archivo de subtitulos que se espera modificar.

	//Lee el numero de indice a borrar
	printf("Ingresar indice del subtitulo a borrar: ");
	scanf("%d",&indice_borrar);

	//La funcion de borrar en si
	
	//LEE EL INDICE.
	fscanf(fp,"%d\n",&indice);
	//MUEVE HASTA EL INDICE A BORRAR.
	while(indice < indice_borrar){
		fgets(dato1, 100 ,fp);
		fscanf(fp,"%d\n",&indice);
	}
	
	//Lee la linea que contiene el tiempo de inicio y de fin.		
	fgets(dato1, 100 ,fp);
	pun = ftell(fp);
	int i= 0;

	//NO BORRA el subtitulo, solo establece una "marca de borrado", en el archivo original.
	while(strcasecmp((fgets(dato1, 100 ,fp)),"\n")){
		despl = (ftell(fp) - pun);
		fseek(fp,-despl,SEEK_CUR);						
		fputs("*",fp);
		fseek(fp,despl,SEEK_CUR);
		pun = (ftell(fp)-1);				
	}	

	fclose(fp);
}


int main(){

	borrar_indice();

}
