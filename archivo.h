#ifndef ARCHIVO__H__
#define ARCHIVO__H__

#include <iostream>
#include <list>
#include<string>
#include "secuencia.h"

using namespace std;

class archivo
{
protected:
    string nombre;
    list <secuencia> secuencias;
    list <string> descripcion;
public:
    int archivos();
    string getNombreArchivo();
    void setNombreArchivo(string nombre);
    list <secuencia> getSecuencias();
	void setSecuencias(list <secuencia> nuevaSec);
	list <string> getDescripciones();
	void setDescripciones(list <string> nuevaDesc);
	int listarSecuencias();
	int conteo();
	/*histograma(Pdescripcion), Obtiene el histograma de la secuencia con la descripcion dada, en caso de que exista*/
};




#include "archivo.hxx"
#endif