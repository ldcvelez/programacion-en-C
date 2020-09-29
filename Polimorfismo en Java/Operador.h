/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#ifndef OPERADOR_H_INCLUDED
#define OPERADOR_H_INCLUDED

#include <string>
#include "DivisionPorCeroException.h"

using namespace std;

class Operador
{
protected:
    float _operA;
    float _operB;
    string nombre;
public:
    Operador(const float a,const float b,const string nombre);
    virtual float calcular() const = 0;
    virtual float getOperandoA() const;
    virtual float getOperandoB() const;
    virtual string operacion() const;
    virtual ~Operador();

};
#endif // OPERADOR_H_INCLUDED

