#include "Lista.h"
#define minimo( X , Y ) ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )

 void crearLista(tLista *p)
 {
    *p = NULL;
 }

 int listaVacia(const tLista *p)
 {
    return *p == NULL;
 }

 int listaLlena(const tLista *p, unsigned cantBytes)
 {
     tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
     void *info = malloc(cantBytes);

     free(aux);
     free(info);
    return aux == NULL || info == NULL;
 }

 void vaciarLista(tLista *p)
 {
     while(*p)
     {
         tNodo *aux = *p;
         *p = aux->sig;
         free(aux->info);
         free(aux);
     }
 }


 int ponerAlComienzo(tLista *p, const void *d, unsigned cantBytes)
 {
     tNodo *nue;

     if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(cantBytes)) == NULL)
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


 int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes)
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

 int verPrimeroLista(const tLista *p, void *d, unsigned cantBytes)
 {
     if(*p == NULL)
        return 0;
     memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
     return 1;
 }


 int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes)
 {
     tNodo *nue;

     while(*p)
        p = &(*p)->sig;

     if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(cantBytes)) == NULL)
     {
         free(nue);
         return 0;
     }
     memcpy(nue->info, d, cantBytes);
     nue->tamInfo = cantBytes;
     nue->sig = NULL;
     *p = nue;
     return 1;
 }

 int sacarUltimoLista(tLista *p, void *d, unsigned cantBytes)
 {
     if(*p == NULL)
        return 0;
     while((*p)->sig)
        p = &(*p)->sig;
     memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
     free((*p)->info);
     free(*p);
     *p = NULL;
     return 1;
 }


 int verUltimoLista(const tLista *p, void *d, unsigned cantBytes)
 {
     if(*p == NULL)
        return 0;
     while((*p)->sig)
        p = &(*p)->sig;
     memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
     return 1;
 }





/**FORMA VIEJA*/
/*void crearLista(t_lista *pl)
{
    *pl=NULL;
}


int listaLlena(t_lista *pl)
{
    t_nodo *aux;

    aux=(t_nodo*)malloc(sizeof(t_nodo));
    free(aux);

    return aux==NULL;
}


int listaVacia(t_lista *pl)
{
    return *pl==NULL;
}


void vaciarLista(t_lista *pl)
{
    t_nodo *aux;

    while(*pl)
    {
        aux=*pl;
        *pl=aux->sig;
        free(aux);
    }
}


int insertarAlInicio(t_lista *pl,t_info *d)
{
    t_nodo *nue;
    nue=(t_nodo *)malloc(sizeof(t_nodo));

    if(nue==NULL)
    {
        printf("No hay memoria.\n");
        return -1;
    }

    nue->info=*d;
    nue->sig=*pl;
    *pl=nue;
    return 1;
}



int insertarAlFinal(t_lista *pl, t_info *d)
{
  while(*pl)
    {
        pl=&(*pl)->sig;
    }

    *pl=(t_nodo*)malloc(sizeof(t_nodo));

    if(pl==NULL)
    {
        printf("No hay mas memoria.\n");
        return -1;
    }

    (*pl)->info=*d;
    (*pl)->sig=NULL;
    return 1;
}


int insertarEnOrden(t_lista *pl,t_info *d,int (*comparacion)(const t_info *,const t_info *))
{
//    t_nodo *nue;
//    nue=(t_nodo*)malloc(sizeof(t_nodo));
//
//    if(nue==NULL)
//    {
//        printf("No hay mas memoria.\n");
//        return -1;
//    }
//
//
//    while(*pl && (comparacion(&(*pl)->info,d))<=0)
//    {
//        pl=&(*pl)->sig;
//    }
//
//    if(*pl && comparacion(&(*pl)->info,d) == 0)
//    {
//        printf("Ya existe en la lista.\n");
//        return -1;
//    }
//
//    nue->info=*d;
//    nue->sig=*pl;
//    *pl=nue;
//    return 1;

   while(*pl && comparacion(&(*pl)->info,d)<0)///ordena ascendente
    {                                     ///0 si son iguales,1 si el primero es mayor y -1 si e; primero es menor
        pl=&(*pl)->sig;
    }

    if( *pl && comparacion(&(*pl)->info,d)==0)
    {
        printf("Ya existe en la lista.\n\n");
        return -1;
    }

    t_nodo *nue;
    nue=(t_nodo *)malloc(sizeof(t_nodo));

    if(nue==NULL)
    {
        printf("No hay mas memoria.\n");
        return 0;
    }

    nue->sig=*pl;
    *pl=nue;
    nue->info=*d;
    return 1;
}


void recorrerLista(const t_lista *pl,void (*mostrar)(const t_info *d))
{
    while(*pl)
    {
        mostrar(&(*pl)->info);
        pl=&(*pl)->sig;
    }
}*/








