#ifndef SECUENCIA__H__
#define SECUENCIA__H__

#include <list>
#include <iostream>
#include <string>

using namespace std;


class secuencia
{
protected:
    list <string> linea;
    string descripcion;
    long cantiBase = 0;
public:
    list <string> getLineas();
    string getDescripcione();
    string histograma();
	void setDescripcion(string nuevaDesc);
    void agregarLinea(string lineaNueva);
    int esSubSecuencia(string sub);
    int enmascarar(string sub);
    int getCantiBase();
    int setCantiBase();
    void borrarLineas();
    string getSecuenciaLinea();
    void crearLista(int f[]);
    int getIndentacion();
};


#include "secuencia.hxx"
#endif