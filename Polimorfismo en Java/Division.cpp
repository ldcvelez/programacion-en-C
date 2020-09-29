/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#include "Division.h"

/// La excepcion se resuelve en el constructor padre
Division::Division(const float a,const float b):Operador(a,b,"DIVISION"){}

//Division::~Division()
//{
//
//}

float Division::calcular()const
{
    return (_operA/_operB);
}
