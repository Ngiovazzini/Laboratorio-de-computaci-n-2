#include <stdio.h>
    #define PI 3.14159
    void area_perimetro(float base,float altura,float *a, float *p){

         *a=base*altura;
         *p=2*(base+altura);


    }

int main (void){

    float base;
    float altura;
    float perimetro;
    float area;
    int opcion;
    float radio;
    float *a;
    float *p;
        a=&area;
        p=&perimetro;
    printf("Seleccione una opción :\n1 Calcular área y perimetro de un cuadrado.\n2 Calcular área y perimetro de un rectangulo.\n3 Calcular área y perimetro de un circulo.\n4 Salir.\n");
    scanf("%d",&opcion);
    do{
        switch(opcion){

        case 1: printf("Digite base:\n");
                scanf("%f",&base);
                printf("Digite altura \n");
                scanf("%f",&altura);
                area_perimetro(base,altura,a,p);
                printf("%f,%f",perimetro,area);
                break;

        case 2: printf("Digite base:\n");
                scanf("%f",&base);
                printf("Digite altura \n");
                scanf("%f",&altura);
                break;

        case 3: printf("Digite radio del circulo:\n");
                scanf("%f",&radio);
                break;

        case 4:
                break;

                    }

    }while(opcion!=4);








return 0;
}
