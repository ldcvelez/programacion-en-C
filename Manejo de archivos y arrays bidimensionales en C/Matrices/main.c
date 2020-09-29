#include "Matrices.h"

int main()
{
    int mat[TAM][TAM] = {{8,1,3},
                    {1,7,4},
                    {3,4,9}};

    mostrarMatriz(mat);
    if(esSimetrica(mat))
        printf("\nLa matriz SI es cuadrada");
    else printf("\nLa matriz NO es cuadrada");




    return 0;
}
