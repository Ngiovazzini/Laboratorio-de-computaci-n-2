#include <stdio.h>
#include <string.h>
struct ciudad{

    char nombre[50];
    int poblacion;
    char pais[50];
};



void cargar_datos(struct ciudad ciudades[], int cantidad,int *acum ){
        char nombre[50];
        int poblacion;
        char pais[50];

    for(int i=0;i<cantidad;i++){

        *acum=i+1;

        printf("Ingrese el nombre:\n");
        fgets(nombre,50,stdin);
        nombre[strcspn(nombre,"\n")] = '\0';

        printf("Ingrese el poblacion:\n");
        scanf("%d",&poblacion);
        while(getchar()!='\n');

        printf("Ingrese el pais:\n");
        fgets(pais,50,stdin);
        pais[strcspn(pais,"\n")] = '\0';

        strcpy(ciudades[i].nombre,nombre);
        ciudades[i].poblacion=poblacion;
        strcpy(ciudades[i].pais,pais);
        }

}

void imprimir(struct  ciudad ciudades[],int cantidad){
    for(int i=0;i<cantidad;i++){
        printf("Nombre: %s \n",ciudades[i].nombre);
        printf("Poblacion: %d \n",ciudades[i].poblacion);
        printf("Pais: %s \n",ciudades[i].pais);
    }
}

void agregar(struct ciudad ciudades[],int *acum){

        char nombre[50];
        int poblacion;
        char pais[50];

        printf("Ingrese el nombre:\n");
        fgets(nombre,50,stdin);
        nombre[strcspn(nombre,"\n")] = '\0';

        printf("Ingrese el poblacion:\n");
        scanf("%d",&poblacion);
        while(getchar()!='\n');

        printf("Ingrese el pais:\n");
        fgets(pais,50,stdin);
        pais[strcspn(pais,"\n")] = '\0';

        strcpy(ciudades[*acum].nombre,nombre);
        ciudades[*acum].poblacion=poblacion;
        strcpy(ciudades[*acum].pais,pais);

        (*acum)++;

}

void quitar(struct ciudad ciudades[], char quitarPersona[], int *acum) {
            for(int i=0;i<*acum;i++) {
                if(strcmp(quitarPersona,ciudades[i].nombre)==0) {
                    strcpy(ciudades[i].nombre,ciudades[i+1].nombre);
                    ciudades[i].poblacion=ciudades[i+1].poblacion;
                    strcpy(ciudades[i].pais,ciudades[i+1].pais);
                }
            }
            (*acum)--;
}

int main(){

    struct ciudad ciudades[10];
    int cantidad=0,opcion=0,acum=0;
    char quitarPersona[50];


    while(opcion!=5){


        printf("Elija una opcion:\n ");
        printf(
                "1. Cargar Datos.\n"
                "2. Imprimir Datos.\n"
                "3. Agregar Ciudad.\n"
                "4. Quitar Ciudad por Nombre.\n"
                "5. Salir.\n"
                );
        scanf("%d",&opcion);
        while(getchar()!='\n');

        switch(opcion){

            case 1: printf("Ingrese la cantidad de ciudades que quiere cargar:\n");
                    scanf("%d",&cantidad);
                    while(getchar()!='\n');
                    cargar_datos(ciudades,cantidad,&acum);
                    break;

            case 2: imprimir(ciudades,cantidad);
                    break;

            case 3: printf("Agregar ciudad \n");
                    agregar(ciudades,&acum);
                    cantidad=acum;
                    break;
            case 4: printf("Escriba el nombre de la ciudad que desea quitar:\n");
                    fgets(quitarPersona,50,stdin);
                    quitarPersona[strcspn(quitarPersona,"\n")] = '\0';
                    quitar(ciudades,quitarPersona,&acum);
        }
  }

return 0;
}
