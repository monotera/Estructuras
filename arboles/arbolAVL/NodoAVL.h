#ifndef __NODOAVL__H__
#define __NODOAVL__H__

#include <iostream>
using namespace std;

template< class T >
class NodoAVL
{
protected:
    T dato;
    NodoAVL<T> *Izq;
    NodoAVL<T> *Dere;
public:
    NodoAVL(T dato);
    NodoAVL();
    T obtenerDato();
    void fijarDato(T& val);
    NodoAVL<T>* obtenerHijoIzq();
    NodoAVL<T>* obtenerHijoDer();
    void fijarHijoIzq(NodoAVL<T> *izq);
    void fijarHijoDer(NodoAVL<T> *der);
};

#include "NodoAVL.hxx"
#endif