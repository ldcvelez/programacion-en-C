#include "TDALista.h"

int generarArchivo(const char *nombre)
{
    t_alumno alu[5]={{'A',"Jose Gomez",24,{31,01,2002}},
                    {'F',"Juan Gil",20,{05,05,2005}},
                    {'R',"Victor Zapata",19,{15,06,2003}},
                    {'W',"Ana Luz",18,{28,02,1995}},
                    {'L',"Delfi Pignatiello",20,{16,02,1999}},
                    };
     FILE *fp;
     fp=fopen(nombre,"wb");

     if(fp==NULL)
     {
         printf("Error en la apertura del archivo.\n");
         return -1;
     }

     fwrite(alu,sizeof(alu),1,fp);
     fclose(fp);
     return 1;
}

int comparacion(const t_info *d1,const t_info *d2)
{
    return d1->edad-d2->edad;
}

int procesarArchivo(const char *nombre, t_lista *l)
{
    t_alumno alu;
    FILE *fp;
    fp=fopen(nombre,"rb");

     if(fp==NULL)
     {
         printf("Error en la apertura del archivo.\n");
         return -1;
     }

    fread(&alu,sizeof(t_alumno),1,fp);

    while(!feof(fp))
    {
        ///insertarAlInicio(l,&alu);
        insertarEnOrden(l,&alu,comparacion);
        fread(&alu,sizeof(t_alumno),1,fp);
    }

    fclose(fp);

    return 1;
}


void crearLista(t_lista *l)
{
    *l=NULL;
}


int insertarAlInicio(t_lista *l,t_info *d)
{
    t_nodo *nue;

    nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(nue==NULL)
    {
        printf("No hay mas memoria.\n");
        return -1;
    }

    nue->info=*d;
    nue->sig=*l;
    *l=nue;
    return 1;
}

void recorrerLista(const t_lista *l,void (*mostrar)(const t_info *))
{
    while(*l)
    {
        mostrar(&(*l)->info);
        l= &(*l)->sig;
    }
}


int insertarAlFinal(t_lista *l,t_info *d)
{
    while(*l)
    {
        l=&(*l)->sig;
    }

    *l=(t_nodo*)malloc(sizeof(t_nodo));

    if(l==NULL)
    {
        printf("No hay mas memoria.\n");
        return -1;
    }

    (*l)->info=*d;
    (*l)->sig=NULL;
    return 1;
}

int listaVacia(const t_lista *l)
{
    return *l==NULL;
}

int listaLlena(const t_lista *l)
{
    void *aux;

    aux=malloc(sizeof(t_nodo));

    free(aux);

    return aux==NULL;
}


void vaciarLista(t_lista *l)
{
    t_nodo *aux;

    while(*l)
    {
        aux=*l;
        *l=aux->sig;
        free(aux);
    }
}


int insertarEnOrden(t_lista *l,t_info *d,int (*comparacion)(const t_info *,const t_info *))
{
    t_nodo *nue;
    nue=(t_nodo*)malloc(sizeof(t_nodo));

    if(nue==NULL)
    {
        printf("No hay mas memoria.\n");
        return -1;
    }

    while(*l && (comparacion(&(*l)->info,d))<=0)///ORDEN ASCENDENTE
    {
        l=&(*l)->sig;
    }

//    if(comparacion(&(*l)->info,d)==0)
//        return -1;

    nue->info=*d;
    nue->sig=*l;
    *l=nue;
    return 1;
}


void eliminarPrimerNodo(t_lista *pl)
{
  t_nodo *  aux=*pl;
        *pl=aux->sig;
        free(aux);
}

void eliminarNodoDelMedio(t_lista *pl)
{
    t_nodo *l = pl;
    t_nodo *aux;

    t_nodo *au1 = pl;
    t_nodo *au2 = &(*pl)->sig;
    aux = &(*pl)->sig;
    t_nodo *au3 = aux->sig;

    strcpy(,au1->info->apyn);
    strcpy("%s",au2->info->apyn);
    strcpy("%s",au3->info->apyn);
//    aux = &(*pl)->sig;
//    printf("%s",aux->info->apyn);
//    l = aux->sig;
//    free(aux);
}

