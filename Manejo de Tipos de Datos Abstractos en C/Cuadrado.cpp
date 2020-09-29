/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#include "Cuadrado.h"


Cuadrado::Cuadrado(double lado):Figura("Cuadrado"), lado(lado)
{
    if(this->lado <= 0)
    {
        FiguraInvalidaException exc = FiguraInvalidaException("Figura invalida");
        throw exc;
    }
    this->lado = lado;
}

Cuadrado::~Cuadrado()
{}

double Cuadrado::area() const
{
    return this->lado*this->lado;
}
