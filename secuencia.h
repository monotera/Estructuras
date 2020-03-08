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
public:
    int secuencias();
    int getAncho();
    void setAncho(int ancho);
    list <string> getLineas();
    void setLineas(list <string> listaNueva);
    int agregarLinea(string lineaNueva);
    int esSubSecuencia(string sub);
    int enmascarar(string sub);
};


#include "secuencia.hxx"
#endif