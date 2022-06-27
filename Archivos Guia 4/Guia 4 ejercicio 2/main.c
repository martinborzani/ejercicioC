#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char ApellidoYNombre[30];
    int edad;
    char CodigoDeporte[10];

} Deportistas;

typedef struct{

    char CodigoDeporte[10];
    char descripcion[20];

}Deportes;

void cargarDeportistas();
void cargarDeportes();
float promDeportistas(Deportistas deportistas,int sumEdad[]);
int obtenerPos(char codigo[],Deportes deportes[]);
void cargarTabla(Deportes deportes[],int *i);
void cantidadDeportistas(Deportistas deportistas,Deportes deportes[],int contadorDeportistas[],int n);
int sumaTotalDeportistas(int contadoDeportistas[],int n);

int main()
{
    Deportistas deportista;
    Deportes deportes[10];
    int sumEdad[20];
    float PromEdad;
    int contadorDeportistas[15] = {0};
    int sumaTotalDepor,i;

    PromEdad = promDeportistas(deportista,sumEdad);
    printf("La edad promedio de los deportistas es de: %.1f",PromEdad);
    cargarTabla(deportes,&i);
    cantidadDeportistas(deportista,deportes,contadorDeportistas,i);
    sumaTotalDepor = sumaTotalDeportistas(contadorDeportistas,i);
    printf("TOTAL = %d ", sumaTotalDepor);

    //cargarDeportistas();
    //cargarDeportes();


    return 0;
}

int sumaTotalDeportistas(int contadoDeportistas[],int n){

    int suma = 0;
    int i;

    for(i = 0; i < n; i++){
        suma += contadoDeportistas[i];
    }

    return suma;

}


void cantidadDeportistas(Deportistas deportistas,Deportes deportes[],int contadorDeportistas[],int n){

    int i,pos;
    FILE *archB;

    archB = fopen("deportistasB.dat","rb");
    if(archB != NULL){
        fread(&deportistas,sizeof(Deportistas),1,archB);
        while(!feof(archB)){
            pos = obtenerPos(deportistas.CodigoDeporte,deportes);
            contadorDeportistas[pos]++;
            fread(&deportistas,sizeof(Deportistas),1,archB);
        }

        fclose(archB);
    }else{
        printf("el archivo no existe \n");
    }
    printf("\n");
    for(i = 0; i < n; i++){
        printf("%s %d \n",deportes[i].descripcion,contadorDeportistas[i]);
    }

}


int obtenerPos(char codigo[],Deportes deportes[]){

    int i = 0;
    while(strcmp(deportes[i].CodigoDeporte,codigo)){
        i++;
    }

    return i;

}


float promDeportistas(Deportistas deportistas,int sumEdad[]){
    float PromEdad;
    int edad,i,n;
    FILE *archB;

    archB = fopen("deportistasB.dat","rb");
    if(archB != NULL){
        n = 0;
        PromEdad = 0;
        fread(&deportistas,sizeof(Deportistas),1,archB);
        while(!feof(archB)){
            sumEdad[n] = deportistas.edad;
            n++;
            fread(&deportistas,sizeof(Deportistas),1,archB);
        }

        fclose(archB);
        edad = 0;
        for(i = 0; i < n; i++){
            edad += sumEdad[i];
        }

        PromEdad = (float)edad/n;

    }else{

        printf("El archivo no existe papa \n");
    }

    return PromEdad;

}

void cargarTabla(Deportes deportes[],int *i){

    FILE *archB;
    archB = fopen("deportesB.dat","rb");
    if(archB != NULL){
        *i = 0;
        fread(&deportes[*i],sizeof(Deportes),1,archB);
        while(!feof(archB)){
            (*i)++;
            fread(&deportes[*i],sizeof(Deportes),1,archB);
        }

        fclose(archB);
    }else{
        printf("el archivo no existe \n");
    }

}

void cargarDeportes(){

    Deportes deportes;

    FILE *archT;
    FILE *archB;

    archT = fopen("deportes.txt","r");
    archB = fopen("deportesB.dat","wb");

    while(fscanf(archT,"%s %s",deportes.CodigoDeporte,deportes.descripcion) == 2){
        fwrite(&deportes,sizeof(Deportes),1,archB);
    }

    fclose(archB);
    fclose(archT);

}



void cargarDeportistas(){

    Deportistas deportistas;
    FILE *archT;
    FILE *archB;

    archT = fopen("deportistas.txt","r");
    archB = fopen("deportistasB.dat","wb");

    while(fscanf(archT,"%s %d %s",deportistas.ApellidoYNombre,&deportistas.edad,deportistas.CodigoDeporte) == 3){
        fwrite(&deportistas,sizeof(Deportistas),1,archB);
    }

    fclose(archB);
    fclose(archT);

}
