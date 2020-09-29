#include "Cola.h"
#define minimo( X , Y ) ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )

 void crearCola(tCola *p)
 {
     p->pri = NULL;
     p->ult = NULL;
 }

 int colaLlena(const tCola *p, unsigned cantBytes)
 {
     tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
     void *info = malloc(cantBytes);
     free(aux);
     free(info);
     return aux == NULL || info == NULL;
 }


 int ponerEnCola(tCola *p, const void *d, unsigned cantBytes)
 {
    tNodo *nue = (tNodo *) malloc(sizeof(tNodo));

     if(nue == NULL || (nue->info = malloc(cantBytes)) == NULL)
     {
         free(nue);
         return 0;
     }

    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
     if(p->ult)
        p->ult->sig = nue;
     else
         p->pri = nue;
         p->ult = nue;
     return 1;
 }


 int verPrimeroCola(const tCola *p, void *d, unsigned cantBytes)
 {
     if(p->pri == NULL)
        return 0;
     memcpy(d, p->pri->info, minimo(cantBytes, p->pri->tamInfo));
     return 1;
 }


 int colaVacia(const tCola *p)
 {
    return p->pri == NULL;
 }


 int sacarDeCola(tCola *p, void *d, unsigned cantBytes)
 {
     tNodo *aux = p->pri;
     if(aux == NULL)
        return 0;
     p->pri = aux->sig;
     memcpy(d, aux->info, minimo(aux->tamInfo, cantBytes));
     free(aux->info);
     free(aux);

     if(p->pri == NULL)
        p->ult = NULL;
     return 1;
 }

 void vaciarCola(tCola *p)
 {
     while(p->pri)
     {
         tNodo *aux = p->pri;
         p->pri = aux->sig;
         free(aux->info);
         free(aux);
     }
     p->ult = NULL;
 }



/**FORMA VIEJA**/
/*void crearCola(t_cola *pc)
{
    pc->frente=NULL;
    pc->fondo=NULL;
}


int colaVacia(const t_cola *pc) ///devuelve 1 si esta vacia, 0 si no esta vacia
{
    //printf("%d",pc->frente ==NULL);
    return pc->frente ==NULL;
}

int colaLlena(const t_cola *c) ///devuelve 0 si no esta llena, 1 si esta llena
{
    t_nodo *aux;

    aux=malloc(sizeof(t_nodo));

    free(aux);
    //printf("%d",aux==NULL);
    return aux==NULL;
}


int acolar(t_cola *pc, t_info *d)
{
   t_nodo *nue;
   nue=(t_nodo*)malloc(sizeof(t_nodo));

   if(nue==NULL)
   {
       printf("No hay mas memoria.\n");
       return -1;
   }

   nue->info=*d;
   nue->sig=NULL;

   if(pc->frente) ///si no es nulo
   {
       pc->fondo->sig=nue;

   }else{

       pc->frente=nue;
   }

    pc->fondo=nue;
    return 1;
}


int desacolar(t_cola *pc,t_info *d)
{
    if(pc->frente==NULL)
    {
        printf("La cola ya esta vacia.\n");
        return -1;
    }

    t_nodo *aux;

    aux=pc->frente;
    *d=aux->info;
    pc->frente=aux->sig;
    free(aux);

    if(pc->frente==NULL)
    {
        pc->fondo=NULL;
    }

    return 1;
}



void vaciarCola(t_cola *pc)
{
    t_nodo *aux;

    while(pc->frente)
    {
        aux=pc->frente;
        pc->frente=aux->sig;
        free(aux);
    }

    pc->fondo=NULL;
}


int verFondo(const t_cola *pc, t_info *d)
{
    if(pc->fondo==NULL)
    {
        printf("La cola esta vacia.\n");
        return -1;
    }

    *d=pc->fondo->info;
    return 1;
}

int verFrente(const t_cola *pc, t_info *d)
{
    if(pc->frente==NULL)
    {
        printf("La cola esta vacia.\n");
        return -1;
    }

    *d=pc->frente->info;
    return 1;
}*/
