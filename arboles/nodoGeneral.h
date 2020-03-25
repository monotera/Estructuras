#ifndef NODOGENERAL__H__
#define NODOGENERAL__H__

#include <list>

template <class T>
class nodoGeneral
{
    protected:
         T dato;
         std::list<nodoGeneral<T>* > desc;
    public:
         nodoGeneral();
         ~nodoGeneral();
         T& obtenerDato();
         void fijarDato(T& val);
         void limpiarLista();
         void adicionarDesc(T& nval);
         bool eliminarDesc(T& val);
         bool esHoja();
};

#include "nodoGeneral.hxx"
#endif