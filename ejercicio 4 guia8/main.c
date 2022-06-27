#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{

    int num;
    struct nodo*sig;

}NODO;

typedef NODO *TLISTA;

void inicializar(TLISTA *lista);
void cargarLista(TLISTA *lista);
void llenarListaPrincipal(TLISTA *lista, TLISTA *lista1);
void mostrarLista(TLISTA lista);


int main()
{

    TLISTA lista,lista1,lista2,act,ant,aux,aux2;
    inicializar(&lista);
    inicializar(&lista1);
    inicializar(&lista2);
    printf("cargar la lista 1: \n");
    cargarLista(&lista1);
    printf("cargar la lista 2: \n");
    cargarLista(&lista2);
    llenarListaPrincipal(&lista,&lista1);
    printf("LISTA SIN ORDEN\n");
    mostrarLista(lista);

    while(lista2 != NULL){
        aux2 = lista2->sig;
        aux = lista;
        act = aux;
        ant = NULL;

        while(act != NULL && act->num > lista2->num){
            ant = act;
            act = act->sig;
        }


         if(ant != NULL){
            ant->sig = lista2;
            lista2->sig = act;
        }else{
            lista2->sig = act;
            act = lista2;
        }

        lista2 = aux2;
    }
    printf("LISTA ORDENADA\n");
    mostrarLista(lista);
    return 0;
}


void inicializar(TLISTA *lista){

    *lista = NULL;
}

void llenarListaPrincipal(TLISTA *lista,TLISTA *lista1){
    TLISTA aux;
    while(*lista1 != NULL){
         aux = (*lista1)->sig;
        (*lista1)->sig = *lista;
        *lista = *lista1;
        *lista1 = aux;
    }

}

void cargarLista(TLISTA *lista){

    TLISTA nuevo,ant;
    nuevo = (TLISTA)malloc(sizeof(NODO));
    nuevo->sig = NULL;
    printf("ingrese numeros\n");
    while(scanf("%d",&nuevo->num) == 1){
        if(*lista == NULL){
            *lista = nuevo;
            ant = *lista;
        }else{
            ant->sig = nuevo;
            ant = nuevo;
        }
        nuevo = (TLISTA)malloc(sizeof(NODO));
        nuevo->sig = NULL;
        printf("ingrese numeros\n");
    }

    free(nuevo);
}

void mostrarLista(TLISTA lista){

    while(lista != NULL){
        printf("%d\n",lista->num);
        lista = lista->sig;
    }
}
