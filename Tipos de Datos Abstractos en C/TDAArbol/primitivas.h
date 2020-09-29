#ifndef PRIMITIVAS_H_INCLUDED
#define PRIMITIVAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


#define MAYOR(X,Y) (X)>(Y)?(X):(Y)
#define ES_HOJA !(*pa)->izq&&!(*pa)->der
#define SIN_MEM 0
#define DUPLICADO -5
#define ARBOL_VACIO 0
#define ERROR_LECTURA 0
#define ERROR_ARCHIVO 3
#define N_ARCHIVO "arbol.bin"
#define TODO_BIEN 1
typedef int t_info;
typedef struct s_nodoa
{
    t_info info;
    struct s_nodoa *izq;
    struct s_nodoa *der;
} t_nodoa;

typedef int (*t_cmp)(const t_info*, const t_info*);
typedef void (*t_accion) (const t_info *);
typedef t_nodoa *t_arbol;

int comp_int (const t_info *a, const t_info *b);
void print (t_info *info);
void imprimir_espacios(int offset);
void crear_arbol(t_arbol *);
int insertar_arbol_enorden(t_arbol *,const t_info *,t_cmp comp);
void mostrar_arbol(t_arbol *pa,int offset);
void cargar_archivo_preorden(t_arbol*pa, FILE** pf);
int contar_hojas(const t_arbol *pa);
int contar_nodos (const t_arbol* pa);
t_arbol *buscar_nodo(const t_arbol *pa,t_info *dato,t_cmp cmp);
int altura_arbol(const t_arbol *pa);
int contar_nodos_con_hijos_izq(const t_arbol *pa);
int contar_nodos_con_hijos_der(const t_arbol *pa);
int contar_nodos_con_hijos_solo_der(const t_arbol *pa);
int contar_nodos_con_hijos_solo_izq(const t_arbol *pa);
int contar_hasta_nivel_inclusive(const t_arbol *pa,int n);
int contar_hasta_nivel_inclusive_no_inclusive(const t_arbol *pa,int n);
void podar_hojas_desde_nivel(t_arbol *pa,int n);
void podar_hojas_arbol(t_arbol *pa);
int podarArbolAltura(t_arbol *pa,int altura);

int  eliminar_arbol(t_arbol *pa);
#endif // PRIMITIVAS_H_INCLUDED
