#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

typedef struct{

    char nombre[50];
    int matricula;
    float promedio;
}Alumno;

typedef struct{

    int indice;
    int suma;
    int pares;

}matricula;


void leerAlumno(Alumno alumnos[], int *c); /* <-- funcion del ejercicio 7  */
void maxPromedio(Alumno alumnos[],int c, char nombreMax[]);
void menorPromedio(Alumno alumnos[],int c, int x);
//void leerMatriz(int matrizA[][N],int *i,int *j);
void llenarVector(matricula Matricula[],int matrizA[][3],int n,int m,int *k);


int main()
{

    /* <--- inicio de ejercicio 13 ---> */



    /* <--- fin de ejercicio 13 ---> */

    /* <--- inicio de ejercicio 12 ---> */
    /*int n,m,k,i;
    int matrizA[3][3] = {{2,4,3},{9,12,11},{4,7,3}};
    matricula Matricula[50];
    n = 3;
    m = 2;
    llenarVector(Matricula,matrizA,n,m,&k);
    for(i = 0; i < k ; i++){
        printf("%d %d %d",Matricula[i].indice,Matricula[i].suma,Matricula[i].pares);
    }*/


    /* <--- fin de ejercicio 12 ---> */


    /* <--- inicio de ejercicio 8 ---> */

      /*  Alumno almunos[20];
        int c,x;
        char nombreMax[25];
        leerAlumno(almunos,&c);
        maxPromedio(almunos,c,nombreMax);
        printf("el alumno con mayor promedio es: %s",nombreMax);
        printf("ingrese el promedio limite: \n");
        scanf("%d",&x);
        menorPromedio(almunos,c,x);*/

    /* <--- fin de ejercicio 8 ---> */

    /* <--- inicio de ejercicio 7 ---> */

   /* Alumno almunos[20];
    int c,i;

    leerAlumno(almunos,&c);

    for(i=0; i < c; i++){
        printf("Alumno: %d\n",i+1);
        printf("Nombre: %s\n",almunos[i].nombre);
        printf("Matricula: %d\n",almunos[i].matricula);
        printf("Promedio: %2.f\n",almunos[i].promedio);
    }*/

    /* <--- fin de ejercicio 7 ---> */
    return 0;
}


int obtenerPosicion(Autos autos[],Autos autos2, int j){

    int i = 0;
    while(i < j && autos[i].categoria != autos2.categoria){
        i++;
    }

    return i;
}

void llenarVector(matricula Matricula[],int matrizA[][3],int n,int m,int *k){

    int i,j;
    *k = 0;
    int sumaI;
    int sumaP;
    sumaI = 0;
    sumaP = 0;
    for(i = 0; i < 3; i++){
        Matricula[*k].indice = i;
        for(j=0; j < 3; j++){
            if(matrizA[i][j] % n == 0){
                sumaI += matrizA[i][j];
            }else if(matrizA[i][j] % m == 0){
                sumaP += matrizA[i][j];
             }

            if(sumaI != 0){
                Matricula[*k].suma += sumaI;
            }else if(sumaP != 0){
                     Matricula[*k].pares += sumaP;
                  }
        }
    }

}


void leerAlumno(Alumno alumnos[],int *c){

    int l;
    *c = 0;
    do{
        printf("ingrese el nombre del alumno \n");
        fflush(stdin); /* <-- se utiloza para limpiar el buffer de escritura por teclado si es que el programa te escribo por si solo */
        fgets(alumnos[*c].nombre,50,stdin);
        printf("ingrese la matricula del alumno \n");
        scanf("%d",&alumnos[*c].matricula);
        printf("ingrese el promedio \n");
        scanf("%f",&alumnos[*c].promedio);
        printf("quieres seguir ingresando alumnos? 0 para salir otra letra para continuar\n");
        scanf("%d",&l);
        (*c)++;
    }while(l != 0);

    getchar();

}

void maxPromedio(Alumno alumnos[],int c, char nombreMax[]){

    int i;
    float promMax = alumnos[0].promedio;
    strcpy(nombreMax,alumnos[0].nombre);
    for(i = 1; i < c; i++){
        if(alumnos[i].promedio > promMax){
            promMax = alumnos[i].promedio;
            strcpy(nombreMax,alumnos[i].nombre);
        }
    }
}

void menorPromedio(Alumno alumnos[],int c,int x){

    int i;
    for(i = 0; i < c; i++){
       if(alumnos[i].promedio < x){
           printf("alumnos con los promedios debajo de la media: \n");
           printf("Lista: %d\n", i+1);
           printf("Nombre: %s\n", alumnos[i].nombre);
           printf("Matricula: %d\n", alumnos[i].matricula);
           printf("Promedio: %2.f\n", alumnos[i].promedio);
       }
    }
}
