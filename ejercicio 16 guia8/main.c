#include <stdio.h>
#include <stdlib.h>
#include "tdacola.h"
#include "tdapila.h"

typedef struct nodito{
    int numero;
    struct nodito *sig;

}NODITO;

typedef NODITO *TSUBLISTA;

typedef struct nodo{
    int numero;
    TSUBLISTA sublista;
    struct nodo *sig;
}NODO;

typedef NODO *TLISTA;


void inicializar(TLISTA *lista);
void cargarLista(TLISTA *lista);
void cargarPila(TPILA *pila);
void mostrarLista(TLISTA lista);

int main()
{
    TLISTA lista,act,ant;
    TSUBLISTA actSub,antSub,nuevoSub;
    TPILA pila;
    int centinela;
    TELEMENTOP pelem;
    inicializar(&lista);
    iniciap(&pila);
    cargarLista(&lista);
    cargarPila(&pila);

    while(!vaciap(pila)){
        act = lista;
        ant = NULL;
        sacap(&pila,&pelem);
        centinela = 0;
        while(centinela != 1){

            while(act != NULL && act->numero % pelem != 0){
                ant = act;
                act = act->sig;
            }
            if(act != NULL){
                actSub = act->sublista;
                antSub = NULL;
                while(actSub != NULL && pelem != actSub->numero){
                    antSub = actSub;
                    actSub = actSub->sig;
                }
                if(actSub == NULL){
                    nuevoSub = (TSUBLISTA)malloc(sizeof(NODITO));
                    nuevoSub->sig = NULL;
                    nuevoSub->numero = pelem;
                    actSub = act->sublista;
                    antSub = NULL;
                    while(actSub != NULL && pelem < actSub->numero){
                        antSub = actSub;
                        actSub = actSub->sig;
                    }
                    if(antSub == NULL){

                        act->sublista = nuevoSub;
                        nuevoSub->sig = actSub;
                    }else{
                        antSub->sig = nuevoSub;
                        nuevoSub->sig = actSub;
                    }

                    centinela = 1;
                }

            }else{
                centinela = 1;
            }

        }

    }

    mostrarLista(lista);
    return 0;
}


void inicializar(TLISTA *lista){
    *lista = NULL;
}

void cargarPila(TPILA *pila){

    TELEMENTOP pelem;
    printf("ingrese datos a la pila\n");
    while(scanf("%d",&pelem) == 1){
        ponep(pila,pelem);
    }
}

void cargarLista(TLISTA *lista){

    TLISTA nuevo;
    TSUBLISTA nuevoSub;
    nuevo = (TLISTA)malloc(sizeof(NODO));
    nuevo->sig = NULL;
    printf("ingrese el numero del nodo\n");
    while(scanf("%d",&nuevo->numero) == 1){
        nuevoSub = (TSUBLISTA)malloc(sizeof(NODITO));
        nuevoSub->sig = NULL;
        nuevo->sublista = NULL;
        nuevo->sig = *lista;
        *lista = nuevo;
        printf("ingrese los datos de la sublista\n");
        while(scanf("%d",&nuevoSub->numero) == 1){
            nuevoSub->sig = nuevo->sublista;
            nuevo->sublista = nuevoSub;
            nuevoSub = (TSUBLISTA)malloc(sizeof(NODITO));
            nuevoSub->sig = NULL;
            printf("ingrese los datos de la sublista\n");
        }

        nuevo = (TLISTA)malloc(sizeof(NODO));
        nuevo->sig = NULL;
        printf("ingrese el numero del nodo\n");
    }

    free(nuevo);
    free(nuevoSub);

}

void mostrarLista(TLISTA lista){
    TSUBLISTA aux;
    while(lista != NULL){
        printf("%d\n",lista->numero);
        aux = lista->sublista;
        while(aux != NULL){
            printf("%d\n",aux->numero);
            aux = aux->sig;
        }
        lista = lista->sig;
    }

}
