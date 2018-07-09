#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void borrar_indice(){
	FILE * fp;
	char dato1[100], *dato2 = " ",*dato3 = "-";	
	char c;
	int indice,indice_borrar,pun,despl;
	struct tm tm1,tm2;

	fp = fopen ("/home/nacho/Descargas/Shrek.srt" ,"r+");

	//printf("%d\n",fgetc(fp));

	//LEO EL INDICE.
	fscanf(fp,"%d\n",&indice);
	printf("Indice :%d\n",indice);

	//Leo el numero de indice a borrar
	printf("Ingresar indice del subtitulo a borrar: ");
	scanf("%d",&indice_borrar);

	//La funcion de borrar en si
	//ME MUEVO HASTA EL INDICE A BORRAR.
	while(indice < indice_borrar){
		//VOY A PASAR POR TODOS LOS CAMPOS PARA MOVERME					ARREGLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR!!
		fgets(dato1, 100 ,fp);
		if(strcasecmp(dato1,dato2)){
			printf("ENtro indice %d\n",indice);
									//aca saque un while que tenia un fgets porque quedaba en loop infinito !!!
			
		}
			//fgets(dato1, 100 ,fp);			no se si esta sentencia sirve
		  fscanf(fp,"%d\n",&indice);
	}
	
	printf("%d\n",indice);

	
	//Agarre el indice ahora tengo que modificarlo.					--> Compactar archivo???		//4/7 solucione el problema que consumia lineas de otros indices.
	fgets(dato1, 100 ,fp);
	pun = ftell(fp);
	int i= 0;
	
	
	while(strcasecmp((fgets(dato1, 100 ,fp)),"\n")){
		despl = (ftell(fp) - pun);
		printf("%d\n%d\n",despl,pun); //para saber si funciona despl
		//estas dos lineas me solucionaron el tema de las que comia de mas
		fseek(fp,-despl,SEEK_CUR);						
		fputs("*",fp);
		//hasta aca
		fseek(fp,despl,SEEK_CUR);
		pun = (ftell(fp)-1);				//el -1 es porque creo que tiene en cuenta el \0
	}	



	fclose(fp);
}


int main(){

	borrar_indice();


}
