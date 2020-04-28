#ifndef SISTEMA__H__
#define SISTEMA__H__

#include <iostream>
#include <list>
#include<string>
#include "archivo.h"
#include "HuffmanArbol.h"

using namespace std;

class sistema
{
private:
   archivo arch;
   HuffmanArbol arbolHuff;
public:
    int cargarArchivo(string nombre);
    int conteo();
    int listar_secuencias();
    int enmascarar(string sub);
    int guardar(string nombre);
    string getNombre();
    int esSubSecuencia(string sub);
    string histograma(string desc);
    bool cifrar();
    bool desCifrar(string nombre);
    struct datosBin;
    void llenarStruct(datosBin &datos);
    bool crearFa(datosBin dat);
};




#include "sistema.hxx"
#endif

