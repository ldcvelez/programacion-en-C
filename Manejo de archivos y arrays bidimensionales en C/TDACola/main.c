#include "TDACola.h"

int main()
{
    t_cola cola;
    char nombreArch[51]="C:\\Users\\leone\\OneDrive\\Escritorio\\AlumnosCola";
    t_alumno alu={'B',"Fabian Cubero",21,{15,12,2003}};
    t_alumno alu2;
    t_alumno alu3;
    t_alumno alu4;
    t_alumno alu5;

    generarArchivo(nombreArch);
    crearCola(&cola);
    procesarArchivo(nombreArch,&cola);
    verFrente(&cola,&alu2);
    puts("Frente de la Cola");
    printf("Nombre: %s\t Edad: %d\n",alu2.apyn,alu2.edad);
    puts("\n");
    puts("Fondo de la Cola");
    verFondo(&cola,&alu2);
    printf("Nombre: %s\t Edad: %d\n\n",alu2.apyn,alu2.edad);

    acolar(&cola,&alu);
    verFondo(&cola,&alu);
    puts("Nuevo fondo de la Cola");
    printf("Nombre: %s\t Edad: %d\n\n",alu.apyn,alu.edad);

    desacolar(&cola,&alu3);
    printf("Expulsado de la cola:\n");
    printf("Nombre: %s\n\n",alu3.apyn);

    verFrente(&cola,&alu4);
    puts("Nuevo frente de la Cola");
    printf("Nombre: %s\t Edad: %d\n",alu4.apyn,alu4.edad);

    vaciarCola(&cola);
    verFrente(&cola,&alu5);
    //puts("Nuevo frente de la Cola");
    //printf("Nombre: %s\t Edad: %d\n",alu5.apyn,alu5.edad);

    return 0;
}
