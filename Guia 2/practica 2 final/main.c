#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define valorB(x) ((x) < (0) ? (x * -1) : (x))
#define esCar(x)  ( (isdigit(x)) ? ("es un digito") : ("no es un digito"))
#define cubo(x) ((x)*(x)*(x))
#define N 4
/* Ejercicios 2,3,4,7,8,9,12,14,15*/

    void leevector(int a[], int *dn);
    void elimina_central(int a[], int *n);
    void escvector(int n[], int a);
    void cambiarPalabra(char palabra[], char *palabra1[]);

int main()
{

    /* <!-- inicio de ejercicio 15 --> */

        /*

            a = el error fue generar una arreglo de 3 y inicializar con 4 numeros

            b = no tiene ningun error

            c = el error esta en el scanf de la linea 3 que esta mal escrita y tambien falta una " en la 3ra linea de codigo y separa el & del a;

            d = los errores estan en la funcion que no se puede hacer puntero y no se puede retornar una direccion de memoria y tambien el error esta en el printf que no se puede poner un *

        */



    /* <!-- fin de ejercicio 15 --> */




    /* <!-- inicio de ejercicio 14 --> */

            // pasar esto a una funcion, hacerlo a la tarde

         int i= 0;
        int j;
        char aux;
        char palabra[N] = {'H','O','L','A'};


        for( i = 0; i < N; i++){
            printf("%c",palabra[i]);
        }

        printf("\n");

        for(i = 0, j = N-1; i < (N/2); i++,j--){
            aux = palabra[i];
            palabra[i] = palabra[j];
            palabra[j] = aux;
        }

        for( i = 0; i < N; i++){
            printf("%c",palabra[i]);
        }






    /* <!-- final de ejercicio 14 --> */


    /* <!-- inicio de ejercicio 9 -->*/

        /*
            a = b;
            a[5] = b[5];
            a = {1, 2, 3, 4, 5};
            estas declaraciones no son validas ya que los 2 primero los arreglos tienen difenrete numero de memoria y 3ro no lo inicializa como un arreglo
            a[5] = {1, 2, 3, 4, 5};
            esta declaracion esta bien ya que se inicializa la variable apenas se genera.

        */



    /* <!-- final de ejercicio 9 -->*/



    /* <!-- inicio de ejercicio 8 --> */

        /*
            a) se genera un arreglo de 20 posiciones
            c) se genera un arreglo de entero de 5 posiciones y se los inicializa
            e) se genera una cadena pero esta mal la inicializacion porque no deja el espacio libre \0
            g) se genera un puntero float y un arreglo , y el puntero apunta al arreglo
            b) se genera un arreglo entero de 20 posiciones y otro de 5 posiciones
            d) se genera un arreglo de float sin decir la cantidad de posiciones pero al inicializarlo ya da la cantidad de espacios
            f) se genera un arreglo entero y se inicializa los primeros 3 cuadros
            h) se genera 2 arreglos y se inicializa todas los indices con 0
        */


    /* <!-- final de ejercicio 8 --> */


    /* <!-- final de ejercicio 7 -->*/

/*    int n;
    int a[20];
    leevector(a, &n);
    elimina_central(a, &n);
    escvector(a, n); */


    /* <!-- inicio de ejercicio 4 --> */

    /* se dice que se negocia velocidad y memoria ya que la funcion utiliza un salto
       y ese salto genera una perdida de tiempo y costo computacional. Pero solo se puede
       usar los macros cuando se tiene que hacer una funcion simple, ya seria muy tedioso
       hacer un proceso complejo y largo en una sola linea de codigo
     */


    /* <!-- final de ejercicio 4 --> */



    /* <!-- inicio de ejercicio 3 --> */

    /*int x = -5;
     int y = 6;
     int c = 3;
     printf("el valor absoluto es %d \n",valorB(x));
     printf("%s \n",esCar(y));
     printf("cubo: %d",cubo(c));*/


    /* <!-- final de ejercicio 3 --> */


    /*
        ejercicio 2:
            la diferencia es que una es una funcion o la otra es un macro, que es como una funcion inline
    */
    return 0;
}

/*void cambiarPalabra(char palabra[], char *palabra1[]){
    int i;
    for(i = 0; i < 5; i++){
        fgets(*palabra1[i],5,stdin);
    }

}*/

int func () {
 int i = 5;
 return i;
}



void leevector(int a[], int *dn)
    {
        int i;
        printf("Ingrese la cantidad de elementos del vector<=100: ");
        scanf("%d", dn);
        for(i=0; i<*dn; i++)
        {
            printf("Ingrese el elemento %d: ", i+1);
            scanf("%d",&a[i]);

        }
    }

    void elimina_central (int a[], int *dn)
    {
        int i;
        for(i = (*dn + 1) / 2; i < *dn-1; i++)
            a[i] = a[i+1];
        (*dn)--;
    }

    void escvector(int n[], int a)
    {
        int i = 0;
        for( ; i < a; i++)
            printf("%d ", n[i]);
    }
