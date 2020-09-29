/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#ifndef TRIANGULO_H_
#define TRIANGULO_H_

#include "Figura.h"


class Triangulo : public Figura
{
private:
    double base;
    double altura;

public:
    Triangulo(double base, double altura);
    ~Triangulo();

    double area() const;
};





#endif // TRIANGULO_H_
