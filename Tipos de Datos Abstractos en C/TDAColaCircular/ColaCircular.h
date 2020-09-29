#ifndef COLACIRCULAR_H_INCLUDED
#define COLACIRCULAR_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define minimo(x,y)  ((x) <= (y) ? (x) : (y) )

typedef struct sNodo
{
    void            *info;
    unsigned        tamInfo;
    struct sNodo    *sig;
}tNodo;

typedef struct
{
    tNodo *pri;
    tNodo *ult;
}tCola;


int colaLlena(const tCola *p,unsigned cantBytes);
int ponerEnCola(tCola *p, const void *d, unsigned cantBytes);
int verPrimeroCola(const tCola *p, void *d, unsigned cantBytes);
void vaciarCola(tCola *p);
int sacarDeCola(tCola *p, void *d, unsigned cantBytes);





#endif // COLACIRCULAR_H_INCLUDED
