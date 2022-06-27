#include <stdio.h>
#include <stdlib.h>
#include "tdacola.h"
#include "tdapila.h"

typedef struct nodo{

    TCOLA cola;
    struct nodo *sig;

}NODO;

typedef NODO *TLISTA;

void inicializar(TLISTA *lista);
void cargarLista(TLISTA *lista);
void mostrarLista(TLISTA lista);

int main()
{
    TLISTA lista,aux;
    TCOLA auxCola;
    TPILA pila;
    int elementoMayor;
    TELEMENTOC celem;
    TELEMENTOP pelem;
    inicializar(&lista);
    iniciac(&auxCola);
    iniciap(&pila);
    cargarLista(&lista);

    aux = lista;
    while(aux != NULL){
        consultac(aux->cola,&celem);
        elementoMayor = celem;
        while(!vaciac(aux->cola)){
            sacac(&aux->cola,&celem);
            if(elementoMayor < celem){
                elementoMayor = celem;
            }
            ponec(&auxCola,celem);
        }

        pelem = elementoMayor;
        ponep(&pila,pelem);

        while(!vaciac(auxCola)){
            sacac(&auxCola,&celem);
            ponec(&aux->cola,celem);
        }

        aux = aux->sig;

    }

    while(!vaciap(pila)){
        sacap(&pila,&pelem);
        printf("%d\n",pelem);
    }

    return 0;
}


void inicializar(TLISTA *lista){
    *lista = NULL;
}

void cargarLista(TLISTA *lista){
    TLISTA nuevo,ult;
    char pregunta;
    TELEMENTOC celem;
    nuevo = (TLISTA)malloc(sizeof(NODO));
    nuevo->sig = NULL;
    printf("ingrese s para ingresar nuevos nodos o n para salir\n");
    scanf("%c",&pregunta);
    while(pregunta != 'n'){
        fflush(stdin);
        iniciac(&nuevo->cola);
        if(*lista == NULL){
            *lista = nuevo;
            ult = *lista;
            printf("ingrese los numeros de la cola\n");
            while(scanf("%d",&celem) == 1){
                ponec(&nuevo->cola,celem);
                printf("ingrese los numeros de la cola\n");
            }

        }else{
            ult->sig = nuevo;
            ult = nuevo;
            printf("ingrese los numeros de la cola\n");
            while(scanf("%d",&celem) == 1){
                ponec(&nuevo->cola,celem);
                printf("ingrese los numeros de la cola\n");
            }
        }

        nuevo = (TLISTA)malloc(sizeof(NODO));
        nuevo->sig = NULL;
        printf("ingrese s para ingresar nuevos nodos o n para salir\n");
        scanf("%c",&pregunta);

    }

    free(nuevo);

}

void mostrarLista(TLISTA lista){

    TCOLA aux;
    iniciac(&aux);
    TELEMENTOC celem;
    while(lista != NULL){

        while(!vaciac(lista->cola)){
            sacac(&lista->cola,&celem);
            printf("%d\n",celem);
            ponec(&aux,celem);
        }

        while(!vaciac(aux)){
            sacac(&aux,&celem);
            ponec(&lista->cola,celem);
        }
        printf("---------------------\n");
        lista = lista->sig;

    }

}
