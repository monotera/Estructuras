#include "nodoGeneral.h"
#include <iostream>
#include <list>
#include <queue>
using namespace std;

template <class T>
nodoGeneral<T>::nodoGeneral()
{
    this->desc.clear();
}

template <class T>
nodoGeneral<T>::~nodoGeneral()
{
    list<nodoGeneral<T>>::iterator it;
    for (it = desc.begin(); it != desc.end(); ++it)
        delete *it;
    this->desc.clear();
}
template <class T>
T &nodoGeneral<T>::obtenerDato()
{
    return this->dato;
}
template <class T>
void nodoGeneral<T>::fijarDato(T &val)
{
    this->dato = val;
}
template <class T>
void nodoGeneral<T>::limpiarLista()
{
    this->desc.clear();
}
template <class T>
void nodoGeneral<T>::adicionarDesc(T &nval)
{
    nodoGeneral<T> *nodo = new nodoGeneral<T>;
    nodo->fijarDato(nval);
    this->desc.push_back(nodo);
}
template <class T>
bool nodoGeneral<T>::eliminarDesc(T &val)
{
    //Buscar el nodo con el valor dado
    list<nodoGeneral<T> *>::iterator it;
    nodoGeneral<T> *aux;
    bool eliminado = false;
    for (it = desc.begin(); it != desc.end(); ++it)
    {
        aux = *it;
        if (aux->obtenerDato() == val)
            break;
    }
    //Si lo encontramos, lo eliminamos
    if (it != this->desc.end())
    {
        delete *it;
        this->desc.erase(it);
        eliminado = true;
    }
    return eliminado;
}
template <class T>
bool nodoGeneral<T>::esHoja()
{
    return this->desc.size() == 0;
}
template <class T>
bool nodoGeneral<T>::insertarNodo(T padre, T n)
{

    if (this->obtenerDato() == padre)
    {
        adicionarDesc(n);
        return true;
    }
    bool ins = false;
    list<nodoGeneral<T> *>::iteratore it;
    for (it = desc.begin(); it != desc.end(); ++it)
    {
        ins = (*it)->insertarNodo(padre, n);
    }
    return ins;
}
template <class T>
bool nodoGeneral<T>::eliminarNdo(T n)
{
    bool del = false;
    del = this->eliminarDesc(n);
    if (!del)
    {
        list<nodoGeneral<T> *>::iteratore it;
        for (it = desc.begin(); it != desc.end(); ++it)
        {
            del = (*it)->eliminarNodo(n);
        }
    }
    return del;
}
template <class T>
bool nodoGeneral<T>::buscar(T n)
{
    bool encontrado = false;
    if (this->obtenerDato() == n)
    {
        encontrado = true;
    }
    if (!encontrado)
    {
        list<nodoGeneral<T> *>::iteratore it;
        for (it = desc.begin(); it != desc.end(); ++it)
        {
            encontrado = (*it)->buscar(n);
        }
    }
    return encontrado;
}
template <class T>
unsigned int nodoGeneral<T>::tamano()
{

    if (this->esHoja())
        return 0;
    list<nodoGeneral<T> *>::iteratore it;
    unsigned int tama = this->desc.size();
    for (it = desc.begin(); it != desc.end(); ++it)
    {
        tamano += (*it)->tamano();
    }
    return tama;
}
template <class T>
void nodoGeneral<T>::posOrden()
{
    if (!this->esHoja())
    {
        list<nodoGeneral<T> *>::iteratore it;
        for (it = desc.begin(); it != desc.end(); ++it)
        {
            (*it)->posOrden();
        }
        cout << this->obtenerDato() << "    ";
        return;
    }
    else
    {
        cout << this->obtenerDato() << "    ";
        return;
    }
}
template <class T>
void nodoGeneral<T>::nivelOrden()
{
}
template <class T>
int nodoGeneral<T>::altura()
{
    int alt = -1;

    if (this->esHoja())
    {
        alt = 0;
    }
    else
    {
        list<nodoGeneral<T> *>::iterator it;
        for (it = desc.begin(); it != desc.end(); ++it)
        {
            int alth = (*it)->altura();
            if (alt < alth + 1)
                alt = alth + 1;
        }
    }

    return alt;
}
template <class T>
void nodoGeneral<T>::preOrder()
{
    cout << this->obtenerDato() << "    ";
    if (!this->esHoja())
    {
        list<nodoGeneral<T> *>::iterator it;
        for (it = desc.begin(); it != desc.end(); ++it)
        {
            (*it)->preOrder();
        }
    }
}