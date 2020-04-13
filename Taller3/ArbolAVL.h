#ifndef ARBOLAVL__H__
#define ARBOLAVL__H__

#include "NodoAVL.h"
#include <list>
template <class T>
class ArbolAVL
{
protected:
    NodoAVL<T> *raiz;

public:
    ArbolAVL();
    NodoAVL<T> *getRaiz();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    bool insertar(T &val);
    int altura(NodoAVL<T> *inicio);
    int tamano(NodoAVL<T> *inicio);
    NodoAVL<T> *insertar(T &val, NodoAVL<T> *padre);
    NodoAVL<T> *eliminarf(T &val, NodoAVL<T> *padre);
    void eliminar(T &val);
    bool buscar(T &val);
    void preOrden(NodoAVL<T> *inicio);
    void inOrden(NodoAVL<T> *inicio);
    void posOrden(NodoAVL<T> *inicio);
    void nivelOrden(NodoAVL<T> *inicio);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    int diff(NodoAVL<T> *);
    NodoAVL<T> *rotacionDerecha(NodoAVL<T> *);
    NodoAVL<T> *rotacionIzquierda(NodoAVL<T> *);
    NodoAVL<T> *rotacionDI(NodoAVL<T> *);
    NodoAVL<T> *rotacionID(NodoAVL<T> *);
    NodoAVL<T> *balance(NodoAVL<T> *);
    void inOrdenL(NodoAVL<T> *inicio, list<T> &l);
    void inOrdenL(list<T> &l);
    void  valorMax(T &mayor);

};

#include "ArbolAVL.hxx"
#endif