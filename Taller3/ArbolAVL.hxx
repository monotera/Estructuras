#include "ArbolAVL.h"
#include <queue>
#include <iostream>
#include <cstddef>
#include <list>

using namespace std;
template <class T>
ArbolAVL<T>::ArbolAVL()
{
    raiz = NULL;
}
template <class T>
bool ArbolAVL<T>::esVacio()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}
template <class T>
T ArbolAVL<T>::datoRaiz()
{
    if (!esVacio())
        return raiz->obtenerDato();
}
template <class T>
int ArbolAVL<T>::altura(NodoAVL<T> *inicio)
{

    if (inicio == NULL)
    {
        return -1;
    }
    else
    {
        int alturai = altura(inicio->obtenerHijoIzq());
        int alturad = altura(inicio->obtenerHijoDer());
        int maxalt = max(alturai, alturad);
        return maxalt + 1;
    }
    return -1;
}
template <class T>
int ArbolAVL<T>::tamano(NodoAVL<T> *inicio)
{
    if (esVacio())
        return 0;
    NodoAVL<T> *hijod = inicio->obtenerHijoDer();
    NodoAVL<T> *hijoi = inicio->obtenerHijoIzq();
    if (hijod == NULL && hijoi == NULL)
    {
        return 1;
    }
    if (hijod == NULL)
        return 1 + tamano(hijoi);
    if (hijoi == NULL)
        return 1 + tamano(hijod);
    return 1 + tamano(hijod) + tamano(hijoi);
}

template <class T>
NodoAVL<T> *ArbolAVL<T>::insertar(T &val, NodoAVL<T> *padre)
{
    NodoAVL<T> *nod, *r = NULL;
    if (esVacio())
    {
        raiz = new NodoAVL<T>(val);

        r = NULL;
    }
    else if (padre == NULL)
    {
        nod = new NodoAVL<T>(val);

        r = nod;
    }
    else if (val > padre->obtenerDato())
    {
        nod = insertar(val, padre->obtenerHijoDer());
        if (nod == NULL)
            r = NULL;
        else
        {
            padre->fijarHijoDer(nod);
            padre = balance(padre);
            r = padre;
        }
    }
    else if (val < padre->obtenerDato())
    {
        nod = insertar(val, padre->obtenerHijoIzq());
        if (nod == NULL)
            r = NULL;
        else
        {
            padre->fijarHijoIzq(nod);
            padre = balance(padre);
            r = padre;
        }
    }

    return r;
}

/*
 * Balancing AVL Tree
 */
template <class T>
NodoAVL<T> *ArbolAVL<T>::balance(NodoAVL<T> *temp)
{
    if (this->altura() <= 1 && this->altura() >= -1)
        return temp;
    int dif = diff(temp);
    if (dif > 1)
    {
        if (diff(temp->obtenerHijoIzq()) > 0)
            temp = rotacionDerecha(temp);
        else
            temp = rotacionID(temp);
    }
    else if (dif < -1)
    {
        if (diff(temp->obtenerHijoDer()) < 0)
            temp = rotacionIzquierda(temp);
        else
            temp = rotacionDI(temp);
    }
    return temp;
}
/*
 * Height Difference
 */
template <class T>
int ArbolAVL<T>::diff(NodoAVL<T> *temp)
{
    int l_altura = altura(temp->obtenerHijoIzq());
    int r_altura = altura(temp->obtenerHijoDer());
    return l_altura - r_altura;
}

/*
 * Der- Der Rotation
 */
template <class T>
NodoAVL<T> *ArbolAVL<T>::rotacionDerecha(NodoAVL<T> *parent)
{
    NodoAVL<T> *temp;
    temp = parent->obtenerHijoIzq();
    parent->fijarHijoIzq(temp->obtenerHijoDer());
    temp->fijarHijoDer(parent);
    return temp;
}
/*
 * getLeft()- Left Rotation
 */
template <class T>
NodoAVL<T> *ArbolAVL<T>::rotacionDI(NodoAVL<T> *parent)
{
    NodoAVL<T> *aux;
    aux = rotacionDerecha(parent->obtenerHijoDer());
    parent->fijarHijoDer(aux);
    return rotacionIzquierda(parent);
}

/*
 * Left - Der Rotation
 */
template <class T>
NodoAVL<T> *ArbolAVL<T>::rotacionID(NodoAVL<T> *parent)
{
    NodoAVL<T> *aux;
    aux = rotacionIzquierda(parent->obtenerHijoIzq());
    parent->fijarHijoIzq(aux);
    return rotacionDerecha(parent);
}

/*
 * Der- Left Rotation
 */
template <class T>
NodoAVL<T> *ArbolAVL<T>::rotacionIzquierda(NodoAVL<T> *parent)
{
    NodoAVL<T> *temp;
    temp = parent->obtenerHijoDer();
    parent->fijarHijoDer(temp->obtenerHijoIzq());
    temp->fijarHijoIzq(parent);
    return temp;
}
template <class T>
void ArbolAVL<T>::eliminar(T &val)
{
    if(!this->esVacio())
        raiz = balance(eliminarf(val, raiz));
}

template <class T>
NodoAVL<T> *ArbolAVL<T>::eliminarf(T &val, NodoAVL<T> *padre)
{
    NodoAVL<T> *r = NULL;
    if (esVacio())
        r = NULL;
    else if (padre == NULL)
    {
        r = NULL;
    }
    if (padre->obtenerDato() == val)
    {
        if (padre->obtenerHijoDer() != NULL && padre->obtenerHijoIzq() == NULL)
            r = padre->obtenerHijoDer();
        else if (padre->obtenerHijoDer() == NULL && padre->obtenerHijoIzq() != NULL)
            r = padre->obtenerHijoIzq();
        else if ((padre->obtenerHijoDer() != NULL && padre->obtenerHijoIzq() != NULL))
        {
            NodoAVL<T> *aux, *auxh;
            aux = padre->obtenerHijoIzq();
            auxh = padre;
            while (aux->obtenerHijoDer() != NULL)
            {
                auxh = aux;
                aux = aux->obtenerHijoDer();
            }
            if (auxh != padre)
                auxh->fijarHijoDer(NULL);
            else
                auxh->fijarHijoIzq(NULL);
            T h = aux->obtenerDato();
            padre->fijarDato(h);
            padre = balance(padre);
            r = padre;
        }
        return r;
    }

    if (val > padre->obtenerDato())
    {
        padre->fijarHijoDer(eliminarf(val, padre->obtenerHijoDer()));
        padre = balance(padre);
        r = padre;
    }

    else if (val < padre->obtenerDato())
    {
        padre->fijarHijoIzq(eliminarf(val, padre->obtenerHijoIzq()));
        padre = balance(padre);
        r = padre;
    }
    return r;
}
template <class T>
bool ArbolAVL<T>::buscar(T &val)
{

    if (esVacio())
        return false;
    NodoAVL<T> *aux = raiz;
    while (aux != NULL && aux->obtenerDato() != val)
    {
        if (val > aux->obtenerDato())
            aux = aux->obtenerHijoDer();
        else if (val < aux->obtenerDato())
            aux = aux->obtenerHijoIzq();
    }
    if (aux == NULL)
        return false;
    else
        return true;
}
template <class T>
void ArbolAVL<T>::preOrden(NodoAVL<T> *inicio)
{
    if (inicio != NULL)
    {
        cout << inicio->obtenerDato() << ", ";
        preOrden(inicio->obtenerHijoIzq());
        preOrden(inicio->obtenerHijoDer());
    }
}
template <class T>
void ArbolAVL<T>::posOrden(NodoAVL<T> *inicio)
{
    if (inicio != NULL)
    {
        posOrden(inicio->obtenerHijoIzq());
        posOrden(inicio->obtenerHijoDer());
        cout << inicio->obtenerDato() << ", ";
    }
}
template <class T>
void ArbolAVL<T>::inOrden(NodoAVL<T> *inicio)
{
    if (inicio != NULL)
    {
        inOrden(inicio->obtenerHijoIzq());
        cout << inicio->obtenerDato() << ", ";
        inOrden(inicio->obtenerHijoDer());
    }
}
template <class T>
void ArbolAVL<T>::nivelOrden(NodoAVL<T> *inicio)
{
    queue<NodoAVL<T>> q;
    if (esVacio())
        cout << "VACIO" << endl;
    else
    {
        cout << raiz->obtenerDato() << ", ";
        encolar(inicio, &q);
        while (!q.empty())
        {
            NodoAVL<T> *aux = &q.front();

            encolar(aux, &q);
            cout << aux->obtenerDato() << ", ";
            q.pop();
        }
    }
}
template <class T>
void encolar(NodoAVL<T> *inicio, queue<NodoAVL<T>> *q)
{
    NodoAVL<T> *hijod = inicio->obtenerHijoDer();
    NodoAVL<T> *hijoi = inicio->obtenerHijoIzq();
    if (hijod == NULL && hijoi == NULL)
        return;
    else if (hijod != NULL && hijoi != NULL)
    {
        q->push((*hijoi));
        q->push((*hijod));
    }
    else if (hijod == NULL)
    {
        q->push((*hijoi));
    }
    else
        q->push((*hijod));
}
template <class T>
NodoAVL<T> *ArbolAVL<T>::getRaiz()
{
    return raiz;
}
template <class T>
int ArbolAVL<T>::altura()
{
    return altura(raiz);
}
template <class T>
int ArbolAVL<T>::tamano()
{
    return tamano(raiz);
}
template <class T>
bool ArbolAVL<T>::insertar(T &val)
{
    NodoAVL<T> *a = insertar(val, raiz);
    if (a == NULL)
        return false;
    else
    {
        raiz = balance(a);
        return true;
    }
}
template <class T>
void ArbolAVL<T>::preOrden()
{
    preOrden(raiz);
}
template <class T>
void ArbolAVL<T>::inOrden()
{
    inOrden(raiz);
}
template <class T>
void ArbolAVL<T>::posOrden()
{
    posOrden(raiz);
}
template <class T>
void ArbolAVL<T>::nivelOrden()
{
    nivelOrden(raiz);
}

template <class T>
void ArbolAVL<T>::inOrdenL(NodoAVL<T> *inicio, list<T> &l)
{
    if (inicio != NULL)
    {
        inOrdenL(inicio->obtenerHijoIzq(),l);
        l.push_back(inicio->obtenerDato());
        inOrdenL(inicio->obtenerHijoDer(),l);
    }

}
template <class T>
void ArbolAVL<T>::inOrdenL(list<T> &l){
    inOrdenL(this->raiz,l);
}
template <class T>
void ArbolAVL<T>::valorMax(T &mayor){
  
    if(!esVacio()){
        NodoAVL<T> *valMax = this->raiz;
        while(valMax->obtenerHijoDer() != NULL){
            valMax = valMax->obtenerHijoDer();
        }
        mayor = valMax->obtenerDato();
    }

}
