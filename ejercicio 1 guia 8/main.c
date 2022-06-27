#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{

    char nombre[20];
    int cantMujeres;
    int cantHombres;
    struct nodo *sig;

}NODO;

typedef NODO *TLISTA;


void inicializar(TLISTA *lista);
void cargarLista(TLISTA *lista);
void porcentajeHombres(TLISTA lista);
void mayorPoblacion(TLISTA lista);
void mostrarLista(TLISTA lista);

int main()
{
    TLISTA lista;
    inicializar(&lista);
    cargarLista(&lista);
    porcentajeHombres(lista);
    mayorPoblacion(lista);

    return 0;
}


void porcentajeHombres(TLISTA lista){

    int contMayorPorcentaje;
    contMayorPorcentaje = 0;
    while(lista != NULL){

        if(lista->cantHombres > lista->cantMujeres){
            contMayorPorcentaje++;
        }
        lista = lista->sig;
    }
    printf("Cantidad de ciudades con mayor porcentaje de hombres: %d\n",contMayorPorcentaje);
}

void mayorPoblacion(TLISTA lista){

    int cantMax,suma;
    char ciudadMax[20];
    cantMax = -1;
    while(lista != NULL){
        suma = 0;
        suma += lista->cantHombres + lista->cantMujeres;
        if(suma > cantMax){
            cantMax = suma;
            strcpy(ciudadMax,lista->nombre);
        }
        lista = lista->sig;
    }

    printf("la ciudad con mayor poblacion es: %s\n",ciudadMax);
}

void inicializar(TLISTA *lista){

    *lista = NULL;

}

void cargarLista(TLISTA *lista){

    TLISTA nuevo,ant;
    nuevo = (TLISTA)malloc(sizeof(NODO));
    nuevo->sig = NULL;
    printf("ingrese ciudad, cantidad de mujeres y cantidad de hombre\n");
    while(scanf("%s %d %d",nuevo->nombre,&nuevo->cantMujeres,&nuevo->cantHombres) == 3){
        if(*lista == NULL){
            *lista = nuevo;
             ant = nuevo;
        }else{
            ant->sig = nuevo;
            ant = nuevo;
        }
        nuevo = (TLISTA)malloc(sizeof(NODO));
        nuevo->sig = NULL;
        printf("ingrese ciudad, cantidad de mujeres y cantidad de hombre\n");
    }

    free(nuevo);
}

void mostrarLista(TLISTA lista){

    while(lista != NULL){
        printf("%s %d %d\n",lista->nombre,lista->cantMujeres,lista->cantHombres);
        lista = lista->sig;
    }

}
