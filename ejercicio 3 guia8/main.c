#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{

    int numero;
    struct nodo *sig;

}NODO;

typedef NODO *TLISTA;

void inicializar(TLISTA *lista);
void cargarLista(TLISTA *lista);
void mostrarLista(TLISTA lista);

int main()
{
    TLISTA lista,par,impar,act,aux;
    inicializar(&lista);
    inicializar(&par);
    inicializar(&impar);
    cargarLista(&lista);
    while(lista != NULL){
        aux = lista->sig;
        if(lista->numero % 2 == 0){
            if(par == NULL){
               lista->sig = par;
               par = lista;
               act = lista;
            }else{
               act->sig = lista;;
               act = act->sig;
               act->sig = NULL;
            }
        }else{
             lista->sig = impar;
             impar = lista;
        }

        lista = aux;
    }
    printf("PAR\n");
    mostrarLista(par);
    printf("IMPAR\n");
    mostrarLista(impar);
    return 0;
}


void inicializar(TLISTA *lista){

    *lista = NULL;
}

void cargarLista(TLISTA *lista){

    TLISTA nuevo,ant;
    nuevo = (TLISTA)malloc(sizeof(NODO));
    nuevo->sig = NULL;
    printf("ingrese los numeros\n");
    while(scanf("%d",&nuevo->numero) == 1){
        if(*lista == NULL){
            *lista = nuevo;
            ant = *lista;
        }else{
            ant->sig = nuevo;
            ant = nuevo;
        }

        nuevo = (TLISTA)malloc(sizeof(NODO));
        nuevo->sig = NULL;
        printf("ingrese los numeros\n");
    }

    free(nuevo);
}

void mostrarLista(TLISTA lista){

    while(lista != NULL){
        printf("%d\n",lista->numero);
        lista = lista->sig;
    }
}
