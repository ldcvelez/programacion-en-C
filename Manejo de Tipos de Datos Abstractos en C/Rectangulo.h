/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#ifndef RECTANGULO_H_
#define RECTANGULO_H_

#include "Figura.h"


class Rectangulo : public Figura
{
private:
    double ladoMenor;
    double ladoMayor;

public:
     Rectangulo(double ladoMenor, double ladoMayor);
     ~Rectangulo();

     double area() const;
};








#endif // RECTANGULO_H_
