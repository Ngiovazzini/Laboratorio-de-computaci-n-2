#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cohete {
int id_cohete;
char nombre[50];
float capacidad_carga;
int numero_lanzamientos;
int misiones_completadas;
};

void ingresar_datos(struct cohete **vector,int *elemntos_vec){
   char desicion;
do{
    printf("-----Ingrese los datos-----\n");
    printf("Ingrese id del cohete: \n");
    scanf("%d",&(*vector)[*elemntos_vec].id_cohete);
    while (getchar() != '\n');

    printf("Ingrese el Nombre: \n");
    fgets((*vector)[*elemntos_vec].nombre,50,stdin);
    (*vector)[*elemntos_vec].nombre[strcspn((*vector)[*elemntos_vec].nombre, "\n")] = '\0';


    printf("Ingrese capacidad de carga: \n");
    scanf("%f",&(*vector)[*elemntos_vec].capacidad_carga);
    while (getchar() != '\n');

    printf("Ingrese numero de lanzamientos: \n");
    scanf("%d",&(*vector)[*elemntos_vec].numero_lanzamientos);
    while (getchar() != '\n');

    printf("Ingrese misiones completadas: \n");
    scanf("%d",&(*vector)[*elemntos_vec].misiones_completadas);
    while (getchar() != '\n');

    printf("\n");

    if(*vector==NULL){
        printf("ERROR al reasignar");
    }

    (*elemntos_vec)++;
    *vector=(struct cohete *)realloc(*vector,(*elemntos_vec)*sizeof(struct cohete));

    printf("Desea cargar otro elemento S/N \n");
    scanf("%c",&desicion);
    while (getchar() != '\n');

    }while(desicion!='n'&& desicion!='N');




}

void imprimir(struct cohete vector[],int *elementos_vec){

    for(int i=0;i<(*elementos_vec);i++){
        printf("-----INDICE %d-----\n",i);
        printf("\n");
        printf("El id del cohete es: %d \n",vector[i].id_cohete);
        printf("E nombre del cohete es: %s \n",vector[i].nombre);
        printf("La capacidad de carga es: %f \n",vector[i].capacidad_carga);
        printf("El numero de lanzamientos es: %d \n",vector[i].numero_lanzamientos);
        printf("Las misiones completadas son: %d \n",vector[i].misiones_completadas);
    }




}

void exportar_dat(struct cohete **vector, int *elementos_vec){
    FILE *archivo_dat;

    archivo_dat=fopen("Cohetes.dat","wb");

    if(archivo_dat==NULL){
        printf("ERROR al exportar");
    }
    fwrite(*vector,(*elementos_vec),sizeof(struct cohete),archivo_dat);
    fclose(archivo_dat);

}

void cargar_dat(struct cohete **vector,int *elementos_vec){
    int leidos=0;

    FILE *archivo_dat;
    archivo_dat=fopen("Cohetes.dat","rb");

    fseek(archivo_dat,(*elementos_vec),SEEK_END);
    (*elementos_vec)=ftell(archivo_dat)/sizeof(struct cohete);
    rewind(archivo_dat);


    *vector=(struct cohete *)realloc(*vector,(*elementos_vec)*sizeof(struct cohete));

    fread(*vector,sizeof(struct cohete),(*elementos_vec),archivo_dat);

fclose(archivo_dat);
}

int main(void){

    struct cohete *vector;
    int opcion=0,elementos_vec=0;
    char si_no;
    vector=(struct cohete *)malloc(sizeof(struct cohete));

    if(vector==NULL){
        printf("ERROR AL ASIGNAR MEMORIA");
        return -1;
    }
        printf("Desea cargr desde un archivo .dat?  S/N \n");
        scanf("%s",&si_no);
        while (getchar() != '\n');

        if(si_no=='S'||si_no=='s'){
            cargar_dat(&vector,&elementos_vec);
        }else{ingresar_datos(&vector,&elementos_vec);}

    do{
        printf("-----MENU-----\n");
        printf("\n");
        printf("1-Imprimir elementos \n");
        printf("2-Modificar datos mediante nombre\n");
        printf("3-Habilitar despegue\n");
        printf("4-Total de misiones completadas\n");
        printf("5-Eliminar por posicion\n");
        printf("6-Exportar a archivo reporte.txt\n");
        printf("7-Exportar  a archivo cohetes.dat\n");
        printf("8-Cargar desde archivo.dat\n");
        printf("9-Salir\n");

        scanf("%d",&opcion);
        while (getchar() != '\n');

        switch(opcion){
            case 1: imprimir(vector,&elementos_vec);
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

            case 7: exportar_dat(&vector,&elementos_vec);
                    break;


            case 8:
                    break;


        }




    }while(opcion!=9);




return 0;
}
