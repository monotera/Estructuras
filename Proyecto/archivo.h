#ifndef ARCHIVO__H__
#define ARCHIVO__H__

#include <iostream>
#include <list>
#include<string>
#include "secuencia.h"
#include "NodoGrafo.h"
using namespace std;

class archivo
{
protected:
    string nombre;
    list <secuencia> secuencias;
public:
    string getNombreArchivo();
    void setNombreArchivo(string nombre);
    list <secuencia> getSecuencias();
	void agregarSecuencia(secuencia nuevaSec);
    int getTamaSec();
    int listar_sec();
    int esSubSecuencia(string sub);
    int enmascarar(string sub);
	string histograma(string desc);
    int guardar(string nombre);
    void borrarSec();
    vector<string> secuenciasLinea();
    short llenarArreglos(char car[],long fre[]);
    vector<string> getNombreSec();
    vector<short> getIdentaciones();
    secuencia buscarSec(string nombre);
    vector<NodoGrafo> generarVertices(string nombre); 
};




#include "archivo.hxx"
#endif