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

int get_id(eEmpleado * emp)
{
    int retorno;
    if(emp !=NULL)
    {
      retorno =emp->id;
    }

    return retorno;
}
char get_Nombre(eEmpleado * emp)
{
    char retorno;
    if(emp !=NULL)
    {
        retorno=emp->nombre;
    }
    return retorno;
}
char get_dire(eEmpleado * emp)
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
    int long retorno;
    if(emp !=NULL)
    {
        retorno=emp->sueldo;
    }
    return retorno;
}

int GuardarArchivoT(ArrayList* this, const char* nombre)
{
        int retorno=-1;
        int i;
        if(this!=NULL)
        {
            eEmpleado* aux;
            FILE *f;
            f=fopen(nombre, "w");
            if(f==NULL)
            {
                retorno=0;
            }
            else
            {
                if(aux !=NULL)
                {
                    int tamanio;
                    tamanio=al_len(this);
                    for (i=0; i<tamanio; i++)
                    {
                    aux = (eEmpleado*)al_get(this, i);
                    fprintf(f,"%d,%s,%s,%d,%d\n",get_id(aux),get_Nombre(aux),get_dire(aux),get_horas(aux),get_sueldo(aux));
                    retorno=1;
                    }//fin for
                    }//fin if(aux!=NULL)
                fclose(f);
            }//fin else
        }// fin if(!=null)
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




