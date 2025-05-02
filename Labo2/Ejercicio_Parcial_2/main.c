#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct articulo {
    int codigo_producto;
    char nombre[50];
    float precio;
    int cantidad_disponible;
    int cantidad_vendida;
};

void imprimir(struct articulo vector[], int elementos_vector) {
    for (int i = 0; i < elementos_vector; i++) {
        printf("---- INDICE %d ----\n", i + 1);
        printf("Codigo producto: %d\n", vector[i].codigo_producto);
        printf("Nombre: %s\n", vector[i].nombre);
        printf("Precio: %.2f\n", vector[i].precio);
        printf("Cantidad disponible: %d\n", vector[i].cantidad_disponible);
        printf("Cantidad vendida: %d\n", vector[i].cantidad_vendida);
        printf("\n");
    }
}

void txt(struct articulo vector[], int elementos_vector) {
    FILE *ptr_txt = fopen("Archivo_texto.txt", "w");
    if (ptr_txt != NULL) {
        for (int i = 0; i < elementos_vector; i++) {
            fprintf(ptr_txt, "%d\n%s\n%.2f\n%d\n%d\n",
                    vector[i].codigo_producto,
                    vector[i].nombre,
                    vector[i].precio,
                    vector[i].cantidad_disponible,
                    vector[i].cantidad_vendida);
        }
        fclose(ptr_txt);
    } else {
        printf("ERROR al abrir el archivo de texto.\n");
    }
}

void cargar_datos(struct articulo **vector, int *elementos_vector) {
    char opcion;
    do {
        printf("\n--- CARGA DE DATOS ---\n");

        printf("Ingrese el codigo del producto: ");
        scanf("%d", &(*vector)[*elementos_vector].codigo_producto);
        while (getchar() != '\n');

        printf("Ingrese el nombre del producto: ");
        fgets((*vector)[*elementos_vector].nombre, 50, stdin);
        (*vector)[*elementos_vector].nombre[strcspn((*vector)[*elementos_vector].nombre, "\n")] = '\0';

        printf("Ingrese el precio: ");
        scanf("%f", &(*vector)[*elementos_vector].precio);
        while (getchar() != '\n');

        printf("Ingrese la cantidad disponible: ");
        scanf("%d", &(*vector)[*elementos_vector].cantidad_disponible);
        while (getchar() != '\n');

        printf("Ingrese la cantidad vendida: ");
        scanf("%d", &(*vector)[*elementos_vector].cantidad_vendida);
        while (getchar() != '\n');

        (*elementos_vector)++;

        *vector = realloc(*vector, (*elementos_vector) * sizeof(struct articulo));
        if (*vector == NULL) {
            printf("ERROR al reservar memoria\n");
            exit(EXIT_FAILURE);
        }

        printf("\nDesea cargar mas datos? S/N: ");
        scanf("%c", &opcion);
        while (getchar() != '\n');

    } while (opcion != 'n' && opcion != 'N');
}

void imprimir_datos_dat(struct articulo *vector, int elementos_vector) {
    FILE *ptr_dat = fopen("Datos_bin.dat", "wb");
    if (!ptr_dat) {
        printf("ERROR al abrir archivo binario para escritura.\n");
        return;
    }
    fwrite(vector, sizeof(struct articulo), elementos_vector, ptr_dat);
    fclose(ptr_dat);
    printf("Los elementos se escribieron correctamente en Datos_bin.dat\n");
}

void cargar_datos_dat(struct articulo **vector, int *elementos_vector) {
    FILE *ptr_dat = fopen("Datos_bin.dat", "rb");
    if (!ptr_dat) {
        printf("No se pudo abrir Datos_bin.dat\n");
        return;
    }
    fseek(ptr_dat, 0, SEEK_END);
    long size = ftell(ptr_dat);
    rewind(ptr_dat);

    *elementos_vector = size / sizeof(struct articulo);
    *vector = realloc(*vector, (*elementos_vector) * sizeof(struct articulo));
    if (*vector == NULL) {
        printf("ERROR al reservar memoria\n");
        fclose(ptr_dat);
        exit(EXIT_FAILURE);
    }

    fread(*vector, sizeof(struct articulo), *elementos_vector, ptr_dat);
    fclose(ptr_dat);
}

int main(void) {
    struct articulo *vector = malloc(sizeof(struct articulo));
    int elementos_vector = 0;
    char decision;
    int opcion = 0;

    if (!vector) {
        printf("NO SE PUDO RESERVAR MEMORIA\n");
        return EXIT_FAILURE;
    }

    printf("Desea cargar los datos desde un archivo .dat? S/N: ");
    scanf("%c", &decision);
    while (getchar() != '\n');

    if (decision == 's' || decision == 'S') {
        cargar_datos_dat(&vector, &elementos_vector);
    } else {
        cargar_datos(&vector, &elementos_vector);
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Imprimir elementos\n");
        printf("2 - Modificar producto\n");
        printf("3 - Solicitar venta\n");
        printf("4 - Total recaudado\n");
        printf("5 - Borrar elemento\n");
        printf("6 - Exportar a archivo TXT\n");
        printf("7 - Guardar en archivo .dat\n");
        printf("8 - Cargar desde archivo .dat\n");
        printf("9 - Salir\n");
        printf("Ingrese opcion: ");

        scanf("%d", &opcion);
        while (getchar() != '\n');

        switch (opcion) {
            case 1:
                imprimir(vector, elementos_vector);
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
                txt(vector, elementos_vector);
                break;
            case 7:
                imprimir_datos_dat(vector, elementos_vector);
                break;
            case 8:
                cargar_datos_dat(&vector, &elementos_vector);
                break;
            case 9:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no implementada o invalida.\n");
        }
    } while (opcion != 9);

    free(vector);
    return 0;
}
