#include "nodoGeneral.h"
#include <iostream>

using namespace std;

template<class T>
nodoGeneral<T>::nodoGeneral(){
    this->desc.clear();
}

template <class T>
nodoGeneral<T>::~nodoGeneral(){
    list<nodoGeneral <T> >::iterator it;
    for (it = desc.begin(); it!=desc.end();++it)
        delete *it;
    this->desc.clear();
}
template <class T>
T& nodoGeneral<T>::obtenerDato(){
    return this->dato;

}
template <class T>
void nodoGeneral<T>::fijarDato(T& val){
    this->dato = val;
}
template <class T>
void nodoGeneral<T>::limpiarLista(){
    this->desc.clear();
}
template <class T>
void nodoGeneral<T>::adicionarDesc(T& nval){
    nodoGeneral<T> *nodo = new nodoGeneral<T>;
    nodo->fijarDato(nval);
    this->desc.push_back(nodo);
}
template <class T>
bool nodoGeneral<T>::eliminarDesc(T& val){
    //Buscar el nodo con el valor dado
    list <nodoGeneral<T>*>::iterator it;
    nodoGeneral<T> *aux;
    bool eliminado = false;
    for (it = desc.begin(); it!=desc.end();++it){
        aux = *it;
        if(aux->obtenerDato() == val)
            break;
    }
    //Si lo encontramos, lo eliminamos
    if(it != this->desc.end()){
        delete *it;
        this->desc.erase(it);
        eliminado = true;
    }
    return eliminado;

}
template <class T>
bool nodoGeneral<T>::esHoja(){
    return this->desc.size() == 0;
}