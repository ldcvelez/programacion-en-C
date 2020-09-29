/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#include "Operador.h"

Operador::Operador(const float a,const float b,const string nombre)
{
    if(nombre == "DIVISION" && b==0)
        throw DivisionPorCeroException();
    _operA = a;
    _operB = b;
    this->nombre = nombre;
}

float Operador::getOperandoA() const
{
    return _operA;
}

float Operador::getOperandoB() const
{
    return _operB;
}

string Operador::operacion() const
{
    return nombre;
}

Operador::~Operador()
{

}
