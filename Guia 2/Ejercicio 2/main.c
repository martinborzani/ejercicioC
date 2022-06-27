#include <stdio.h>
#include <stdlib.h>

void escribe(int m);

int main()
{
    /* Un puntero es como el var de pascal para poder guardar los datos de una funcion */

 /* <!-- comienzo de ejercicio 16 --> */
int *ptrl, *ptr2;
 int a, b;
 ptrl = &a; // aca se conecta el puntero 1 con la variable a
 ptr2 = &b;
 *ptrl = 8;
 *ptr2 = 61;
 ptrl = ptr2; // aca se desconecta el puntero 1 con la variable a y se conecta con la variable b
 *ptrl += 2;
 (*ptrl)++;
 printf("%d , %d \n", a, b); // por lo tanto a vale 8 ya que se desconecto antes que el valor cambie
 printf("%d, %d \n", *ptrl, *ptr2);
 printf("%p, %p \n", ptrl, ptr2);
 printf("%p, %p \n", &a, &b);

/* <!-- fin de ejercicio 16 --> */


/* <!-- comienzo ejercicio 13 --> */
//int a = 1, b = 0;
 //int* p = &a;
 //printf ("a = %d ", a);  /* <-- 1 */
 //printf ("p = %p ", p); /* <-- direcicon de memoria */
 //printf ("*p = %d ", *p); /* <-- 1 */
//a = 2;
 //printf ("\na = %d ", a); /* <-- 2 */
 //printf ("p = %p ", p); /* <-- memoria */
// printf ("*p = %d ", *p); /* <-- 2 */
//*p *= 2;
 //printf ("\na = %d ", a); /* <-- 4  comentario: si el puntero cambia, la variable que le pasa la direccion tambien cambia*/
 //printf ("p = %p ", p); /* <-- memoria */
 //printf ("*p = %d ", *p); /* <-- 4 */
 //p = &b;
 //printf ("\na = %d ", a); /* <-- 4 */
 //printf ("p = %p ", p); /* <-- memoria */
 //printf ("*p = %d ", *p); /* <-- 0 */

 /* <!-- fin ejercicio 13 --> */

// pr1intf("%d", **q + x - *p);





  /* <!--- Comienzo de ejercicio 10 guia 2 ---> */

   /* int *pint,y,var = 10;
    pint = &var;
    y = var = (*pint)*2;
    printf("%d \n",y); */ /* <-- respuesta:  20 -->*/


  /* <!--- fin de ejercicio 10 guia 2 ---> */

 /* <!--- Comienzo de ejercicio 6 guia 2 ---> */

   /* int a = 5, b = 6;
    int *p = &a, *q = &b;
    cambio(p,q);
    printf("%d %d",*p,*q);*/


    /*
        respuesta: a) se pasa la direccion por parametro y desde la funcion con el * tienen el valor
        de la direccion;
                   b) El programa tira error ya que no se pasa una direccion y la funcion no puede
        tener el valor de la direccion.
                   c) las variables punteros apuntan al valor de a y b y para mostrarlo en pantalla tengo que mostrarlo con *
    */

 /* <!--- fin de ejercicio 6 guia 2 ---> */


    /* <!--- comienzo ejercicio 5 guia 2 --> */
  //  int veces = 5;
   // char ch = '!'; /* código ASCII 33 */
   // float f = 6.0;
    //escribe(veces);
    //escribe(ch);
//    escribe((int)f); /* conversión explicita*/

    /* <!--- fin ejercicio 5 guia 2 --> */

  /*  float a,b;
    scanf("%f %f",&a,&b);

    intercambia(&a,&b);

    printf("%f %f",a,b);*/

    return 0;
}

/* <!-- funcion ejercicio 6 guia 2 --> */

/*void cambio(int *da,int *db) {
 int aux;
 aux = *da ;
 *da = *db ;
 *db = aux;

 }*/


/* <!-- funcion ejercicio 5 guia 2 --> */
/*void escribe(int m){

while(m--){
    printf("#");

}

printf("\n");
} */
/* <!-- -->*/
/* void intercambia(float *a, float*b){

    float aux;      <!-- funcion basica para conocimietno de puntero -->

    aux = *a;
    *a = *b;
    *b = aux;
}  */
