#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#define TIENE_ENCABEZADO_ARCHIVO 0
#define CANTIDAD_CAMPOS_ARCHIVO 4

int cargarDesdeArchivo(ArrayList *this,const char* nombre);
int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee);





#endif // ARCHIVOS_H_INCLUDED
