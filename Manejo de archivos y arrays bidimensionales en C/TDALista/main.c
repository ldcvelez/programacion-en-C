#include "TDALista.h"

void mostrar(const t_info *d)
{
    printf("Nombre :%s\t | Edad :%d\n",d->apyn,d->edad);
}

int main()
{
    t_lista lista;
    char nombreArch[51]="C:\\Users\\leone\\OneDrive\\Escritorio\\AlumnosLista";
    t_alumno alu={'B',"Fabian1 Cubero",21,{15,12,2003}};
    t_alumno alu2={'B',"Fabian2 Cubero",21,{15,12,2003}};
    t_alumno alu3={'B',"Fabian3 Cubero",21,{15,12,2003}};
    t_alumno alu4={'B',"Fabian4 Cubero",21,{15,12,2003}};

    generarArchivo(nombreArch);
    crearLista(&lista);
    ///procesarArchivo(nombreArch,&lista);
    insertarAlInicio(&lista,&alu);
    insertarAlInicio(&lista,&alu2);
    insertarAlInicio(&lista,&alu3);
    eliminarNodoDelMedio(&lista);
    recorrerLista(&lista,mostrar);


    ///vaciarLista(&lista);
    ///insertarAlFinal(&lista,&alu);
    ///insertarEnOrden(&lista,&alu,comparacion);
    //recorrerLista(&lista,mostrar);
    return 0;
}
