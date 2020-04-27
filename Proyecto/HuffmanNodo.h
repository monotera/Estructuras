#ifndef HUFFMANNODO_H_INCLUDED
#define HUFFMANNODO_H_INCLUDED

#include<iostream>
#include<string.h>
#include <queue>

using namespace std;

class HuffmanNodo
{
private:
    char dato;
    unsigned int freq;
    HuffmanNodo *der, *izq;
    
public:
    HuffmanNodo();
    HuffmanNodo(char dato, unsigned int freq);
    HuffmanNodo* obtenerHijoIzq();
    HuffmanNodo* obtenerHijoDer();
    void fijarHijoDer(HuffmanNodo* der);
    void fijarHijoIzq(HuffmanNodo* izq);
    unsigned int obtenerFreq();
    char obtenerDato();
    bool esHoja();

};


#include "HuffmanNodo.hxx"
#endif 
