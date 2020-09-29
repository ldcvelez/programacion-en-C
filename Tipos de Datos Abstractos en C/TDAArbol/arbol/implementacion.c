#include "implementacion.h"
int cargar_arbol(t_arbol *pa)
{
    t_cmp comp=&comp_int;
    t_info elementos[]= {100,50,25,150,125,130,175,200,489,75,2,1,0,278,654,97,98,99,3,6,26,657};
    int i, insertar;
    crear_arbol(pa);
    for(i=0; i<22; i++)
    {
        insertar=insertar_arbol_enorden(pa,&elementos[i],comp);
        if(insertar!=TODO_BIEN)
        {
            if(insertar==DUPLICADO)
                puts("duplicado");
            if(insertar==SIN_MEM)
                puts("sin memoria");
        }
    }
    return TODO_BIEN;
}
int cargar_arbol_ord_arch(t_arbol * pa)
{
    t_info r;
    t_cmp comp=&comp_int;
    FILE * pf=fopen(N_ARCHIVO,"rb");
    if(!pf)
        return ERROR_ARCHIVO;
    fread(&r,1,sizeof(t_info),pf);
    insertar_arbol_enorden(pa,&r,comp);
    while(!feof(pf))
    {
        fread(&r,1,sizeof(t_info),pf);
        insertar_arbol_enorden(pa,&r,comp);
    }
    fclose(pf);

    return TODO_BIEN;
}
void generar_archivo(t_arbol *pa)
{
    FILE* pf;
    pf=fopen(N_ARCHIVO,"wb");
    if(!pf)
    {
        puts("\n ERROR ARCHIVO");
        return;
    }
    cargar_archivo_preorden(pa,&pf);

    puts("\n archivo generado correctamente");
    fclose(pf);

}
void imprimir_arbol(t_arbol *pa)
{
    int offset=0;
    mostrar_arbol(pa,offset);

}
void cantidad_hojas_arbol(const t_arbol* pa)
{
    int cant_hojas;
    cant_hojas=contar_hojas(pa);
    printf("\n\n La cantidad total de hojas del arbol es:%d",cant_hojas);
}
void posicion_dato (const t_arbol *pa, int dato)
{
    t_nodoa** nodo;
    t_cmp cmp= &comp_int;
    *nodo=buscar_nodo(pa,&dato,cmp);
    if(!*nodo)
        puts("\n el valor no fue encontrado");
    else
        printf("\n La direccion del nodo deseado  es: %p",*nodo);
}
