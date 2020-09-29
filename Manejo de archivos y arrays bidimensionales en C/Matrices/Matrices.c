#include "Matrices.h"

void mostrarMatriz(int m[][TAM])
{
    int i,j;

    printf("\n");
    for(i=0;i<TAM;i++)
    {
        printf("\n");
        for(j=0;j<TAM;j++)
        {
            printf("%d\t",m[i][j]);
        }
    }
}


int esSimetrica(int m[][TAM])
{
    int i,j;

    for(i=1;i<TAM;i++)
        for(j=0;j<i;j++)
            if(m[i][j] != m[j][i])
                return 0;

    return 1;
}
