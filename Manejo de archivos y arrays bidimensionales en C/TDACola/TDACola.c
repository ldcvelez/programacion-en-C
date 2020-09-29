#include "TDACola.h"

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


int procesarArchivo(const char *nombre, t_cola *pc)
{
    t_alumno alu;
    FILE *fp;
    fp=fopen(nombre,"rb");

    if(fp==NULL)
    {
        printf("Error al abrir el archivo.\n");
        return -1;
    }

    fread(&alu,sizeof(t_alumno),1,fp);

    while(!feof(fp))
    {
        acolar(pc,&alu);
        fread(&alu,sizeof(t_alumno),1,fp);
    }

    fclose(fp);
    return 1;
}




void crearCola(t_cola *pc)
{
    pc->frente=NULL;
    pc->fondo=NULL;
}

int acolar(t_cola *pc,t_info *d)
{
    t_nodo *nue;
    nue=(t_nodo *)malloc(sizeof(t_nodo));

    if(nue==NULL)
    {
        printf("No hay memoria.\n");
        return -1;
    }

    nue->info=*d;
    nue->sig=NULL;

    if(pc->fondo) ///si no es nulo
    {
        pc->fondo->sig=nue;
    }else
    {
        pc->frente=nue;
    }
    pc->fondo=nue;
    return 1;
}


int desacolar(t_cola *pc,t_info *d)
{
    if(pc->frente == NULL)
    {
        printf("La cola esta vacia.\n");
        return -1;
    }

    t_nodo *aux;

    aux=pc->frente;
    *d=aux->info;
    pc->frente=aux->sig;

    if(pc->frente == NULL)
    {
        pc->fondo=NULL;
    }
    free(aux);
    return 1;
}

int verFrente(const t_cola *pc, t_info *d)
{
    if(pc->frente == NULL)
    {
        printf("\nLa cola esta vacia.\n");
        return -1;
    }

    *d=pc->frente->info;
    return 1;
}


int verFondo(const t_cola *pc,t_info *d)
{
    if(pc->fondo==NULL)
    {
        printf("\nLa cola esta vacia.\n");
        return -1;
    }

    *d= pc->fondo->info;
    return 1;
}


int colaLlena(const t_cola *pc)
{
    t_nodo *aux;

    aux=malloc(sizeof(t_nodo));

    free(aux);

    return aux==NULL;
}


int colaVacia(const t_cola *pc)
{
    return pc->frente==NULL;
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



