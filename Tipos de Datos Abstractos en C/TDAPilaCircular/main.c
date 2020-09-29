#include "PilaCircular.h"

int main()
{
    int vec[15] = {17,2,3,4,5};
    int i,num;

    tPila pila;

    crearPila(&pila);
    for(i=0;i<5;i++)
    {
        ponerEnPila(&pila,vec + i,sizeof(int));
    }

    verTope(&pila,&num,sizeof(int));
    printf("%d",num);

    return 0;
}
