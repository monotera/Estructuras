#ifndef __NODOBINARIO__H__
#define __NODOBINARIO__H__

#include <iostream>
using namespace std;

template< class T >
class NodoBinario
{
protected:
    T dato;
    NodoBinario<T> *Izq;
    NodoBinario<T> *Dere;
public:
    NodoBinario(T dato);
    NodoBinario();
    T obtenerDato();
    void fijarDato(T& val);
    NodoBinario<T>* obtenerHijoIzq();
    NodoBinario<T>* obtenerHijoDer();
    void fijarHijoIzq(NodoBinario<T> *izq);
    void fijarHijoDer(NodoBinario<T> *der);
};

#include "NodoBinario.hxx"
#endif