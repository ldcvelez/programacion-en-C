#include "Lista.h"

void mostrar(const t_info *d)
{
    printf("Nombre: %s\n",d->apyn);
    printf("Edad: %d\n\n",d->edad);
}

int comparacion(const t_info *d1, const t_info *d2)
{
    return d1->edad - d2->edad;
}

int main()
{
    t_lista lista;
    t_empleado emp,emp2,emp3,emp4,emp5,emp6;

    strcpy(emp.apyn,"Pedro");
    emp.edad=30;

    strcpy(emp2.apyn,"Juanes");
    emp2.edad=33;

    strcpy(emp4.apyn,"Maria");
    emp4.edad=24;

    strcpy(emp3.apyn,"Victoria");
    emp3.edad=20;

    strcpy(emp5.apyn,"Sebas");
    emp5.edad=25;

    strcpy(emp6.apyn,"Ana");
    emp6.edad=24;

    crearLista(&lista);
    insertarAlFinal(&lista,&emp3);
    insertarAlInicio(&lista,&emp);
    insertarAlInicio(&lista,&emp4);
    insertarAlInicio(&lista,&emp5);
    insertarAlFinal(&lista,&emp2);
    insertarEnOrden(&lista,&emp6,comparacion);
    recorrerLista(&lista,mostrar);

    return 0;
}
