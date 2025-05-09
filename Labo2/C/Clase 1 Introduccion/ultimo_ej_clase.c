#include <stdio.h>

int main() {
    int num, opcion;
    char continuar;

    do {
        // Solicitar al usuario que ingrese un número
        printf("Ingrese un número: ");
        scanf("%d", &num);

        // Mostrar el menú de opciones
        printf("\nElija una opción:\n");
        printf("1. Imprimir los números del 1 al número ingresado\n");
        printf("2. Calcular el cuadrado del número ingresado\n");
        printf("3. Verificar si el número ingresado es par o impar\n");
        printf("4. Salir del programa\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        // Ejecutar la opción seleccionada
        switch(opcion) {
            case 1:
                // Imprimir los números del 1 al número ingresado
                printf("Números del 1 al %d:\n", num);
                for (int i = 1; i <= num; i++) {
                    printf("%d ", i);
                }
                printf("\n");
                break;

            case 2:
                // Calcular el cuadrado del número ingresado
                printf("El cuadrado de %d es %d\n", num, num * num);
                break;

            case 3:
                // Verificar si el número ingresado es par o impar
                if (num % 2 == 0) {
                    printf("El número %d es par.\n", num);
                } else {
                    printf("El número %d es impar.\n", num);
                }
                break;

            case 4:
                // Salir del programa
                printf("Saliendo del programa...\n");
                return 0;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }

        // Preguntar si el usuario desea continuar
        printf("\n¿Desea continuar? (s para sí, cualquier otra tecla para salir): ");
        scanf(" %c", &continuar);  // El espacio antes de %c es para consumir el salto de línea pendiente

    } while (continuar == 's' || continuar == 'S');

    printf("Gracias por usar el programa. ¡Hasta luego!\n");
    return 0;
}