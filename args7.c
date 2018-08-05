#include "args.h"



char *opc[] = {
	"-b",
	"-i",
	"-v",
	"-f",
	"-o"
};

static void init_arreglo(struct arreglo_opciones *a, int initial_size) {
  a->opciones = (struct arr *)malloc(initial_size * sizeof(struct arr));
  a->tamanio = initial_size;
  a->ocupado = 0;
}

struct arr *insertar_opciones(int opt, char * s){		//creo que aca voy a necesitar lista de argumentos variable
  struct arr *tmp;
	tmp = (struct arr *) malloc(sizeof(struct arr));
	tmp->opcion = opt;
	strcpy(tmp->args,s);	//arreglar el tema del tamaño	
	return tmp;
	
}

struct arreglo_opciones *insert_operand(struct arreglo_opciones *a, struct arr * dato){
  if (a->ocupado == a->tamanio) {
    a->tamanio *= 2;
    a->opciones = (struct arr *)realloc(a->opciones, a->tamanio * sizeof(dato));
  }
  a->opciones[a->ocupado++] = *dato;
  return a;
}



struct arreglo_opciones *recuperar_args(int argc, char **argv){
	struct arreglo_opciones * arreglo = calloc (1, sizeof(struct arreglo_opciones));  //revisar esta sentencia e init:arreglo de abajo
	struct arr * tmp;
	init_arreglo(arreglo,sizeof(struct arr));

	int entrada = 0 ,salida = 0;
	//primer recorrido para recuperar -f y -o (en caso que haya). Voy a guardar estos datos en un arreglo separado para poder trabajar cuando necesite con estos datos.
	for(int i = 0; i < argc; i++){
		
		//para agregar -f
		if(strcasecmp (argv[i],"-f") == 0){
			if(entrada == 0){
				arreglo = insert_operand(arreglo,insertar_opciones(4,argv[i+1]));
				printf("%s",argv[i+1]);
				entrada++;
			}
			else{
				fprintf(stderr,"Solo se puede ingresar una vez el parametro -f [archivo].\n");
				exit (1);
			}
		}
	
		//para agregar -o
		if(strcasecmp (argv[i],"-o") == 0){
				if(salida == 0){
					arreglo = insert_operand(arreglo,insertar_opciones(5,argv[i+1]));
					salida++;
				}
				else {
					fprintf(stderr,"Solo se puede ingresar una vez el parametro -o [archivo].\n");
					exit (1);
				}
		}
	}
	if(entrada == 0){
		fprintf(stderr,"El argumento -f es obligatorio.\n");
		exit(2);
		
	}
	printf("El tamaño de arreglo: %d",sizeof(struct arr) / sizeof(arreglo->opciones));
	printf("Nombre del archivo de entrada:%s",arreglo->opciones->args);
	getchar();
	

	//agarrar el resto de los argumentos e imprimir los valores que tiene el supuesto arreglo de las opciones que llegan como argumentos
	for(int i = 0; i < argc; i++){
	
		int optindex;	
		for(optindex = 0; optindex < 3; optindex++){	
			if(strcasecmp(argv[i],opc[optindex])== 0){
				arreglo = insert_operand(arreglo,insertar_opciones(optindex + 1,"hola"));
				// recordar modificar esta funcion ---> insert_operand(arreglo,optindex + 1);
			}
		}
	
	}
	printf("El arreglo:\n");
	for(int i = 0; i < arreglo->ocupado;i++){
		printf("%d",arreglo->opciones[i].opcion);
	}
	printf("\n");
	
	printf("El tamaño de arreglo: %d", sizeof(struct arr) /sizeof(arreglo->opciones));
	getchar();

	return arreglo;
}
