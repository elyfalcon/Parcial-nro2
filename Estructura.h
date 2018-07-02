#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

typedef struct
{
    char nombre [25];
    int edad;
    int legajo;
    char sexo [1];
}eAlumno;


//ArrayList* ListarPorEdad(ArrayList *this,int (*pFunc)(void* ,void*));
ArrayList* clonaOrdenado(ArrayList *this,int (*pFunc)(void* ,void*),int orden);
ArrayList* ListarPorEdad(ArrayList *this,int orden);
void MostrarElemento(ArrayList *this,int desde, int hasta);
int Muestra1UnElemento(eAlumno * record);
int funcionQuefiltra(void* item);





#endif // ESTRUCTURA_H_DECLARED
