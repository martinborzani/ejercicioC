#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float promedio(int matriz[][5], int i);

int main()
{

    /* <!-- inicio de ejercicio 11 --> */

        /*
            a) char c[2][6] = {{ "hola"},{"adios"}}; <-- aca se inicializa la matriz en la primera fila hola y en 2da con adios
            b) int d[3][3] = {{1,2,3}, {2,3,4},{5,6,7}}; <-- se inicializa una matriz de entero completo
            c) char c[2][2] = {48} <-- se inicializa toda la matriz con 48
            d) int t[3][3] = {{1,2,3}, {4}, {5,6}} <-- se inicializa la 1ra fila con 1,2,3 la segunda con un 4 y ceros y la 3ra con 5 y 6 y un cero
            e) int a[3][3] = {1,2,3,4,5} <-- en la primera fila pone los primeros 3 numeros, en la 2da fila los ultimos 2 y despues llena de 0
            f)
               int a[3][3], i, j;
               for (i = 0; i <= 2; i++)
                 for (int j = 0; j <= 2; j++)
                    a[i][j] = i + j;  <-- no se llena la matriz

        */


    /* <!-- fin de ejercicio 11 --> */

    /* <!-- inicio de ejercicio 10 --> */

        /*

            a)
                #define FIN "***"
                ...............
                char dato[10];
                gets(dato);
                while(strcmp(dato, FIN) != 0) {
                .........
                gets(dato);
            }   <-- aca se pide que ingrese algun carater o cadena antes del while y en el while compara la cadenas de la constante
                con la ingresada por el usuario, y mientras que no sean iguales las cadenas entra al while y pide otra cadena al usuario
                y si es igual a la constante finalize el while

                b)
                // debe tipear CTRL-Z + Enter
                // para finalizar
                char dato[10];
                while(gets(dato) != NULL) {
                    .........
                } <-- aca pide que ingrese un dato al usuario en el while.. mientras que ingrese cualquier dato entra la while
                si no ingresa nada sale del while



        */

    /* <!-- fin de ejercicio 10 --> */

     /* <!-- inicio de ejercicio 6 --> */

       /* Desarrolle un programa que lea e imprima el promedio de cada fila de una matriz de enteros de 3x5,
utilizando una función que calcule el promedio de un vector de 5 enteros. */


       /* int matriz[3][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        int i;

        for(i = 0; i < 3; i++){
            printf("el promedio de la fila %d es %.2f \n",i,promedio(matriz,i));
        } */

     /* <!-- fin de ejercicio 5 --> */

    /* <!-- inicio de ejercicio 5 --> */

       // char nota [] = "Nos veremos";
       // char *ptr;
       // ptr = nota;
       // puts(ptr);  /* <--- aca muesrta el mensaje nos veremos */
       // puts(++ptr); /* <--- aca muestra el mensaje os veremos ya que se adelante un indice */
       // nota[7] = '\0' ; /* <--- aca muestra el mensaje nos ver ya que en el indice 7 pone un corte de cande \0 */
       // puts(nota); /* <--- aca muesrta el mensaje nos ver ya que en el indice 7 pone un corte de cande \0 */
        //puts(++ptr);  /* <--- aca muestra el mensaje s veremos ya que se adelanta dos indice */


    /* <!-- fin de ejercicio 5 --> */


    /* <!-- inicio de ejercicio 4 --> */

        /*
            strlen = devuelve el tamaño del array de caracter o cadena
            strcmp = compara dos cadenas para averiguar si son iguales
            strcpy = copia una cadena y lo pega en otra variable
            strcat = sirve para concatenar una cadena junto a otra

        */

    /* <!-- inicio de ejercicio 4 --> */


    /* <!-- inicio de ejercicio 3 --> */

        /*
            char a[] = "hola" = aca guarda una cadena;
            char a[4] = "hola" = aca guarda una cadena pero al reservar solo 4 espacio fisico muestra basura
            char a[] = {'h', 'o', 'l' ,'a'} = aca inicializa un arreglo de caracteres pero al no tener un final \0 muestra basura
            char a[] = {'h', 'o', 'l' ,'a','\0'} = aca inicializa un arreglo de caracteres pero muetra hasta el caracter final \0
            char *a = "hola" = aca se genera un puntero y se lo inicializa con una cadena y se puede mostrar todo sin problema

        */



    /* <!-- fin de ejercicio 3 --> */

    /* <!-- inicio de ejercicio 2 --> */

        /*

            la diferencia es que uno es un arrglo y el otro es un puntero, ademas el arreglo tiene un limite fisico guardado
            por computadora mientras que el puntero no tiene un limite fisico!

        */

    /* <!-- fin de ejercicio 1 --> */




    /* <!-- inicio de ejercicio 1 --> */

       /*
            El codigo no esta bien ya que utiliza el == para compracion de cadenas cuando para comparar cadenas se utiliza strcmp
       */

    /* <!-- fin de ejercicio 1 --> */

    return 0;
}


float promedio(int matriz[][5],int i){

    int j;
    float suma;

   for(j = 0; j < 5; j++){
        suma += matriz[i][j];
    }

    return suma/5;

}
