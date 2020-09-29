/**//* 38.670.422-CESPEDES,Leonel-(06-2965) *//**/

#ifndef FIGURAINVALIDAEXCEPTION_H_
#define FIGURAINVALIDAEXCEPTION_H_

#include <exception>
#include <string>


using namespace std;


class FiguraInvalidaException
{
 private:
       string mensaje;

 public:
       FiguraInvalidaException(const string& mensaje);
       const string& what()const;
};





#endif // FIGURAINVALIDAEXCEPTION_H_
