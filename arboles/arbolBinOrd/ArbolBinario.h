#ifndef ARBOLBINARIO__H__
#define ARBOLBINARIO__H__

#include "NodoBinario.h"

template <class T>
class ArbolBinario
{
protected:
    NodoBinario<T> *raiz;

public:
    ArbolBinario();
    NodoBinario<T> *getRaiz();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    int altura(NodoBinario<T> *inicio);
    int tamano(NodoBinario<T> *inicio);
    bool insertar(T &val);
    bool eliminar(T &val);
    bool buscar(T &val);
    void preOrden(NodoBinario<T> *inicio);
    void inOrden(NodoBinario<T> *inicio);
    void posOrden(NodoBinario<T> *inicio);
    void nivelOrden(NodoBinario<T> *inicio);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
};

#include "ArbolBinario.hxx"
#endif