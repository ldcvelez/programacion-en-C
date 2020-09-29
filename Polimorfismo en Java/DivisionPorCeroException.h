/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#ifndef DIVISIONPORCEROEXCEPTION_H_INCLUDED
#define DIVISIONPORCEROEXCEPTION_H_INCLUDED

#include <exception>
#include <string>

using namespace std;

class DivisionPorCeroException : public exception
{
public:
    DivisionPorCeroException():exception(){}
    const char* what()const throw ()
    {
        return "Division por cero";
    }
};


#endif // DIVISIONPORCEROEXCEPTION_H_INCLUDED

