#ifndef SISTEMA__H__
#define SISTEMA__H__

#include <iostream>
#include <list>
#include<string>
#include "archivo.h"

using namespace std;

class sistema
{
private:
   archivo arch;
public:
    archivo getArchivo();
    int cargarArchivo(string nombre);
    int guardar(string nombre);
      
};




#include "sistema.hxx"
#endif

