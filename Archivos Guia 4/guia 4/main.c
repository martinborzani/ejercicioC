#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char apellidoynombre[30];
    char seccion[6];
    char categoria[3];

}Empleado;

typedef struct{

    char codigo[6];
    char descripcion[30];

}Seccion;

typedef struct{
    char codigo[3];
    float sueldo;

}Categoria;

void cargarArchivoEmpleado();
void cargarArchivoSeccion();
void cargarArchivoCategoria();
void cargarTabla(Seccion secciones[],int *n);
int obtenerIndice(Seccion secciones[],char codigo[]);
void cantidadEmpleados(Seccion secciones[],Empleado empleados,int n);
int sumaTotalSueldo(Categoria categorias);



int main()
{
    Empleado empleados;
    Seccion secciones[10];
    Categoria categorias;
    int n;
    float suma;


    //cargarArchivo();
    //cargarArchivoSeccion();
    //cargarArchivoCategoria();
    cargarTabla(secciones,&n);
    cantidadEmpleados(secciones,empleados,n);
    suma = sumaTotalSueldo(categorias);
    printf("El sueldo de todos los empleados de la empresa es de: %.1f",suma);

    return 0;
}

int sumaTotalSueldo(Categoria categorias){
    int suma;

    FILE *archCate;
    suma = 0;
    archCate = fopen("categoria.dat","rb");
    if(archCate != NULL){
        fread(&categorias,sizeof(Categoria),1,archCate);
        while(!feof(archCate)){
            suma = suma + categorias.sueldo;
            fread(&categorias,sizeof(Categoria),1,archCate);
        }

        fclose(archCate);
    }else{
        printf("El Archivo no existe \n");
     }

     return suma;
}


void cantidadEmpleados(Seccion secciones[],Empleado empleados,int n){

    int pos,i;
    int cantEmpleados[15] ={0};
    FILE *archA;

    archA = fopen("empleados.dat","rb");
    if(archA != NULL){
        fread(&empleados,sizeof(Empleado),1,archA);
        while(!feof(archA)){
            pos = obtenerIndice(secciones,empleados.seccion);
            cantEmpleados[pos]++;
            fread(&empleados,sizeof(Empleado),1,archA);
        }

        fclose(archA);
    }else{
        printf("El archivo no existe \n");
    }


    for(i = 0; i < n; i++){
        printf("%s %d \n",secciones[i].descripcion,cantEmpleados[i]);
    }

}


int obtenerIndice(Seccion secciones[],char codigo[]){

    int i=0;
    while(strcmp(codigo,secciones[i].codigo)){
        i++;
    }
    return i;
}

void cargarTabla(Seccion secciones[],int *n){

    FILE *archB;
    archB = fopen("secciones.dat","rb");
    if(archB != NULL){
        *n = 0;
        fread(&secciones[*n],sizeof(Seccion),1,archB);
        while(!feof(archB)){
            (*n)++;
            fread(&secciones[*n],sizeof(Seccion),1,archB);
        }
        fclose(archB);
    }else{
        printf("el archivo no tiene datos");
    }

}



void cargarArchivoEmpleado(){

    Empleado empleado;
    FILE *archB,*archT;

    archB = fopen("empleados.dat","wb");
    archT = fopen("empleados.txt","r");

    while(fscanf(archT,"%s %s %s",empleado.apellidoynombre,empleado.seccion,empleado.categoria) == 3){
        fwrite(&empleado,sizeof(empleado),1,archB);
    }

    fclose(archB);
    fclose(archT);

}

void cargarArchivoSeccion(){

    Seccion secciones;
    FILE *archB,*archT;

    archB = fopen("secciones.dat","wb");
    archT = fopen("secciones.txt","r");

    while(fscanf(archT,"%s %s",secciones.codigo,secciones.descripcion) == 2){
        fwrite(&secciones,sizeof(secciones),1,archB);
    }

    fclose(archB);
    fclose(archT);

}


void cargarArchivoCategoria(){

    Categoria categorias;
    FILE *archB,*archT;

    archB = fopen("categoria.dat","wb");
    archT = fopen("categoria.txt","r");

    while(fscanf(archT,"%s %f",categorias.codigo,&categorias.sueldo) == 2){
        fwrite(&categorias,sizeof(categorias),1,archB);
    }

    fclose(archB);
    fclose(archT);

}
