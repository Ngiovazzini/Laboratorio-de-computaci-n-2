#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct notebook{
    int codigo_maquina;
    char nombre_prestado[20];
    long int dni;
    char fecha_prestamo[12]; //25-06-2024
    char fecha_expiracion[12]; //30-06-2024
    float valor_asegurado;
};

void cargar_datos(struct notebook vector[],int *elementos,int *indice) {
    printf("Cargue los datos:\n");
  for(int i=0;i<(*elementos);i++) {
      *indice++;
      printf("Ingrese el codigo de la maquina %d \n",i+1);
      scanf("%d",&vector[i].codigo_maquina);
      while(getchar()!='\n');

      printf("Nombre de la persona a la que se le presto \n");
      fgets(vector[i].nombre_prestado,20,stdin);
      vector[i].nombre_prestado[strcspn(vector[i].nombre_prestado,"\n")] = '\0';

      printf("DNI \n");
      scanf("%li",&vector[i].dni);
      while(getchar()!='\n');

      printf("Fecha del prestamo\n");
      fgets(vector[i].fecha_prestamo,12,stdin);
      vector[i].fecha_prestamo[strcspn(vector[i].fecha_prestamo,"\n")] = '\0';

      printf("Fecha de expiracion\n");
      fgets(vector[i].fecha_expiracion,12,stdin);
      vector[i].fecha_expiracion[strcspn(vector[i].fecha_expiracion,"\n")] = '\0';

      printf("Valor asegurado\n");
      scanf("%f",&vector[i].valor_asegurado);
      while(getchar()!='\n');
  }
    *indice--;
}

void imprimir(struct notebook vector[],int *elementos) {
    for(int i=0;i<*elementos;i++){
        printf("---Indice: %d --- \n",i+1);
        printf("Codigo de la maquina: %d \n",vector[i].codigo_maquina);
        printf("Nombre de a quien se le presto: %s \n",vector[i].nombre_prestado);
        printf("DNI: %ld \n",vector[i].dni);
        printf("Fecha del prestamo: %s \n",vector[i].fecha_prestamo);
        printf("Fecha de expiracion: %s \n",vector[i].fecha_expiracion);
        printf("Valor asegurado: %f \n",vector[i].valor_asegurado);
        printf("\n");
    }
}

void modificar(struct notebook vector[],int *elementos) {
 long int modificar;
    printf("Ingrese el DNI de la persona a la cual quiere modificar la fecha de expiracion \n");
    scanf("%li",&modificar);
    while(getchar()!='\n');
    for(int i=0;i<(*elementos);i++) {
        if(modificar==vector[i].dni) {
            char nuevo [12];
            printf("ingrese la nueva fecha de expiracion:\n");
            fgets(nuevo,12,stdin);
            fflush(stdin);
            strcpy(vector[i].fecha_expiracion,nuevo);
        }
    }

}

void modificar_todo(struct notebook vector[],int *indice) {
    int new_codi=0;

    printf("Ingrese el codigo de maquina asi modifica todos los datos \n");
    scanf("%li",&new_codi);
    while(getchar()!='\n');

        if(new_codi==vector[*indice].codigo_maquina) {
            printf("Ingrese el nuevo nombre de la persona\n");
            fgets(vector[*indice].nombre_prestado,20,stdin);
            fflush(stdin);

            printf("El DNI nuevo \n");
            scanf("%li",&vector[*indice].dni);
            while(getchar()!='\n');

            printf("Nuevo Fecha del prestamo\n");
            fgets(vector[*indice].fecha_prestamo,12,stdin);
            fflush(stdin);

            printf("Nueva Fecha de expiracion\n");
            fgets(vector[*indice].fecha_expiracion,12,stdin);
            fflush(stdin);

            printf("Nuevo Valor asegurado\n");
            scanf("%f",&vector[*indice].valor_asegurado);
            while(getchar()!='\n');
        }

}

void borrar_indice(struct notebook vector[], int *elementos,int *indice) {
    int borrar;
    imprimir(vector,elementos);

    printf("indique el indice del usuario que desea borrar: \n");
    scanf("%i",&borrar);
    while(getchar()!='\n');

    for(int i=*indice;i<(*elementos-1);i++) {
        vector[i]=vector[i+1];
    }
    *elementos-=1;

}

void imprimir_txt(struct notebook vector[],FILE *p_Archivo,int *elementos) {

    for(int i=0;i<(*elementos);i++) {
        fprintf(p_Archivo,"%d\n%10s\n%li\n%10s\n%10s\n%.2f\n",
            vector[i].codigo_maquina,
            vector[i].nombre_prestado,
            vector[i].dni,
            vector[i].fecha_prestamo,
            vector[i].fecha_expiracion,
            vector[i].valor_asegurado);
    }
}

void imprimir_binario(struct notebook vector[],FILE *datos_archivo,int *elementos){

    datos_archivo=fopen("Datos.dat","wb");
    if(datos_archivo!=NULL){
        fwrite(vector,sizeof(struct notebook),*elementos,datos_archivo);
        fclose(datos_archivo);
        printf("Inventario guardado correctamente");
    }else{printf("No se puede abrir el archivo");}


}

void cargar_binario(struct notebook vector[],FILE *datos_archivo,int *elementos,int *indice){
    datos_archivo=fopen("Datos.dat","rb");

    if(datos_archivo!=NULL){

     /*   if(leidos!=elementos){
            int leidos=fread(datos_archivo,sizeof(struct notebook),*elementos,datos_archivo);
            printf("ERROR:No se leyeron los elementos");
            fclose(datos_archivo);
            return -1;
        }
    */
        fseek(datos_archivo,0,SEEK_END); //esto coloca el cursor en la ultima posicion del "vector"
        int num_notebooks=ftell(datos_archivo)/sizeof(struct notebook);/*ftell() te devuelve el valor en bytes del lugar donde
        el cursor del puntero en ese momento y eso dividido el tamaño en bytes del struct notebook te da la cantidad
        de notebook cargadas*/
        rewind(datos_archivo);//vuelve el posicionador al inicio

        vector=(struct notebook*)realloc(vector,num_notebooks*sizeof(struct notebook));
        fread(vector,sizeof(struct notebook),num_notebooks,datos_archivo);

        (*elementos)=num_notebooks;
        (*indice)=num_notebooks+1;
        printf("Inventario cargado correctamente");
    }else{printf("No se puede abrir el archivo");}

    fclose(datos_archivo);

}

int main(void) {
    int opcion=0, borrar,elementos,indice=0;
    struct notebook *vector; //puntero del tipo struct notebook
    char desicion;
    FILE *p_Archivo=NULL;
    FILE *datos_archivo;

    printf("Cuantas notebooks desea cargar? \n");
    scanf("%d",&elementos);
    while(getchar()!='\n');

    //aca asigno la direccion de memoria del bloque que me da molloc() al puntero tipo struct notebook
    vector=(struct notebook *)malloc(elementos*sizeof(struct notebook));
    if(vector==NULL) {
        printf("No Hay Espacio");
        return -1;
    }

    printf("Desea cargar datos desde el archivo?  S/N");
    desicion=getchar();
    while(getchar()!='\n');
    if(desicion=='s'){
        cargar_binario(vector,datos_archivo,&elementos,&indice);
    }else{cargar_datos(vector,&elementos,&indice);}





    while (opcion!=7){
        printf("Elija la opcion deseada\n");
        printf("1-Imprimir Elementos\n"
                        "2-Modificar Fecha de Expiracion mediante DNI\n"
                        "3-Modificar Todo\n"
                        "4-Borrar por indice\n"
                        "5-Imprimir en Archivo .TXT\n"
                        "6-Imprimir en Archivo .BIN\n"
                        "7-Salir\n"
                        );
        scanf("%d",&opcion);
        while(getchar()!='\n');

        switch (opcion) {
            case 1: imprimir(vector,&elementos);
                    break;

            case 2: modificar(vector,&elementos);
                    break;

            case 3: modificar_todo(vector,&indice);
                    break;
            case 4: borrar_indice(vector,&elementos,&indice);
                    break;

            case 5: p_Archivo=fopen("Entradas.txt","w");
                    if(p_Archivo==NULL) {
                        printf("no funciona el archivo");
                    }
                    imprimir_txt(vector,p_Archivo,&elementos);
                    fclose(p_Archivo);
                    break;

            case 6:imprimir_binario(vector,datos_archivo,&elementos);
                    break;

        }
    }

free(vector);




    return 0;
}
