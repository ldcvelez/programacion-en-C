/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/


/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
#include <string.h>
#include <stdlib.h>
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/

tNodo* buscarMenorYSacarDeLista(tLista *p, int (*comparar)(const void *, const void *));
void ponerEnListaAntesDe(tLista *nuevaLista, tNodo *men, tLista *p);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarMovim_MIO(const void *d, FILE *fp)
{
    tMovi *mov = (tMovi*)d;
    fprintf(fp,"%s  %8.2f\n",mov->ctaCte,mov->saldo);
}


int compararMovim_MIO(const void *d1, const void *d2)
{
    tMovi *mov1 = (tMovi*)d1;
    tMovi *mov2 = (tMovi*)d2;

    char a1[20],a2[20];
    strcpy(a1,mov1->ctaCte);
    strcpy(a2,mov2->ctaCte);

    return strcmp(mov1->ctaCte,mov2->ctaCte);
}


int esCtaCte002_MIO(const void *d)
{
    tMovi *mov = (tMovi*)d;
    int c = strlen(mov->ctaCte);

    if(*(mov->ctaCte + c - 1) == '2')
        return 1;
    return 0;
}


int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                      const void *ori, unsigned tamOri)
{
    tMovi **p1 = (tMovi**)dest;
    tMovi *p2 = (tMovi*)ori;
    (*p1)->saldo += p2->saldo;
    return 1;
}


void mostrarTotal_MIO(const void *d, FILE *fp)
{
    const tMovi *mov = (const tMovi *) d;

    fprintf(fp, " Total cliente:  %8.2f\n\n", mov->saldo);
}


/**//* para el TDA LISTA                                                  *//**/

int mostrarLista_MIO(const tLista *p,void (*mostrar)(const void *, FILE *), FILE *fp)
{
    int cant = 0;

    fprintf(fp,"Nro Cuenta Banc   Importe\n");
    while(*p)
    {
        mostrar((*p)->info,fp);
        p = &(*p)->sig;
        cant++;
    }

    return cant;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    tNodo *men;
    tLista *ini = p;
    tLista nuevaLista = NULL;

    while((*ini)->sig)
    {
        men = buscarMenorYSacarDeLista(ini, comparar);

        if(men == *ini)
            ini = &(*ini)->sig;
        else
           ponerEnListaAntesDe(&nuevaLista, men, ini);

    }

    *p = nuevaLista;
}

void ponerEnListaAntesDe(tLista *nuevaLista, tNodo *men, tLista *p)
{
    if(*nuevaLista == NULL)
    {
        *nuevaLista = men;
        (*nuevaLista)->sig = *p;
        return;
    }

    while((*nuevaLista)->sig != *p)
        nuevaLista = &(*nuevaLista)->sig;

    men->sig = *p;
    (*nuevaLista)->sig = men;
}

tNodo* buscarMenorYSacarDeLista(tLista *p, int (*comparar)(const void *, const void *))
{
    tNodo   *pmen = *p,
            *ant = *p,
            *ini = *p;

    while((*p)->sig)
    {
        if(comparar((*p)->sig->info, pmen->info) < 0)
        {
            pmen = (*p)->sig;
            ant = *p;
        }

        p = &(*p)->sig;
    }

    if(pmen != ant)
        ant->sig = pmen->sig;

    p = &ini;

    return pmen;
}

int eliminarMostrarYMostrarSubTot_MIO(tLista *p, FILE *fpPant,
                                      int comparar(const void *, const void *),
                                      int comparar2(const void *d),
                                      int acumular(void **, unsigned *,
                                                   const void *, unsigned),
                                      void mostrar(const void *, FILE *),
                                      void mostrar2(const void *, FILE *))
{
    tNodo* ant=*p,*aux;
    int cant=0;


    if(!*p)
        return 0;

    while(*p)
    {
        if(comparar2((*p)->info))
        {
            fprintf(fpPant,"Nro Cuenta Banc   Importe\n");
            mostrar((*p)->info,fpPant);

            while((*p)->sig && (comparar((*p)->info,(*p)->sig->info))==0)///Me fijo que el siguiente no sea nulo y sea el mismo cliente.
            {
                mostrar((*p)->sig->info,fpPant);

                acumular(&(*p)->info,&(*p)->tamInfo,(*p)->sig->info,(*p)->sig->tamInfo);

                aux = (*p)->sig;///Elimnar nodo

                (*p)->sig = aux->sig;

                free(aux->info);

                free(aux);///Elimnar nodo
                cant++;///Aumento el contador de eliminados
            }
            mostrar2((*p)->info,fpPant);

            aux = *p;///Guardo en aux el nodo a eliminar.Como ya cambio de cliente.
            ant->sig = aux->sig;///Avanzo ant y queda en la misma posición que p
            *p = aux->sig;
            free(aux->info);///Libero lo que quedaba en p
            free(aux);
            cant++;///Aumento el contador de eliminados
        }
        else
          {
            ant=*p;///Le asigno la dirección de p
            p = &(*p)->sig;///Avanzo el puntero.
          }
    }

    return cant;///Retorno cantidad.
}


int  vaciarListaYMostrar_MIO(tLista *p,
                             void (*mostrar)(const void *, FILE *), FILE *fp)
{
    tNodo * vaciar;
    int cant = 0;

    while(*p)
    {
        vaciar = *p;

        cant++;
        *p = vaciar->sig;

        if(mostrar && fp)
        {
            mostrar(vaciar->info,fp);
        }

        free(vaciar->info);
        free(vaciar);
    }

    return cant;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

