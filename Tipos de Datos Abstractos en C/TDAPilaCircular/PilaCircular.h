#ifndef PILACIRCULAR_H_INCLUDED
#define PILACIRCULAR_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define minimo(x,y)  ((x) <= (y) ? (x) : (y) )

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;
typedef tNodo * tPila;

void crearPila(tPila *p);
int pilaLlena(const tPila *p, unsigned cantBytes);
int ponerEnPila(tPila *p, const void *d,unsigned cantBytes);
int verTope(const tPila *p, void *,unsigned cantBytes);
int pilaVacia(const tPila *p);
int sacarDePila(tPila *p,void *d,unsigned cantBytes);
void vaciarPila(tPila *p);


#endif // PILACIRCULAR_H_INCLUDED



