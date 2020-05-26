#ifndef SISTEMA__H__
#define SISTEMA__H__

#include <iostream>
#include <list>
#include<string>
#include "archivo.h"
#include "HuffmanArbol.h"
#include "GrafoM.h"
#include "NodoGrafo.h"
using namespace std;

class sistema
{
private:
   GrafoM <NodoGrafo,double> grafo;
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
    bool cifrar(string);
    bool desCifrar(string nombre);
    struct datosBin;
    void llenarStruct(datosBin &datos);
    bool crearFa(datosBin dat);
    void generarGrafo(string nombre);
    bool llenarVertices(string nombre);
    bool llenarConex();
    string ruta_mas_corta(string nombre, int i, int j, int x,int y);
};




#include "sistema.hxx"
#endif

