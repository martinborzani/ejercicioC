#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{

    char caracter;
    struct nodo*sig;
}NODO;

typedef NODO *TLISTA;

void inicializar(TLISTA *lista);
void cargarLista(TLISTA *lista);
void mostrarLista(TLISTA lista);

int main()
{
    TLISTA lista,act,ant;
    char letra;
    int cont;
    inicializar(&lista);
    cargarLista(&lista);
    printf("digite la letra que quieres eliminar\n");
    scanf("%c",&letra);
    act = lista;
    ant = NULL;
    cont = 0;

    while(act != NULL){

        if(letra == act->caracter){
            if(cont != 0){
                cont = 1;
            }else{
                ant->sig = act->sig;
                free(act);
                act = ant->sig;
            }
        }else{
            ant = act;
            act = act->sig;
        }


    }


    mostrarLista(lista);


    return 0;
}


void inicializar(TLISTA *lista){
    *lista = NULL;
}

void cargarLista(TLISTA *lista){

    TLISTA nuevo,ant;
    nuevo = (TLISTA)malloc(sizeof(NODO));
    nuevo->sig = NULL;
    printf("ingrese los caracteres\n");
    while(scanf("%c",&nuevo->caracter) == 1){
        if(*lista == NULL){
            *lista = nuevo;
            ant = *lista;
        }else{
            ant->sig = nuevo;
            ant = nuevo;
        }
        nuevo = (TLISTA)malloc(sizeof(NODO));
        nuevo->sig = NULL;
        printf("ingrese los caracteres\n");
        fflush(stdin);
    }

    free(nuevo);
}

void mostrarLista(TLISTA lista){

    while(lista != NULL){
        printf("%c\n",lista->caracter);
        lista = lista->sig;
    }
}
