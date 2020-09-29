#include "TDA.h"

int main()
{
    t_alumno alu;
    t_pila pila;
    char nombreArch[51]="C:\\Users\\leone\\OneDrive\\Escritorio\\AlumnosPila";

    generarArchivo(nombreArch);
    crearPila(&pila);

    procesarArchivo(nombreArch,&pila);

    desapilar(&pila,&alu);
    puts("Expulsado: ");
    printf("Nombre :%s\n",alu.apyn);
    printf("Edad :%d\n\n",alu.edad);

    ///vaciarPila(&pila);

    verTope(&pila,&alu);
    printf("Nombre :%s\n",alu.apyn);
    printf("Edad :%d\n",alu.edad);
    return 0;
}
