#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

 typedef struct sNodo
 {
     void *info;
     unsigned tamInfo;
     struct sNodo *sig;
 } tNodo;

 typedef struct
 {
     tNodo  *pri,
            *ult;
 } tCola;

 void crearCola(tCola *p);

 int colaLlena(const tCola *p, unsigned cantBytes);

 int ponerEnCola(tCola *p, const void *d, unsigned cantBytes);

 int verPrimeroCola(const tCola *p, void *d, unsigned cantBytes);

 int colaVacia(const tCola *p);

 int sacarDeCola(tCola *p, void *d, unsigned cantBytes);

 void vaciarCola(tCola *p);

/*void crearCola(t_cola *);
int colaVacia(const t_cola *);
int colaLlena(const t_cola *);
int acolar(t_cola *, t_info *);
int desacolar(t_cola *, t_info *);
void vaciarCola(t_cola *);
int verFondo(const t_cola *,t_info *);
int verFrente(const t_cola *,t_info *);*/




#endif // COLA_H_INCLUDED
