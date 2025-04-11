/*Escribir un programa que solicite al usuario dos n´umeros enteros
y luego intercambie los valores de las variables utilizando punteros.*/



#include <stdio.h>

int main(void){

    int numero_A=0;
    int numero_B=0;
    int *p_A;
    int *p_B;
    int aux;
    printf("ingrese el primer numero entero : \n");
    scanf("%d",&numero_A);

    printf("ingrese el segundo numero entero : \n");
    scanf("%d",&numero_B);

    p_A=&numero_A;
    p_B=&numero_B;
    printf("%u\n",p_A);
    printf("%u\n",p_B);
    aux=*p_A;
    *p_A=*p_B;
    *p_B=aux;

    printf("%d\n%d\n",numero_A,numero_B);






}
