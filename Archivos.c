#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "tools.h"
#include "Estructura.h"
#include "Dato.h"
#include "Archivos.h"
#define TAM 10



int parserEmployee(FILE* pFile, ArrayList* this)
{
     int retorno = -1;
    int cantidadFilasLeidas = 0;
    int cantidadDatosLeidos;
    int agregoRecord;
    char cabecera[80];
    int guardoDato;

    eAlumno* record;

    char Nombre[30];
    char Edad[10];
    char Legajo[10];
    char Sexo[2];

    if(pFile != NULL)
    {
        retorno = -2;
        if(TIENE_ENCABEZADO_ARCHIVO == 1)
        {
            //descarto la lectura del encabezado
            fgets(cabecera, 80, pFile);
        }

        while(!feof(pFile))
        {
            retorno = 0;
            record = nuevo();
            if(record != NULL)
            {
                cantidadDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",Nombre,Edad,Legajo,Sexo);
                if(cantidadDatosLeidos == CANTIDAD_CAMPOS_ARCHIVO)
                {

                    guardoDato = Alumno_setName(record,(char*) Nombre);
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = Alumno_setEdad(record, charToint(Edad) );
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = Alumno_setLegajo(record,charToint(Legajo) );
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    //guardoDato = Alumno_setSexo(record,(char) Sexo );
                    guardoDato = Alumno_setSexo(record,(char *) Sexo );
                    if(guardoDato !=0)
                    {
                        break;
                    }


                    al_add(this, record);

                    cantidadFilasLeidas++;
                }
                else //Fin de archivo u otro error
                {
                    break;
                }
            }
            else //Sin memoria
            {
                break;
            }
        }
    }
/*
    int r,i;
    int flag=0;
    char var1[20];
    char var2[10];
    int var3[20];
    char var4[20];

    eAlumno* alum;


   pFile=fopen("alumnos.csv","r");

   if(pFile==NULL)

   {
       flag=-1;

   }

   fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

   while(!feof(pFile))
      {

        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    //    if(r==4)

    //    {

        alum=(eAlumno*)malloc(sizeof(eAlumno));
        alum->edad=atoi(var2);
        strcpy(auxalumno->nombre,var1);
        alum->legajo=var3;
        strcpy(alum->sexo,var4);
       /* if(strcmp(var4,"false"))
            {
            auxempleado->isEmpty=0;

            }

        else
            auxempleado->isEmpty=1;*/
    //  al_add(pArrayListEmployee,auxempleado);

     //   flag=1;

       // }
  //  }
  //  fclose(pFile);*/
    return retorno;

}
int cargarDesdeArchivo(ArrayList *this,const char* nombre)
{
	int flag = 0;
	FILE *pArchivo;

    if(this !=NULL && nombre !=NULL)
    {
        pArchivo=fopen(nombre,"r");
        if(pArchivo != NULL)
        {
            flag=0;
		//pArchivo= fopen("nombre", "wb");
            if(parserEmployee(pArchivo,this)==0)
            {
                flag= 1;
                fclose(pArchivo);

            }
        }
    }
        if(flag ==1)
        {
	    printf("Carga Correcta:\n");
	    system("pause");
        }
        else
        {
            printf("No se pudo cargar\n");
            system("pause");
        }


	return flag;

}
void CrearListado(EMovie *peli,int cant)
{
     int i;
     FILE *f;
     f=fopen("Peliculas.txt", "w");

     if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");

     }

     else

     {
         fprintf(f,"Listado de Peliculas\n\n\n");

         fprintf(f,"-----------------------------------------------------------------\n");

         fprintf(f,"Titulo             Descripcion       Genero       Duracion       Puntaje \n");

         fprintf(f,"-----------------------------------------------------------------\n");

         for(i=0; i<cant; i++)
         {
                if(peli[i].id != 0)
                  {

                  fprintf(f,"%s\t    %s %s\t\%d\t%d\n", peli[i].titulo, peli[i].descripcion, peli[i].genero, peli[i].duracion,peli[i].puntaje);

                  }
         }
      }

      fclose(f);

      printf("Listado creado con exito\n");

      system("pause");

}
