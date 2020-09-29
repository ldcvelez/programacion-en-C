#ifndef TDALISTA_H_INCLUDED
#define TDALISTA_H_INCLUDED
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

 typedef t_nodo* t_lista;


 int generarArchivo(const char *);
 int procesarArchivo(const char *, t_lista *);

 void crearLista(t_lista *);
 int listaVacia(const t_lista *);
 int listaLlena(const t_lista *);
 void vaciarLista(t_lista *);
 int insertarAlInicio(t_lista *, t_info *);
 int insertarAlFinal(t_lista *,t_info *);
 int insertarEnOrden(t_lista *,t_info *,int (*)(const t_info *,const t_info *));
 void recorrerLista(const t_lista *, void (*)(const t_info *));

#endif // TDALISTA_H_INCLUDED
