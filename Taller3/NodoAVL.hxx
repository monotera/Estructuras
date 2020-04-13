#include <cstddef>
#include "NodoAVL.h"
template <class T>
NodoAVL<T>::NodoAVL(T dat)
{
    dato = dat;
    Izq = NULL;
    Dere = NULL;
}
template <class T>
NodoAVL<T>::NodoAVL()
{
    Izq = NULL;
    Dere = NULL;
}

template <class T>
void NodoAVL<T>::fijarDato(T &val)
{
    dato = val;
}
template <class T>
NodoAVL<T> *NodoAVL<T>::obtenerHijoIzq()
{
    return Izq;
}
template <class T>
NodoAVL<T> *NodoAVL<T>::obtenerHijoDer()
{
    return Dere;
}
template <class T>
void NodoAVL<T>::fijarHijoIzq(NodoAVL<T> *izq)
{
    this->Izq = izq;
}
template <class T>
void NodoAVL<T>::fijarHijoDer(NodoAVL<T> *der)
{
    this->Dere = der;
}
template <class T>
T NodoAVL<T>::obtenerDato()
{
    return dato;
}