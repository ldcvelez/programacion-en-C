/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**         COMPLETE LA DECLARACIÓN DE LA CLASE          **//**//**//**/

#ifndef PRISMA_H_
#define PRISMA_H_

#include <iostream>
#include <string>

using namespace std;

class Prisma
{
private:
    int alto;
    int ancho;
    int profundidad;
    string color;     /// <--preferentemente, de lo contrario:  char *color;

public:
    // Constructores
    Prisma(string color = "Incoloro", int alto =1, int ancho =1, int profundidad =1);
    Prisma(const Prisma& pris);
    //~Prisma();

    //Sobrecarga Operadores
    Prisma& operator =(const Prisma& pris);
    Prisma operator++(int num);
    Prisma& operator--();
    friend ostream& operator<<(ostream& out, const Prisma& p);
    friend Prisma operator*(int numero, const Prisma& pris);
    void imprimirPrisma(ostream& out)const;
};


#endif // PRISMA_H_

