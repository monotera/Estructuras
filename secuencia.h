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
    int ancho;
    string descripcion;
    long cantiBase;
public:
    int getAncho();
    void setAncho(int ancho);
    list <string> getLineas();
    string getDescripcione();
	void setDescripcion(string nuevaDesc);
    void agregarLinea(string lineaNueva);
    int esSubSecuencia(string sub);
    int enmascarar(string sub);
    int getCantiBase();
    int setCantiBase();
    void borrarLineas();
};


#include "secuencia.hxx"
#endif