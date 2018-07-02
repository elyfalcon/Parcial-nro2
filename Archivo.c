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
    retorno =emp->id;
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



