#include "Pila.h"
#define minimo( X , Y ) ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )


 void crearPila(tPila *p)
 {
    *p = NULL;
 }

 int pilaLlena(const tPila *p, unsigned cantBytes)
 {
     tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
     void *info = malloc(cantBytes);

     free(aux);
     free(info);
     return aux == NULL || info == NULL;
 }

 int ponerEnPila(tPila *p, const void *d, unsigned cantBytes)
 {
     tNodo *nue;

     if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||(nue->info = malloc(cantBytes)) == NULL)
     {
         free(nue);
         return 0;
     }
     memcpy(nue->info, d, cantBytes);
     nue->tamInfo = cantBytes;
     nue->sig = *p;
     *p = nue;
     return 1;
 }

 int verTope(const tPila *p, void *d, unsigned cantBytes)
 {
     if(*p == NULL)
        return 0;
     memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
     return 1;
 }

 int pilaVacia(const tPila *p)
{

}


int sacarDePila(tPila *p, void *d, unsigned cantBytes)
 {
     tNodo *aux = *p;

     if(aux == NULL)
        return 0;
     *p = aux->sig;
     memcpy(d, aux->info, minimo(cantBytes, aux->tamInfo));
     free(aux->info);
     free(aux);
     return 1;
}

void vaciarPila(tPila *p)
{
     while(*p)
     {
         tNodo *aux = *p;

         *p = aux->sig;
         free(aux->info);
         free(aux);
     }
 }

/**FORMA VIEJA**/
/*void crearPila(t_pila *p)
{
    *p=NULL;
}

int pilaVacia(const t_pila *p)
{
    return *p==NULL;
}


int pilaLlena(const t_pila *p)
{
    t_nodo *aux;

    aux=malloc(sizeof(t_nodo));
    free(aux);

    return aux==NULL;
}


int apilar(t_pila *p, t_info *d)
{
    t_nodo *nue;

    nue=(t_nodo*)malloc(sizeof(t_nodo));

    if(nue==NULL)
    {
        printf("No hay memoria.\n");
        return -1;
    }

    nue->info=*d;
    nue->sig=*p;
    *p=nue;
    return 1;
}

int desapilar(t_pila *p,t_info *d)
{
    if(*p==NULL)
    {
        printf("No hay nada que desapilar.\n");
        return -1;
    }

    t_nodo *aux;
    aux=*p;

    *d=aux->info;
    *p=aux->sig;

    free(aux);
    return 1;
}


int verTope(const t_pila *p,t_info *d)
{
    if(*p==NULL)
    {
        printf("La pila esta vacia.\n");
        return -1;
    }

    *d=(*p)->info;
    return 1;
}


void vaciarPila(t_pila *p)
{
    t_nodo *aux;

    while(*p)
    {
        aux=*p;
        *p=aux->sig;
        free(aux);
    }
}*/
