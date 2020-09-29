#include "TDA.h"

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

int procesarArchivo(const char *nombre, t_pila *p)
{
    t_alumno alu;
    FILE *fp;
    fp=fopen(nombre, "rb");

    if(fp==NULL)
    {
        printf("Error en la apertura del archivo.\n");
        return -1;
    }

    fread(&alu,sizeof(t_alumno),1,fp);

    while(!feof(fp))
    {
        apilar(p,&alu);
        fread(&alu,sizeof(t_alumno),1,fp);
    }

    return 1;
}


void crearPila(t_pila *p)
{
    *p=NULL;
}


int apilar(t_pila *p,t_info *d)
{
    t_nodo *nue;
    nue=(t_nodo*)malloc(sizeof(t_nodo));

    if(nue==NULL)
        return -1;

    nue->info=*d;
    nue->sig=*p;
    *p=nue;
    return 1;
}


int verTope(const t_pila *p, t_info *d)
{
    if(*p==NULL)
    {
        printf("La pila esta vacia.\n");
        return -1;
    }

    *d= (*p)->info;
    return 1;
}


int desapilar(t_pila *p, t_info *d)
{
    if(*p==NULL)
    {
        printf("La pila esta vacia.\n");
        return -1;
    }

    t_nodo *aux;
    aux=*p;

    *d=aux->info;
    *p=aux->sig;

    free(aux);
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

}


int pilaVacia(const t_pila *p)
{
    return *p==NULL;
}

int pilaLlena(const t_pila *p)
{
    void *aux;

    aux=malloc(sizeof(t_nodo));

    free(aux);

    return aux==NULL;
}






