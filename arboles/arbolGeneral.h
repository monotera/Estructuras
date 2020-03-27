#ifndef ARBOLGENERAL__H__
#define ARBOLGENERAL__H__
#include "nodoGeneral.h"

template <class T >
class arbolGeneral
{
    protected:
        nodoGeneral<T>* raiz;
    public:
        arbolGeneral();
        arbolGeneral(T val);
        ~arbolGeneral();
        bool esVacio();
        nodoGeneral<T>* obtenerRaiz();
        void fijarRaiz(nodoGeneral<T>* nraiz);
        bool insertarNodo (T padre, T n);
        bool eliminarNdo (T n);
        bool buscar(T n);
        int altura();
        unsigned int tamano();
        void preOrder();
        void posOrden();
        void nivelOrden();
};




#include "arbolGeneral.hxx"
#endif