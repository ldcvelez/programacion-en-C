#include "Cola.h"
#include "main.h"

 int main(void)
{
     probarIngresarYMostrarProd();

     probarIngresarYMostrarTexto();

     probarPonerYSacarDeCola();

    return 0;
 }

 void probarIngresarYMostrarProd(void)
 {
     tProd prod;
     int cant = 0;

     puts("Probando ingresar productos y mostrar productos.\n"
     "======== ======== ========= = ======= =========");
     if(ingresarProducto(&prod))
     mostrarProducto(NULL);
     do
     {
     mostrarProducto(&prod);
     cant++;
     } while(ingresarProducto(&prod));
     fprintf(stdout, "Se mostraron %d productos.\n\n", cant);
 }

 void probarIngresarYMostrarTexto(void)
 {
     char linea[90];
     int cant = 0;

     puts("Probando ingresar lineas de texto mostrandolas.\n"
     "======== ======== ====== == ===== ============");
     while(ingresarTexto(linea, sizeof(linea)))
     {
         cant++;
         printf("\"%s\"\n", linea);
     }
     fprintf(stdout, "Se mostraron %d lineas de texto.\n\n", cant);
 }

 int _probarLlenaYEncolar(tCola *cola)
 {
     tProd prod;
     int cant = 0;

     puts("Probando cola llena y poner en cola.");
     mostrarProducto(NULL);
     while(!colaLlena(cola, sizeof(prod)) && ingresarProducto(&prod))
     {
         if(!ponerEnCola(cola, &prod, sizeof(prod)))
         {
         fprintf(stderr, "ERROR - inesperado - cola llena.\n");
         puts("no se pudo cargar la informacion y"
         " habria que tomar alguna decision drastica.");
         }
     mostrarProducto(&prod);
     cant++;
     }
    return cant;
 }

 void _probarVerTope(tCola *cola)
 {
     tProd prod;

     puts("Probando ver el primero de la cola.");
     if(verPrimeroCola(cola, &prod, sizeof(prod)))
     {
         mostrarProducto(NULL);
         mostrarProducto(&prod);
     }
     else
     puts("La cola estaba vacia.");
     puts("");
 }

 void _probarVaciaYDesacolarN(tCola *cola, int canti)
 {
     tProd prod;

     printf("Probando cola vacia y sacar de cola %d productos (mostrandolos.\n",
     canti);
     if(colaVacia(cola))
        puts("La cola esta vacia.");
     else
        mostrarProducto(NULL);
     while(canti > 0 && sacarDeCola(cola, &prod, sizeof(prod)))
     {
         canti--;
         mostrarProducto(&prod);
     }
     puts("");
 }


 int _probarVaciarColaYColaVacia(tCola *cola)
 {
     puts("Probando vaciar cola y cola vacia.");
     vaciarCola(cola);
     if(!colaVacia(cola))
        return 0; // fprintf(stderr, "ERROR - la cola debia estar vacia\n\n");
     printf("Vaciar cola funciona!\n\n");
     puts("");
     return 1;
 }

 void _probarLlenaYEncolarTexto(tCola *cola)
 {
     char linea[70];
     int cant = 0;

     puts("Probando cola llena y poner en cola Texto.");
     while(!colaLlena(cola, sizeof(linea)) && ingresarTexto(linea, sizeof(linea)))
     {
         if(!ponerEnCola(cola, linea, strlen(linea) + 1))
         {
             fprintf(stderr, "ERROR - inesperado - cola llena.\n");
             puts("no se pudo cargar la informacion y"
             " habria que tomar alguna decision drastica.");
         }
         printf("\"%s\"\n", linea);
         cant++;
     }
     printf("se pusieron %d lineas de texto en la cola.\n\n", cant);
     printf("Probando sacar de cola con las lineas de texto.\n");
 }


 void _probarSacarDeColaTexto(tCola *cola)
 {
     char linea[70];
     int cant = 0;

     while(sacarDeCola(cola, linea, sizeof(linea)))
     {
         cant++;
         printf("\"%s\"\n", linea);
     }
     printf("Se sacaron y mostraron %d lineas de texto\n\n", cant);
 }

 void probarPonerYSacarDeCola(void)
 {
     tCola cola;
     int cant;

     crearCola(&cola);

     puts("Probando primitivas de cola con productos.\n"
     "======== ========== == ==== === =========\n");
     cant = _probarLlenaYEncolar(&cola);
     printf("se pusieron %d productos en la cola.\n\n", cant);

     _probarVerTope(&cola);

     _probarVaciaYDesacolarN(&cola, cant - 2);

     _probarVerTope(&cola);

     if(_probarVaciarColaYColaVacia(&cola) != 1)
     fprintf(stderr, "ERROR - inesperado, la cola NO QUEDO vacia\n");

     puts("Probando primitivas de cola con lineas de texto.\n"
     "======== ========== == ==== === ====== == =====\n");
     _probarLlenaYEncolarTexto(&cola);

     _probarSacarDeColaTexto(&cola);
     cant = 0;

     puts("ATENCION: se mostro el uso de una cola, en la que se pusieron"
         " productos, se pro\n"
         "baron todas las primitivas. Una vez que se la dejo vacia "
         "se encolaron lineas\n"
         "de texto y luego se desencolaron. Lo mas importante de esto "
         "no es utilizar la\n"
         "misma cola, lo que mas importa es que con las mismas primiti"
         "vas se pueden enco-\n"
         "lar distintos tipos de objetos, incluyendo lineas de texto d"
         "e distinto tamano.\n");
 }

