#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct notebook{
    int codigo_maquina;
    char nombre_prestado[20];
    long int dni;
    char fecha_prestamo[12]; //25-06-2024
    char fecha_expiracion[12]; //30-06-2024
    float valor_asegurado;
};

void cargar_datos(struct notebook vector[],int *elementos) {
    printf("Cargue los datos:\n");
  for(int i=0;i<(*elementos);i++) {
      printf("Ingrese el codigo de la maquina %d \n",i+1);
      scanf("%d",&vector[i].codigo_maquina);
      while(getchar()!='\n');

      printf("Nombre de la persona a la que se le presto \n");
      fgets(vector[i].nombre_prestado,20,stdin);
      fflush(stdin);

      printf("DNI \n");
      scanf("%li",&vector[i].dni);
      while(getchar()!='\n');

      printf("Fecha del prestamo\n");
      fgets(vector[i].fecha_prestamo,12,stdin);
      fflush(stdin);

      printf("Fecha de expiracion\n");
      fgets(vector[i].fecha_expiracion,12,stdin);
      fflush(stdin);

      printf("Valor asegurado\n");
      scanf("%f",&vector[i].valor_asegurado);
      while(getchar()!='\n');
  }

}

void imprimir(struct notebook vector[],int *elementos) {
    for(int i=0;i<*elementos;i++){
        printf("Indice: %d \n",i+1);
        printf("Codigo de la maquina: %d \n",vector[i].codigo_maquina);
        printf("Nombre de a quien se le presto: %s \n",vector[i].nombre_prestado);
        printf("DNI: %ld \n",vector[i].dni);
        printf("Fecha del prestamo: %s \n",vector[i].fecha_prestamo);
        printf("Fecha de expiracion: %s \n",vector[i].fecha_expiracion);
        printf("Valor asegurado: %f \n",vector[i].valor_asegurado);

    }
}

void modificar(struct notebook vector[],int *elementos) {
 long int modificar;
    printf("Ingrese el DNI de la persona a la cual quiere modificar la fecha de expiracion \n");
    scanf("%li",&modificar);
    while(getchar()!='\n');
    for(int i=0;i<(*elementos);i++) {
        if(modificar==vector[i].dni) {
            char nuevo [12];
            printf("ingrese la nueva fecha de expiracion:\n");
            fgets(nuevo,12,stdin);
            fflush(stdin);
            strcpy(vector[i].fecha_expiracion,nuevo);
        }
    }

}

int main(void) {
    int opcion=0, borrar,elementos;
    struct notebook *vector; //puntero del tipo struct notebook

    printf("Cuantas notebooks desea cargar? \n");
    scanf("%d",&elementos);
    while(getchar()!='\n');

    //aca asigno la direccion de memoria del bloque que me da molloc() al puntero tipo struct notebook
    vector=(struct notebook *)malloc(elementos*sizeof(struct notebook));
    if(vector==NULL) {
        printf("No Hay Espacio");
        return -1;
    }

    cargar_datos(vector,&elementos);


    while (opcion!=5){
        printf("Elija la opcion deseada\n");
        printf("1-Imprimir Elementos\n"
                        "2-Modificar Fecha de Expiracion mediante DNI\n"
                        "3-Modificar Todo\n"
                        "4-Borrar por indice\n"
                        "5-Salir\n"
                        );
        scanf("%d",&opcion);
        while(getchar()!='\n');

        switch (opcion) {
            case 1: imprimir(vector,&elementos);
                    break;

            case 2: modificar(vector,&elementos);
                    break;

        }
    }






    return 0;
}
