#include <stdio.h>
#include <stdlib.h>
//Prueba para GhitHub
void ingresar(int elementos,int ptr_dinamico[]) {
    for(int i=0;i<elementos;i++) {
        printf("Ingrese elemento: \n");
        scanf("%d",ptr_dinamico[i]);
        while(getchar()!='\n');
    }
}

void suma_promedio(int ptr_dinamico[],int *suma,float *promedio,int elementos) {
    *suma=0;
    *promedio=0;
    for(int i=0;i<elementos;i++) {
        *suma=ptr_dinamico[i]+(*suma);
        *promedio=*suma/i+1;
    }

}

int main(void) {
    int elementos=0,suma=0;
    float promedio=0;
    int *ptr_dinamico=NULL;
    printf("Determina el la cantidad de elementos:\n");
    scanf("%d",&elementos);
    while(getchar()!='\n');

    ptr_dinamico=(int*)malloc(elementos*sizeof(int));
    if(ptr_dinamico==NULL) {
      printf("ERROR");
    }
    ingresar(elementos,ptr_dinamico);
    suma_promedio(ptr_dinamico,&suma,&promedio,elementos);
    printf("La suma de los elementos es; %d \n",suma);
    printf("El promedio de los elemntos es: %.2f \n",promedio);
    return 0;
}
