#include "Archivos1.h"

int main()
{
    t_alumno alu[10]= {{6,"Juan Perez",25,25,12,1995},{9,"Maria Lopez",20,25,10,1990},{10,"Ana Florencia",19,31,01,2000}};
    char nombreArchTXT[51]= "C:\\Users\\leone\\OneDrive\\Escritorio\\Alumnos.txt";
    char nombreArchPTXT[51]= "C:\\Users\\leone\\OneDrive\\Escritorio\\Parsear Alumnos.txt";
    char nombreArchBIN1[51]= "C:\\Users\\leone\\OneDrive\\Escritorio\\Alumnos1.bin";
    char nombreArchBIN2[51]= "C:\\Users\\leone\\OneDrive\\Escritorio\\Alumnos2.bin";
    char nombreArchMergeo[51]= "C:\\Users\\leone\\OneDrive\\Escritorio\\Mergeo.bin";

    generarArchivoTXT(alu,nombreArchTXT,3);
    generarArchivoBIN(nombreArchBIN1,nombreArchBIN2);

    puts("PRIMER ARCHIVO:\n");
    leerArchivoBIN(nombreArchBIN1);
    puts("\n\nSEGUNDO ARCHIVO:\n");
    leerArchivoBIN(nombreArchBIN2);
    //leerArchivoTXT(nombreArchTXT);
    mergeoArchivos(nombreArchBIN1,nombreArchBIN2,nombreArchMergeo);
    puts("\n\nUNION DE ARCHIVOS:\n");
    leerArchivoBIN(nombreArchMergeo);
    return 0;
}
