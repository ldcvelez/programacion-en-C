/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#include "Rectangulo.h"


Rectangulo::Rectangulo(double ladoMenor, double ladoMayor):Figura("Rectángulo"), ladoMenor(ladoMenor), ladoMayor(ladoMayor)
{
    if(this->ladoMenor <= 0 || this->ladoMayor <= 0)
    {
        FiguraInvalidaException exc = FiguraInvalidaException("Figura invalida");
        throw exc;
    }
    this->ladoMenor = ladoMenor;
    this->ladoMayor = ladoMayor;
}

Rectangulo::~Rectangulo()
{}



double Rectangulo::area()const
{
    return this->ladoMenor * this->ladoMayor;
}
