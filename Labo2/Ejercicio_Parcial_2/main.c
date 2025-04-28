#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 struct articulo{
int codigo_producto;
char nombre[50];
float precio;
int cantidad_disponible;
int cantidad_vendida;
};

void cargar_datos(struct articulo vector[], int *elementos_vector){
    char opcion;
    do {
        printf("Siga las instruciones para cargar los datos\n");

        printf("Ingrese el codigo del producto: \n");
        scanf("%d",&vector[*elementos_vector].codigo_producto);
        while(getchar()!='\n');

        printf("Ingrese el nombre del producto: \n");
        fgets(vector[*elementos_vector].nombre,50,stdin);
        vector[*elementos_vector].nombre[strcspn(vector[*elementos_vector].nombre,"\n")] = '\0';

        printf("Ingrese el precio: \n");
        scanf("%f",&vector[*elementos_vector].precio);
        while(getchar()!='\n');

        printf("Ingrese la cantidad disponible: \n");
        scanf("%d",&vector[*elementos_vector].cantidad_disponible);
        while(getchar()!='\n');

        printf("Ingrese la cantidad vendida: \n");
        scanf("%d",&vector[*elementos_vector].cantidad_vendida);
        while(getchar()!='\n');

        (*elementos_vector)++;

        vector=realloc(vector,(*elementos_vector)*sizeof(struct articulo));
        printf("Desea cargar mas datos? S/N \n");
        scanf(("%c"),&opcion);
        while(getchar()!='\n');

    }while(opcion!='n' && opcion!='N');



}


int main(void) {
char desicion;
int opcion=0,elementos_vector=0;
struct articulo *vector;

 vector=(struct articulo *)malloc(sizeof(struct articulo));

    if(vector!=NULL){
        printf("Desea cargar los datos desde un archivo .dat? S/N\n");
        scanf("%c",&desicion);
        while(getchar()!='\n');
            if (desicion=='s') {
                cargar_datos_dat();
            }else{cargar_datos(vector,&elementos_vector);}
    }else {
        printf("NO SE PUEDE RESERVAR MEMORIA");
        return -1;
    }
    do {
        printf("Elija una opcion:\n");
        printf("1-Imprimir elementos\n"
                     "2-Modificar mediante codigo de producto\n"
                     "3-Solicitar venta\n"
                     "4-Total recaudado\n"
                     "5-Borrar elemento\n"
                     "6-Imprimir en archivo .TXT\n"
                     "7-Imprimir en archivo .dat\n"
                     "8-Cargar desde archivo .dat"
                     "9-Salir\n");
        scanf("%d",&opcion);
        while(getchar()!='\n');

    switch (opcion) {
        case 1:
                break;
        case 2:
                break;
        case 3:
                break;
        case 4:
                break;
        case 5:
                break;
        case 6:
                break;
        case 7:
                break;
        case 8:
                break;
    }
 }while (opcion!=9);

    
    



return 0;
}
