#ifndef NODOBINARIO__H__
#define NODOBINARIO__H__

#include <iostream>
using namespace std;

template<class T>
class nodoBinario
{
    protected:
        T dato;
        nodoBinario <T> *hijoIzq;
        nodoBinario <T> *hijoDer;
    public:
        T& obtenerDato();
        void fijarDato(T& val);
        nodoBinario<T>* obtenerHijoIzq();
        nodoBinario<T>* obtenerHijoDer();
        void fijarHijoIzq(nodoBinario<T> *iz);
        void fijarHijoDer(nodoBinario<T> *der);
};

#include "nodoBinario.hxx"
#endif