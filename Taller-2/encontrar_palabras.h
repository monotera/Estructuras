#ifndef ENCONTRA_RPALABRAS__H__
#define ENCONTRA_RPALABRAS__H__
#include <list>
#include <queue>
#include <string>

using namespace std;

class encontrar_palabras
{
protected:
    int cantiPalabras = 0;

public:
    void contiene(char *palabraBuscar, list<string> linea);
    void separateWords(char *str, queue<char *> &palabras);
    void comienza(char *palabraBuscar, list<string> linea);
};



#include "encontrar_palabras.hxx"
#endif