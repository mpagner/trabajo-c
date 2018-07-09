#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//parte de time.h
struct tm{
  int tm_ml;			/* Milisegundos. [0-999]*/
  int tm_sec;			/* Seconds.	[0-60] (1 leap second) */
  int tm_min;			/* Minutes.	[0-59] */
  int tm_hour;			/* Hours.	[0-23] */
};


/*struct tm *leer_tm(FILE * fp){
	
	return tiempo;
}*/

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

	//LEO EL TIEMPO.
	/*printf("%c",c = fgetc(fp));
	printf("%c",c = fgetc(fp));
	printf("%c",c = fgetc(fp));
	printf("%c",c = fgetc(fp));
	printf("%c",c = fgetc(fp));
	getchar();
	fscanf(fp,"%d",&tm1.tm_hour);
	fgetc(fp);
	fscanf(fp,"%d",&tm1.tm_min);
	fgetc(fp);
	fscanf(fp,"%d",&tm1.tm_sec);
	fgetc(fp);
	fscanf(fp,"%d",&tm1.tm_ml);
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fgetc(fp);
	fscanf(fp,"%d",&tm2.tm_hour);
	fgetc(fp);
	fscanf(fp,"%d",&tm2.tm_min);
	fgetc(fp);
	fscanf(fp,"%d",&tm2.tm_sec);
	fgetc(fp);
	fscanf(fp,"%d",&tm2.tm_ml);

	
	//Imprimo para comprobar el valor de la estructura.
	printf("%d:",tm1.tm_hour);
	printf("%d:",tm1.tm_min);
	printf("%d,",tm1.tm_sec);
	printf("%d",tm1.tm_ml);



	//Recuperar texto del archivo.
	
	//fscanf(fp,"%s",&dato1);
	fgetc(fp);
	fgets(dato1, 100 ,fp);
	fgets(dato2, 100 ,fp);

	//fscanf(fp,"%s",dato2);
	printf("%s",dato1);
	printf("%s",dato2);


	//Estaba probando si podia posicionarme. Despues entendi que el archivo es dinamico(NO hay campos fijos, entonces no me puedo ir moviendo tan facilmente).
	/*fseek(fp , 3, SEEK_SET);
	printf("%d\n",ftell(fp));
	
	//printf("%s\n",fgets(dato,10,fp));	Estoy usando mal el fgets() !! */


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
