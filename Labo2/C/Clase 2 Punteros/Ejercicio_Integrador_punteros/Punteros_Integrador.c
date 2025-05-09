
 #include <stdio.h>
 /*escribir un programa en C que solicite al usuario ingresar la cantidad de numeros
 que desea procesar. Luego, elprograma debe soicitar al usuario que ingrese esos numeros
 uno por uno. Utilizando punteros, el programa debe calcular y mostrar la suma y el producto
 de los numeros ingresados.

    Elprograma debe cumplir con los siguientes requisitos.

    Debe utilizar punteros para acceder a los numeros ingresados.
    Debe utilizar funciones Scanf y Printf para interactuar con el usuario.
    Debe utilizar un ciclo para procesar los numeros ingresados.
    No esta permitido usar vectores para almacenar los numeros ingresados.
    */

    int main(void){

    float *n;
    int cant_numeros=0;
    float acum=0;
    float acum_multi=1;
    float numero=0;
    float suma=0;
    float multi=0;
    n=&numero;
    printf("Ingrese la cantidad de numeros que desea procesar: \n");
    scanf("%d",&cant_numeros);

    for(int i=1;i<=cant_numeros;i++){


        printf("ingresaar numero: \n");
        scanf("%f",&n);

        acum=acum+*n;
        acum_multi=acum_multi*(*n);

        }

        printf("Suma: %f\n",acum);
        printf("Multi: %f\n",acum_multi);





    }
