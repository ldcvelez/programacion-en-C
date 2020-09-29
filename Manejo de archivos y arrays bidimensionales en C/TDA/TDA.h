#ifndef TDA_H_INCLUDED
#define TDA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
    {
        int d,m,a;
    }t_fecha;

typedef struct
    {
        char legajo;
        char apyn[21];
        int edad;
        t_fecha fNac;
    }t_alumno;

 typedef t_alumno t_info;

 typedef struct s_nodo
    {
       t_info info;
       struct s_nodo *sig;
    }t_nodo;

typedef t_nodo* t_pila;

void crearPila(t_pila *);
int apilar(t_pila *, t_info *);
int verTope(const t_pila *,t_info *);
int desapilar(t_pila *,t_info *);
void vaciarPila(t_pila *);
int pilaLlena(const t_pila *);
int pilaVacia(const t_pila *);

int generarArchivo(const char *);
int procesarArchivo(const char *,t_pila *);

#endif // TDA_H_INCLUDED
