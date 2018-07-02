#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Estructura.h"

eAlumno* nuevo(void)
{
    eAlumno* returnAux;
    returnAux = (eAlumno*)malloc(sizeof(eAlumno));
    return returnAux;
}

int charToint(char* charInt)
{
    int nro;
    nro = atoi(charInt);
    return nro;
}

int Alumno_setEdad(eAlumno* this, int dato)
{
    this->edad = dato;
    return 0;
}

int Alumno_setLegajo(eAlumno* this, int dato)
{
    this->legajo = dato;
    return 0;
}

int Alumno_setSexo(eAlumno* this,  char *dato)
{
    strcpy(this->sexo,dato);
    return 0;
}

int Alumno_setName(eAlumno* this, const char* name)
{
    strcpy(this->nombre, name);
    return 0;
}
int get_Edad(eAlumno * alum)
{
    int retorno;
    retorno =alum->edad;
    return retorno;
}
char get_Nombre(eAlumno * alum)
{
    char retorno;
    if(alum !=NULL)
    {
        retorno=alum->nombre;
    }
    return retorno;
}
char get_Sexo(eAlumno * alum)
{
    char retorno;
    if(alum !=NULL)
    {
        retorno=alum->sexo;
    }
    return retorno;
}


int CompararEdad(void* eAlumno1,void* eAlumno2)
{
    int retorno=-1;

    if(((eAlumno*)eAlumno1)->edad >((eAlumno*)eAlumno2)->edad)
    {
        retorno=1;
    }
    if(((eAlumno*)eAlumno1)->edad <((eAlumno*)eAlumno2)->edad)
        retorno=0;
    return retorno;
}
ArrayList* ListarPorEdad(ArrayList *this,int orden)
{
    ArrayList *ListOrdenada;
    ListOrdenada=NULL;
    if(this!=NULL)
    {
        ListOrdenada=al_newArrayList();
        ListOrdenada=al_clone(this);
        if(ListOrdenada !=NULL)
        {
            ListOrdenada->sort(this,CompararEdad,1);
        }
    }//fin if this!Null
return ListOrdenada;
}


int Muestra1UnElemento(eAlumno * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        retorno=0;
        printf("Nombre: %s    \t\t",record->nombre);
        printf("Edad: %d \t",record->edad);
        printf("Legajo: %d \t",record->legajo);
        printf("Sexo: %s \n",record->sexo);
    }
    return retorno;
}
void MostrarElementos(ArrayList *this,int desde, int hasta)
{
    int i;
   // if(this !=NULL && desde>=0 && hasta < this->len(this))
   if(this !=NULL)
    {
        system("cls");
        printf("\n\n--------LISTADO ORDENADO POR EDAD  --------\n");
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=desde;i<hasta;i++)
            {
                Muestra1UnElemento(al_get(this,i));
            }//fin for i
        }
        system("pause");
    }
}
ArrayList* al_filter(ArrayList* listln , int (*functionFilter)(void*))//agregada
{
    ArrayList* ListaAuxiliar;
    ListaAuxiliar=al_newArrayList();
    int i;

    if(listln!=NULL)
    {
        if(ListaAuxiliar!=NULL )
        {
            for(i=0;i<listln->len(listln);i++)
            {
                if(functionFilter(listln->get(listln,i))==1)
                {
                    ListaAuxiliar->add(listln,listln->get(listln,i));
                }

            }//fin for
        }
    }//fin listln
    return ListaAuxiliar;

int funcionQuefiltra(void* item)
{
 int retorno=0;
 eAlumno *aux_alumno;
 aux_alumno=(eAlumno * ) item;
 if(get_edad(aux_alumno)>30)
 {
     retorno=1;
 }
 return retorno;
}

}
/*int CompararElementos(ArrayList *this,int orden)
{
 void* pElement;
 int i,j;
 if(this !=NULL && orden==1 || orden ==0)
 {
     for(i=0;i< this->len(this)-1;i++)
     {
         for(j=i+j;j<this->len(this);j++)
         {
             if(order==0)
                {
                    if(al_get(this,i),al_get(this,j)) <0)
                    {
                        AuxElement=al_get(this,i);
                        al_set(this,i,al_get(this,j));
                        al_set(this,j,AuxElement);
                    }
                }//fin ir order
         }//fin for j

     }//fin for i
 }
}

*/
/*ArrayList* clonaOrdenado(ArrayList *this,int (*pFunc)(void* ,void*),int orden)
{
    ArrayList *ListaOrdenada=NULL;
    if(this!=NULL)
    {
        ListaOrdenada = al_newArrayList();
        ListaOrdenada=al_clone(this);
        if(ListaOrdenada!=NULL)
        {
            //if(ListaOrdenada->sort(ListaOrdenada,compara_elementos_Estructura,1)==-1)
            if(ListaOrdenada->sort(ListaOrdenada,pFunc,1)==-1)
            {
                ListaOrdenada=NULL;
            }
        }
    }
    return ListaOrdenada;
}*/
int persona_comparaNombre(void* pEmployeeA,void* pEmployeeB)
{
    int retorno=0;
    if (strcmp(((Employee*)pEmployeeA)->name,((Employee*)pEmployeeB)->name)==1)
    {
      retorno=1;
    }
        if (strcmp(((Employee*)pEmployeeA)->name,((Employee*)pEmployeeB)->name)==-1)
    {
      retorno=-1;

    }
    return retorno;

}
int persona_compareDNI(void* pEmployeeA,void* pEmployeeB)

{

    int retorno=0;

    if (strcmp(((Employee*)pEmployeeA)->dni,((Employee*)pEmployeeB)->dni)==1)
    {

      retorno=1;

    }

        if (strcmp(((Employee*)pEmployeeA)->dni,((Employee*)pEmployeeB)->dni)==-1)
    {

      retorno=-1;
    }
    return retorno;

}



