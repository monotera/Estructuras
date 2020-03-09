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
    int conteo();
    int listar_secuencias();
    int guardar(string nombre);
    string getNombre();
    int esSubSecuencia(string sub);
    string histograma(string desc);
};




#include "sistema.hxx"
#endif

