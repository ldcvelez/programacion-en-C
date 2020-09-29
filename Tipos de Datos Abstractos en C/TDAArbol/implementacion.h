#ifndef IMPLEMENTACION_H_INCLUDED
#define IMPLEMENTACION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "primitivas.h"
int cargar_arbol(t_arbol *pa);
int cargar_arbol_ord_arch(t_arbol * pa);
void generar_archivo(t_arbol *pa);
void imprimir_arbol(t_arbol *pa);
void cantidad_hojas_arbol(const t_arbol* pa);
void posicion_dato (const t_arbol *pa,int dato);

#endif // IMPLEMENTACION_H_INCLUDED
