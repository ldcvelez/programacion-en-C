#ifndef ARCHIVOS1_H_INCLUDED
#define ARCHIVOS1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int d,m,a;
}t_fecha;


typedef struct
{
    int nlegajo;
    char apyn[21];
    int edad;
    t_fecha fNac;
}t_alumno;

int generarArchivoTXT(t_alumno *,const char *,int );
int generarArchivoBIN(const char *,const char *);
int leerArchivoBIN(const char *);
int leerArchivoTXT(const char *);
int mergeoArchivos(const char *,const char *,const char *);
#endif // ARCHIVOS1_H_INCLUDED
