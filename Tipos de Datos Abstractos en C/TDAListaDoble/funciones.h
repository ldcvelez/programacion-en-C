#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char    dni[11];
    char    apYNom[31];
    int     codMat,
            calif;
} tFinal;


void mostrarFinal_MIO(const void *d, FILE *fp);


#endif // FUNCIONES_H_INCLUDED
