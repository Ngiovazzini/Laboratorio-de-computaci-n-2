#include <stdio.h>

    void ingresar_elementos(int vector[]){
    printf("ingrese los elementos uno por uno\n");
        for(int i=0;i<10;i++){
        scanf("%d",&vector[i]);
        }
    }

    void imprimir(int vector[]) {
        for(int i=0;vector[i]!=0;i++) {
            printf("%d  \n",vector[i]);
        }
    }

    int suma_elementos(int vector[]) {
        int acum=0;
        for(int i=0;vector[i]!=0;i++){
            acum=acum+vector[i];
        }
        return acum;
    }

    int max(int vector[],int *maximo) {

        for(int i=0;vector[i]!=0;i++) {
            if(*maximo<vector[i]) {
                *maximo=vector[i];
            }
        }
        return *maximo;
    }

    int min(int vector[]) {
        int minimo=vector[0];
        for(int i=0;vector[i]!=0;i++) {
                if(vector[i]<minimo) {
                    minimo=vector[i];
                }
            }

        return minimo;
    }


int main(void){

 int vector[10]={1,2,3,4,5,6,7,8,9,10}, opcion=0,maximo;
 float promedio;


    do
        {

        printf("\n Elegir la opción deseada; \n"
            "1: Ingresar elementos del vector\n"
            "2: Imprimir elemntos del vector\n"
            "3: Calcular la suma de los elementos del  vector\n"
            "4: Encontrar el maximo del vector\n"
            "5: Encontrar el minimo del vector\n"
            "6: Calcular el promedio de los elementos del vector \n"
            "7: Salir\n");
        scanf("%d",&opcion);
    switch(opcion){

        case 1: ingresar_elementos(vector);
                break;
        case 2: imprimir(vector);
                break;
        case 3: printf("La suma de todos los elemntos es \n %d",suma_elementos(vector));
                break;
        case 4: printf("El maximo elemento es: \n %d",max(vector,&maximo));
                break;
        case 5: printf("El minimo elemento es: \n %d",min(vector));

        case 6: promedio=suma_elementos(vector)/10;
                printf("El promedio de la suma de todos los elementos es: \n %f",promedio);
                break;
    }
}while (opcion!=7);








return 0;
}
