#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "tools.h"
#include "Archivo.h"
#include "Empleados.h"
#define ENCABEZADO 0
#define CANTIDAD 5


int parserEmployee(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
    int cantidadDatosLeidos;
    int agregoRecord;
    char cabecera[80];
    int guardoDato;

    eEmpleado* record;

    char Nombre[20];
    char Id[2];
    char dire[25];
    char sueldo[10];
    char horas[10];


    if(pFile != NULL)
    {
        retorno = -2;
        if(ENCABEZADO == 1)
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
                cantidadDatosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",Id,Nombre,dire,sueldo,horas);
                if(cantidadDatosLeidos == CANTIDAD)
                {

                   guardoDato = Empleado_setId(record, charToint(Id) );

                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = Empleado_setName(record,(char*) Nombre);
                    if(guardoDato !=0)
                    {
                        break;
                    }

                    guardoDato = Empleado_setDire(record,dire );
                    if(guardoDato !=0)
                    {
                        break;
                    }
                    guardoDato = Empleado_setSueldo(record, charToint(sueldo) );

                    guardoDato = Empleado_setHoras(record, charToint(horas) );

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
int Muestra1UnElemento(eEmpleado * emp)
{
    int retorno=-1;
    if(emp !=NULL)
    {
        retorno=0;
        //printf("%s\t%s \n",emp->nombre,emp->direccion);//agregar geters
        printf("%s\t%s\t%d\tSueldo Total:%d \n",get_Nombre(emp),get_dire(emp),get_horas(emp), get_sueldo(emp));//agregar geters


    }
    return retorno;
}
int Muestra1UnElementoSalario(eEmpleado * emp)
{
    int retorno=-1;
    if(emp !=NULL)
    {
        retorno=0;
      //  printf("%s\t%s\t%d \n",emp->nombre,emp->direccion,emp->sueldo);//agregar geters
        printf("%s\t%s\t%d\tSueldo Total:%d \n",get_Nombre(emp),get_dire(emp),get_horas(emp), get_sueldo(emp));//agregar geters


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
        printf("\n\n--------LISTADO ORDENADO POR NOMBRE  --------\n");
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=desde;i<hasta;i++)
            {
                Muestra1UnElemento(al_get(this,i));
            }//fin for i
        }
        system("\npause");
    }
}

void MostrarElementosconSalario(ArrayList *this,int desde, int hasta)
{
    int i;
   // if(this !=NULL && desde>=0 && hasta < this->len(this))
   if(this !=NULL)
    {
        system("cls");
        printf("\n\n--------LISTADO CON SALARIO  --------\n");
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=desde;i<hasta;i++)
            {
                Muestra1UnElementoSalario(al_get(this,i));
            }//fin for i
        }
        system("\n pause");
    }
}



ArrayList* ListarPorNombre(ArrayList *this,int orden)
{
    ArrayList *ListOrdenada;
    ListOrdenada=NULL;
    if(this!=NULL)
    {
        ListOrdenada=al_newArrayList();
        //ListOrdenada=al_clone(this);
        ListOrdenada=al_clone(this);
        if(ListOrdenada !=NULL)
        {
            ListOrdenada->sort(this,ComparaNombre,1);
        }
    }//fin if this!Null
return ListOrdenada;
}
int ComparaNombre(void* eEmpleadoA,void* eEmpleadoB)
{
    int retorno=-1;
    if (strcmp(((eEmpleado*)eEmpleadoA)->nombre,((eEmpleado*)eEmpleadoB)->nombre)==1)
    {
      retorno=1;
    }
        if (strcmp(((eEmpleado*)eEmpleadoA)->nombre,((eEmpleado*)eEmpleadoB)->nombre)==-1)
    {
      retorno=0;

    }
    return retorno;

}

int CalculaSalario(ArrayList *this)
{
    int retorno=0;
    int aux;
    int opcion;
    eEmpleado *aux_emp;
    aux=aux_emp->horas;
    if(this !=NULL)
    {
    retorno=1;
    if(aux <=120)
    {
        Empleado_setSueldo(this,(aux_emp->horas)*180);
    }
    if(aux >120 && aux <=160)
    {
     Empleado_setSueldo(this,(aux_emp->horas)*240);
    }
    if(aux >160 && aux <=240)
    {
    Empleado_setSueldo(this,(aux_emp->horas)*350);
    }
    }//fin this!
return retorno;


}
int CalcularSalary(eEmpleado* element)
{
    int aux;
    int cont=0;
    int retorno=-1;
   // eEmpleado *element;


    if(element !=NULL)
    {
        retorno=0;
        if(element->horas <=120)
        {
            Empleado_setSueldo(element,(element->horas)*180);

        }
        if(element->horas > 120 && element->horas <= 160)
        {
           Empleado_setSueldo(element,(element->horas)*240);

        }
        if(element->horas > 160 && element->horas <=240)
        {
          Empleado_setSueldo(element,(element->horas)*350);

        }
    }//fin if(element !=)


 return retorno;
}
