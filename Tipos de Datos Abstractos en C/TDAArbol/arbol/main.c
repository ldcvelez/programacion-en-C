#include <stdio.h>
#include <stdlib.h>
#include "implementacion.h"

int main()
{
    t_arbol pa;
    int cant_nodos;
    int altura;
    cargar_arbol(&pa);
    puts("\n\n\n\n");
    imprimir_arbol(&pa);
    cantidad_hojas_arbol(&pa);
    posicion_dato(&pa,0);
    cant_nodos=contar_nodos(&pa);
    printf("\n la cantidad de nodos total es %d",cant_nodos);
    altura=altura_arbol(&pa);
    printf("\n la altura del arbol es: %d", altura);
    cant_nodos=contar_hasta_nivel_inclusive(&pa,2);
    printf("\n la cantidad de nodos hasta el nivel dado (inclusive) es %d",cant_nodos);
    cant_nodos=contar_hasta_nivel_no_inclusive(&pa,2);
    printf("\n la cantidad de nodos hasta llegar al nivel dado es %d",cant_nodos);
    cant_nodos=contar_nodos_con_hijos_izq(&pa);
    printf("\n la cantidad de nodos que tienen hijos izquierdos es %d",cant_nodos);
    cant_nodos=contar_nodos_con_hijos_der(&pa);
    printf("\n la cantidad de nodos que tienen hijos derechos es es %d",cant_nodos);
    cant_nodos=contar_nodos_con_hijos_solo_der(&pa);
    printf("\n la cantidad de nodos con hijos solo por derecha es %d",cant_nodos);
    cant_nodos=contar_nodos_con_hijos_solo_izq(&pa);
    printf("\n la cantidad de nodos con hijos solo por izquierda es %d",cant_nodos);
    return 0;
}
