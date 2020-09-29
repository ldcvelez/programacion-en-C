/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#include "Triangulo.h"


Triangulo::Triangulo(double base, double altura):Figura("Triángulo"), base(base), altura(altura)
{
    if(this->base <= 0 || this->altura <= 0)
    {
        FiguraInvalidaException exc = FiguraInvalidaException("Figura invalida");
        throw exc;
    }
    this->base = base;
    this->altura = altura;
}


Triangulo::~Triangulo()
{}



double Triangulo::area()const
{
    return (this->base*this->altura)/2;
}
