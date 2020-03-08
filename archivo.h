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
public:
    int archivos();
    string getNombreArchivo();
    void setNombreArchivo(string nombre);
    list <secuencia> getSecuencias();
	void agregarSecuencia(secuencia nuevaSec);
	int listarSecuencias();
	int conteo();
    int getTamaSec();
    int listar_sec();
    void imprimirSec(secuencia sec, int sec_incompleta);
    int esSubSecuencia(string sub);
	/*histograma(Pdescripcion), Obtiene el histograma de la secuencia con la descripcion dada, en caso de que exista*/
};




#include "archivo.hxx"
#endif