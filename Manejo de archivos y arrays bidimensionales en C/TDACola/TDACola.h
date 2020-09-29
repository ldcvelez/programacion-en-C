#ifndef TDACOLA_H_INCLUDED
#define TDACOLA_H_INCLUDED
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

typedef struct
    {
            t_nodo *frente;
            t_nodo *fondo;
    }t_cola;

void crearCola(t_cola *);
int acolar(t_cola *,t_info *);
int desacolar(t_cola *,t_info *);
int verFrente(const t_cola *,t_info *);
int verFondo(const t_cola *,t_info *);
int colaLlena(const t_cola *);
int colaVacia(const t_cola *);
void vaciarCola(t_cola *pc);


int generarArchivo(const char *);
int procesarArchivo(const char *,t_cola *);
#endif // TDACOLA_H_INCLUDED
