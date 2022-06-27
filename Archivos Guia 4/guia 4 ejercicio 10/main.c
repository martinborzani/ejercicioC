#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    char codHistorial[6];
    int obesidad;
    int fumador;
    int presion;

} Pacientes;


void cargarPacientes();
void cargarNovedades();
void mostrarArchivos();
void mostrarHistorial(Pacientes paciente);

int main()
{

    int cantCambios;
    Pacientes paciente;
    Pacientes novedades;
    FILE *archPacientes, *archNove, *archActu;
    archPacientes = fopen("pacientesB.dat","rb");
    archNove = fopen("novedadesB.dat","rb");
    archActu = fopen("pacientesActualizados.dat","wb");
    cantCambios = 0;
    if(archPacientes != NULL || archNove != NULL)
    {
        fread(&paciente,sizeof(Pacientes),1,archPacientes);
        fread(&novedades,sizeof(Pacientes),1,archNove);
        printf("Historia Clinica\tObesidad\tFumador\t\tPresion\n");
        while(!feof(archPacientes) || !feof(archNove))
        {
            if(strcmp(paciente.codHistorial,novedades.codHistorial)<0)  // no se modifica
            {
                fwrite(&paciente,sizeof(Pacientes),1,archActu);
                if(paciente.obesidad != novedades.obesidad)
                {
                    printf("S\t");
                }
                else
                {
                    printf("N\t");
                }
                if(paciente.fumador != novedades.fumador)
                {
                    printf("S\t");
                }
                else
                {
                    printf("N\t");
                }
                if(paciente.presion != novedades.presion)
                {
                    printf("S\n");
                }
                else
                {
                    printf("N\n");
                }
                fread(&paciente,sizeof(Pacientes),1,archPacientes);
            }
            else if(strcmp(paciente.codHistorial,novedades.codHistorial)>0)   // se da un alta
            {
                fwrite(&novedades,sizeof(Pacientes),1,archActu);
                fread(&novedades,sizeof(Pacientes),1,archNove);

            }
            else
            {


                if(novedades.obesidad == 0 && novedades.fumador == 0 && novedades.presion == 0)  // se da de baja
                {
                    fread(&paciente,sizeof(Pacientes),1,archPacientes);
                    fread(&novedades,sizeof(Pacientes),1,archNove);
                }

                printf("%s\t\t\t",paciente.codHistorial);

                if(paciente.obesidad != novedades.obesidad)
                {
                    printf("S\t\t");
                }
                else
                {
                    printf("N\t\t");
                }
                if(paciente.fumador != novedades.fumador)
                {
                    printf("S\t\t");
                }
                else
                {
                    printf("N\t\t");
                }
                if(paciente.presion != novedades.presion)
                {
                    printf("S\n");
                }
                else
                {
                    printf("N\n");
                }
               /* paciente.obesidad = novedades.obesidad;
                paciente.fumador = novedades.fumador;
                paciente.presion = novedades.presion;*/
                if(paciente.obesidad == novedades.obesidad && paciente.fumador == novedades.fumador && paciente.presion == novedades.presion)
                {
                    cantCambios++;
                }

                fwrite(&novedades,sizeof(Pacientes),1,archActu);
                fread(&paciente,sizeof(Pacientes),1,archPacientes);
                fread(&novedades,sizeof(Pacientes),1,archNove);
            }
        }// fin del while

        fclose(archActu);
        fclose(archNove);
        fclose(archPacientes);
    }
    else
    {
        printf("algun archivo no existe \n");
    }

     mostrarHistorial(paciente);

    // mostrarArchivos();
      printf("cantidad sin cambios %d \n",cantCambios);
    return 0;
}


void mostrarHistorial(Pacientes paciente){

    FILE *archAct;
    archAct = fopen("pacientesActualizados.dat","rb");
    printf("ARCHIVO ACTUALIZADO \n");
    if(archAct != NULL){

        fread(&paciente,sizeof(Pacientes),1,archAct);
        printf("Historia Clinica\t\tObesidad\tFumador\t\tPresion\n");
        while(!feof(archAct)){
            printf("%s\t\t\t\t %d\t\t%d\t\t %d \n",paciente.codHistorial,paciente.obesidad,paciente.fumador,paciente.presion);
            fread(&paciente,sizeof(Pacientes),1,archAct);
        }
        fclose(archAct);
    }else{
        printf("el archivo no existe\n");
    }


}

void mostrarArchivos()
{

    Pacientes paciente;
    FILE *arch;

    arch = fopen("pacientesActualizados.dat","rb");
    //arch = fopen("novedadesB.dat","rb");
    //arch = fopen("pacientesB.dat","rb");
    if(arch != NULL)
    {
        fread(&paciente,sizeof(Pacientes),1,arch);
        while(!feof(arch))
        {
            printf("%s %d %d %d \n",paciente.codHistorial,paciente.obesidad,paciente.fumador,paciente.presion);
            fread(&paciente,sizeof(Pacientes),1,arch);
        }
        fclose(arch);
    }
    else
    {
        printf("el archivo no existe");
    }

}


void cargarPacientes()
{

    Pacientes paciente;

    FILE *archT, *archB;

    archT = fopen("Pacientes.txt","r");
    archB = fopen("pacientesB.dat","wb");

    if(archT != NULL)
    {
        while(fscanf(archT,"%s %d %d %d",paciente.codHistorial,&paciente.obesidad,&paciente.fumador,&paciente.presion) == 4)
        {
            fwrite(&paciente,sizeof(Pacientes),1,archB);
        }

        fclose(archB);
        fclose(archT);
    }
    else
    {
        printf("el archivo no existe \n");
    }

}

void cargarNovedades()
{

    Pacientes paciente;

    FILE *archT, *archB;

    archT = fopen("Novedades.txt","r");
    archB = fopen("novedadesB.dat","wb");

    if(archT != NULL)
    {
        while(fscanf(archT,"%s %d %d %d",paciente.codHistorial,&paciente.obesidad,&paciente.fumador,&paciente.presion) == 4)
        {
            fwrite(&paciente,sizeof(Pacientes),1,archB);
        }

        fclose(archB);
        fclose(archT);
    }
    else
    {
        printf("el archivo no existe \n");
    }

}
