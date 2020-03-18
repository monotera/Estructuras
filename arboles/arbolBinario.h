#ifndef ARBOLBINARIO__H__
#define ARBOLBINARIO__H__

#include "nodoBinario.h"

template <class T>
class arbolBinario
{
    protected:
        nodoBinario<T> *raiz;        
    public:
        bool esVacio();
        T& datoRaiz();
        int altura();
        int tamano();
        bool insertarIzq(T& val, nodoBinario<T> *padre);
        bool insertarDer(T& val, nodoBinario<T> *padre);
        bool eliminar(T& val);
        bool buscar(T& val);
        void preOrden();
        void inOrden();
        void posOrden();
        void nivelOrden();
};

#include "arbolBinario.hxx"
#endif