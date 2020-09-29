#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef struct sNodo
 {
     void *info;
     unsigned tamInfo;
     struct sNodo *sig;
 } tNodo;
 typedef tNodo *tPila;

 void crearPila(tPila *p);
 int pilaLlena(const tPila *p, unsigned cantBytes);
 int ponerEnPila(tPila *p, const void *d, unsigned cantBytes);
 int verTope(const tPila *p, void *d, unsigned cantBytes);
 int pilaVacia(const tPila *p);
 int sacarDePila(tPila *p, void *d, unsigned cantBytes);
 void vaciarPila(tPila *p);


/**FORMA VIEJA*/
/*typedef struct{
    int dni;
    char apyn[31];
}t_empleado;

typedef t_empleado t_info;

typedef struct s_nodo{
    t_info info;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo *t_pila;

void crearPila(t_pila *);
int pilaVacia(const t_pila *);
int pilaLlena(const t_pila *);
int apilar(t_pila *, t_info *);
int desapilar(t_pila *,t_info *);
int verTope(const t_pila *,t_info *d);
void vaciarPila(t_pila *);*/

#endif // PILA_H_INCLUDED
