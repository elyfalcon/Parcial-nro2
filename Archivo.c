#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "tools.h"
#include "Empleados.h"



eEmpleado* nuevo(void)
{
    eEmpleado* returnAux;
    returnAux = (eEmpleado*)malloc(sizeof(eEmpleado));
    return returnAux;
}

int charToint(char* charInt)
{
    int nro;
    nro = atoi(charInt);
    return nro;
}
float charToFloat(char* charFlt)
{
    float num;
    num=atof(charFlt);
    return num;
}
int get_id(eEmpleado* this)
{
    return this->id;
}

char* get_Nombre(eEmpleado* this)
{
    return this->nombre;
}

char* get_dire(eEmpleado* this)
{
    return this->direccion;
}

int get_horas(eEmpleado* this)
{
    return this->horas;
}

int get_sueldo(eEmpleado* this)
{
    return this->sueldo;
}









//-----------------------------------
int Empleado_setId(eEmpleado* this, int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->id = dato;
    }

    return 0;
}
int Empleado_setSueldo(eEmpleado* this,int dato)
{
    if(this!=NULL && dato!=NULL)
    {
        this->sueldo=dato;
    }
    return 0;
}
int Empleado_setHoras(eEmpleado* this,int dato)
{
    if(this!=NULL && dato !=NULL)
    {
        this->horas=dato;
    }
    return 0;
}

int Empleado_setDire(eEmpleado* this,  char *dato)
{
    strcpy(this->direccion,dato);
    return 0;
}

int Empleado_setName(eEmpleado* this, const char* name)
{
    strcpy(this->nombre, name);
    return 0;
}
//-----------------------------------------------------
/*
int get_id(eEmpleado * emp)
{
    int retorno;
    if(emp !=NULL)
    {
      retorno =emp->id;
    }

    return retorno;
}
char *get_Nombre(eEmpleado * emp)
{
    char retorno;
    if(emp !=NULL)
    {
        retorno=emp->nombre;
    }
    return retorno;
}
char *get_dire(eEmpleado * emp)
{
    char retorno;
    if(emp !=NULL)
    {
        retorno=emp->direccion;
    }
    return retorno;
}
int get_horas(eEmpleado *emp)
{
    int retorno;
    if(emp !=NULL)
    {
        retorno=emp->horas;
    }
    return retorno;
}

int get_sueldo(eEmpleado *emp)
{
    int retorno;
    if(emp !=NULL)
    {
        retorno=emp->sueldo;
    }
    return retorno;
}*/

int GuardarArchivoT(ArrayList* this, const char* nombre)
{
        int retorno=-1;
        int i;
        int tamanio=0;
        if(this!=NULL)
        {
            eEmpleado* emp;
            FILE *f;
            f=fopen(nombre, "w");
            if(f==NULL)
            {
                retorno=0;
            }
            else
            {
                if(emp !=NULL)
                {
                    tamanio=al_len(this);
                    for (i=0; i<tamanio; i++)
                    {
                    emp = (eEmpleado*)al_get(this, i);
                    fprintf(f,"%d,%s,%s,%d,%f\n",get_id(emp),get_Nombre(emp),get_dire(emp),get_horas(emp),get_sueldo(emp));
                   // fprintf(f,"%d,%s,%s,%d,%d\n",emp->id,emp->nombre,emp->direccion,emp->horas,emp->sueldo);
                    retorno=1;
                    }//fin for
                    }//fin if(aux!=NULL)
                fclose(f);
            }//fin else
        }// fin if(!=null)
        if(retorno==1)
        {
            printf("Se creo el archivo sueldo.csv correctamente\n");
            system("pause");
        }
        else
        {
            printf("No se pudo crear el archivo sueldo.csv\n");
            system("pause");
        }

        return retorno;

}
int GuardarArchivoB(ArrayList* this,char nombrearchivo[])
{
    int retorno=-1;
    int i;

    if(this!=NULL)
    {
        eEmpleado* aux;
        FILE *f;

        f=fopen(nombrearchivo, "wb");
        if(f==NULL)
        {
            retorno=0;
        }
        else
        {
            int tamanio;
            tamanio=al_len(this);
            for (i=0; i<tamanio; i++)
            {
                aux = (eEmpleado*)al_get(this, i);
                fwrite(aux,sizeof(eEmpleado),1,f);
                retorno=1;
            }
            fclose(f);
        }
    }
    return retorno;
}

int BuscaMaximo(ArrayList *this)
{

}
int ComparaEntero(void* eEmpleadoA,void* eEmpleadoB)
{
    eEmpleado *retorno;
    if (((eEmpleado*)eEmpleadoA)->sueldo >((eEmpleado*)eEmpleadoB)->sueldo)
    {
      retorno=eEmpleadoA;
    }
        if (((eEmpleado*)eEmpleadoA)->sueldo <((eEmpleado*)eEmpleadoB)->sueldo)
    {
      retorno=eEmpleadoB;

    }
    return retorno;

}

