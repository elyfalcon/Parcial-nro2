#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int id;
    int long sueldo;
    char nombre[20];
    char direccion[25];
    int horas;
}eEmpleado;


int cargarDesdeArchivo(ArrayList *this,const char* nombre);
int ComparaNombre(void* eEmpleadoA,void* eEmpleadoB);
ArrayList* ListarPorNombre(ArrayList *this,int orden);
void MostrarElementos(ArrayList *this,int desde, int hasta);
int CalculaSalario(ArrayList *this);
int CalcularSalary(eEmpleado* element);





#endif // EMPLEADOS_H_INCLUDED
