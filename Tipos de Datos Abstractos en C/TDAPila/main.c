#include "Pila.h"

int main()
{
    t_pila pila;

    crearPila(&pila);
    t_empleado empleado,empleado2;

    strcpy(empleado.apyn,"Juan Perez");
    empleado.dni=34;

    if(pilaVacia(&pila))
        {printf("La pila esta vacia.\n");}
        else
        {printf("La pila no esta vacia.\n");}

     if(pilaLlena(&pila))
        {printf("La pila esta llena.\n");}
        else
        {printf("La pila no esta llena.\n");}

    apilar(&pila,&empleado);
    //desapilar(&pila,&empleado2);
    //vaciarPila(&pila);
    verTope(&pila,&empleado2);
    printf("%d",empleado2.dni);


    return 0;
}
