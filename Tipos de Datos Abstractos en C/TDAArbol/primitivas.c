#include "primitivas.h"
int comp_int (const t_info *a, const t_info *b)
{
    return *a-*b;
}
void print (t_info *info)
{
    printf("%d", *info);
}
void imprimir_espacios(int offset)
{
    int i;
    for (i=0; i<offset; i++)
    {
        printf("\t");
    }
}
/// crear, validar lleno y vacio.

void crear_arbol(t_arbol *pa)
{
    *pa=NULL;
}

int arbol_vacio(const t_arbol *pa)
{
    return *pa==NULL;
}

int arbol_lleno(const t_arbol *pa)
{
    t_nodoa *aux=(t_nodoa *)malloc(sizeof (t_nodoa));
    free(aux);
    return aux==NULL;
}

/// Insertar en orden (hecho en clase)

int insertar_arbol_enorden(t_arbol *pa,const t_info *dato,t_cmp comp)
{
    int cmp;
    if(*pa)
    {
        if((cmp=comp(dato,&(*pa)->info))>0)
            return insertar_arbol_enorden(&(*pa)->der,dato,comp);
        if(cmp<0)
            return insertar_arbol_enorden(&(*pa)->izq,dato,comp);
        else
            return DUPLICADO;
    }
    *pa=(t_nodoa *)malloc(sizeof(t_nodoa));
    if(*pa==NULL)
        return SIN_MEM;
    (*pa)->info=*dato;
    (*pa)->izq=(*pa)->der=NULL;
    return TODO_BIEN;
}
void mostrar_arbol(t_arbol *pa,int offset)
{
    if(!*pa)
        return;
    mostrar_arbol(&(*pa)->der,offset+1);    // DER
    imprimir_espacios((offset));
    print(&(*pa)->info);                   // RAIZ
    printf("\n");
    mostrar_arbol(&(*pa)->izq,offset+1);    // IZQ

}
void cargar_archivo_preorden(t_arbol*pa, FILE** pf)
{
    if(!*pa)
        return;
    fwrite(&(*pa)->info,sizeof(t_info),1,*pf);
    cargar_archivo_preorden(&(*pa)->izq,pf);
    cargar_archivo_preorden(&(*pa)->der,pf);
}
int contar_hojas(const t_arbol *pa)
{
    if(!*pa)
        return ARBOL_VACIO;
    if(ES_HOJA)
        return 1;
    return contar_hojas(&(*pa)->der)+contar_hojas(&(*pa)->izq);
}
int contar_nodos (const t_arbol* pa)
{
    if(!*pa)
        return 0;
    if(ES_HOJA)
        return 1;
    return contar_nodos(&(*pa)->izq)+contar_nodos(&(*pa)->der)+1;

}
t_arbol *buscar_nodo(const t_arbol *pa,t_info *dato, t_cmp cmp)
{
    int comp;
    if(!*pa)
        return NULL;
    if((comp=cmp(dato,&(*pa)->info))==0)
        return (t_arbol*)pa; //casteo porque al ser const *pa no puedo retornarlo.
    if(comp<0)
        return buscar_nodo(&(*pa)->izq,dato,cmp);
    else
        return buscar_nodo(&(*pa)->der,dato,cmp);
}
int altura_arbol(const t_arbol *pa)
{
    int ai;
    int ad;
    if(!*pa)
        return 0;
    if(ES_HOJA)
        return 1;
    ai = altura_arbol(&(*pa)->izq);
    ad = altura_arbol(&(*pa)->der);
    return (MAYOR(ad,ai))+1;
}
int contar_nodos_con_hijos_izq(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    if(ES_HOJA)
        return 0;
    if((*pa)->izq)
        return contar_nodos_con_hijos_izq(&(*pa)->izq)+contar_nodos_con_hijos_izq(&(*pa)->der)+1;

}
int contar_nodos_con_hijos_der(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    if(ES_HOJA)
        return 0;
    if((*pa)->der)
        return contar_nodos_con_hijos_der(&(*pa)->izq)+contar_nodos_con_hijos_der(&(*pa)->der)+1;

}
int contar_hasta_nivel_inclusive(const t_arbol *pa,int n)
{
    if(!*pa||n<0)
        return 0;
    if(ES_HOJA)
        return 1;
    return contar_hasta_nivel_inclusive(&(*pa)->izq,n-1)+contar_hasta_nivel_inclusive(&(*pa)->der,n-1)+1;
}
int contar_hasta_nivel_no_inclusive(const t_arbol *pa,int n)
{
    if(!*pa||n==0)
        return 0;
    if(ES_HOJA)
        return 1;
    return contar_hasta_nivel_no_inclusive(&(*pa)->izq,n-1)+contar_hasta_nivel_no_inclusive(&(*pa)->der,n-1)+1;
}
int contar_nodos_con_hijos_solo_izq(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    if(ES_HOJA)
        return 0;
    if((*pa)->izq)
        return contar_nodos_con_hijos_solo_izq(&(*pa)->izq)+1;
}
int contar_nodos_con_hijos_solo_der(const t_arbol *pa)
{
    if(!*pa)
        return 0;
    if(ES_HOJA)
        return 0;
    if((*pa)->izq)
        return contar_nodos_con_hijos_solo_der(&(*pa)->der)+1;
}

int podarArbolAltura(t_arbol *pa,int altura)
{
    if(!*pa || altura<0)
        return 0;


    podarArbolAltura(&(*pa)->izq,altura-1);
    podarArbolAltura(&(*pa)->der,altura-1);
    if (altura==0)
    {
        eliminar_arbol(&(*pa)->der);
        eliminar_arbol(&(*pa)->izq);
    }
    return 1;
}

int  eliminar_arbol(t_arbol *pa)
{
    if(!*pa)
        return 0;

    eliminar_arbol(&(*pa)->der);
    eliminar_arbol(&(*pa)->izq);
    free(*pa);
    *pa=NULL;
    return 1;
}
void podar_hojas_desde_nivel(t_arbol *pa,int n)
{
    if(!*pa)
        return;
    if(n==0)
    {
        podar_hojas_arbol(pa);
        return;
    }
    podar_hojas_desde_nivel(&(*pa)->izq,n-1);
    podar_hojas_desde_nivel(&(*pa)->der,n-1);
}

void podar_hojas_arbol(t_arbol *pa)
{
    if(!*pa)
        return;
    if(ES_HOJA)
    {
        free(*pa);
        *pa=NULL;
        return;
    }
    podar_hojas_arbol(&(*pa)->izq);
    podar_hojas_arbol(&(*pa)->der);
}


