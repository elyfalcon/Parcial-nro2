#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "tools.h"
#include "Empleados.h"
#include "Archivos.h"
#define NOM_ARCHIVO "archivo.csv"

int main()
{
    char seguir='S';
    int opcion;
    int retorno=0;

    ArrayList *ListaEmpleados;
    ListaEmpleados=al_newArrayList();
    ArrayList *ListaAux;
    ListaAux=al_newArrayList();

    if(ListaEmpleados !=NULL)
    {

        while(seguir=='S')
        {
          ShowMenu("1:Cargar Archivo\n2:Listar \n3:Listar ordenado\n4:Lista Salario\n");
          scanf("%d",&opcion);
          ValidaMenu(opcion,0,4);
            switch(opcion)
            {
                case 1:
                    cargarDesdeArchivo(ListaEmpleados,NOM_ARCHIVO);
                    break;
                case 2:
                    ListaAux=ListarPorNombre(ListaEmpleados,1);
                   if(ListaAux !=NULL)
                   {
                       MostrarElementos(ListaAux,0,ListaAux->len(ListaAux));
                   }
                   else
                    printf("No hay nada para mostrar\n");
                    system("pause");
                    break;
                case 3:
                    MostrarElementos(ListaEmpleados,0,ListaEmpleados->len(ListaEmpleados));
                    break;
                case 4:
                    ListaAux=al_map(ListaEmpleados, CalcularSalary);
                    if(ListaEmpleados!=NULL )
                    MostrarElementosconSalario(ListaEmpleados,0,ListaEmpleados->len(ListaEmpleados));
                    else
                        printf("Nada para mostrar\n");
                    break;
                case 0:
                    seguir='n';
                    break;
            }//FIN switch
        }//fin while




            }//fin if(ListaAlumnos !=NULL)
    return 0;
}
