#include "ArbolBinario.h"
#include <queue>
#include <iostream>
#include <cstddef>

using namespace std;
template <class T>
ArbolBinario<T>::ArbolBinario()
{
    raiz = NULL;
}
template <class T>
bool ArbolBinario<T>::esVacio()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}
template <class T>
T ArbolBinario<T>::datoRaiz()
{
    if (!esVacio())
        return raiz->obtenerDato();
}
template <class T>
int ArbolBinario<T>::altura(NodoBinario<T> *inicio)
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
int ArbolBinario<T>::tamano(NodoBinario<T> *inicio)
{
    if (esVacio())
        return 0;
    NodoBinario<T> *hijod = inicio->obtenerHijoDer();
    NodoBinario<T> *hijoi = inicio->obtenerHijoIzq();
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
bool ArbolBinario<T>::insertar(T &val)
{
    bool duplicado = false;
    bool ins = false;
    if (esVacio())
    {
        NodoBinario<T> *nodo = new NodoBinario<T>(val);
        if (nodo != NULL)
        {
            this->raiz = nodo;
            ins = true;
        }
    }
    else
    {
        NodoBinario<T> *aux = this->raiz;
        NodoBinario<T> *padre = this->raiz;
        while (aux != NULL && !duplicado)
        {
            padre = aux;
            if (val > aux->obtenerDato())
                aux = aux->obtenerHijoDer();
            else if (val < aux->obtenerDato())
                aux = aux->obtenerHijoIzq();
            else
                duplicado = true;
        }
        if (!duplicado)
        {
            NodoBinario<T> *nuevo = new NodoBinario<T>(val);
            if (nuevo != NULL)
            {
                if (val > padre->obtenerDato())
                {
                    padre->fijarHijoDer(nuevo);
                }
                else
                {
                    padre->fijarHijoIzq(nuevo);
                }
                ins = true;
            }
        }
    }
    return ins;
}
//comparar con dato en nodo para saber por donde bajar
//si val esta en el arbol, verifica la situacion
//1) Nodo hoja => borrarlo
//2) Solo un nodo => usar hijo para remplazar nodo
//3) Nodo con dos hijos => usar max del sub-arbol izq
template <class T>
bool ArbolBinario<T>::eliminar(T &val)
{
    bool elim = false;
    if (!this->esVacio())
    {
        bool encontrado = false;
        NodoBinario<T> *aux = this->raiz;
        NodoBinario<T> *padre = this->raiz;
        while (aux != NULL && !encontrado)
        {
            padre = aux;
            if (val > aux->obtenerDato())
                aux = aux->obtenerHijoDer();
            else if (val < aux->obtenerDato())
                aux = aux->obtenerHijoIzq();
            if (aux != NULL)
            {
                if (aux->obtenerDato() == val)
                    encontrado = true;
            }
        }
        if (encontrado)
        {
            //Si es hoja
            if (aux->obtenerHijoDer() == NULL && aux->obtenerHijoIzq() == NULL)
            {
                //Si el nodo que quiero eliminar esta a la derecha del padre
                if (aux->obtenerDato() > padre->obtenerDato())
                {
                    delete aux;
                    padre->fijarHijoDer(NULL);
                    aux = NULL;
                }
                //Si el nodo que quiero eliminar esta a la izq del padre
                else
                {
                    delete aux;
                    padre->fijarHijoIzq(NULL);
                    aux = NULL;
                }
            }
            //Si tiene dos hijos
            else if (aux->obtenerHijoDer() != NULL && aux->obtenerHijoIzq() != NULL)
            {
                NodoBinario<T> *izMax = aux->obtenerHijoIzq();
                NodoBinario<T> *padreMax = aux->obtenerHijoIzq();
                //Ciclo para obtener el nodo maximo del sub-arbol izquierdo y su padre
                while (izMax->obtenerHijoDer() != NULL)
                {
                    padreMax = izMax;
                    izMax = izMax->obtenerHijoDer();
                }
                if (izMax == aux->obtenerHijoIzq())
                {
                    izMax->fijarHijoDer(aux->obtenerHijoDer());
                    //Si el nodo que quiero eliminar esta a la derecha del padre
                    if (val > padre->obtenerDato())
                    {
                        padre->fijarHijoDer(izMax);
                    }
                    //Si el nodo que quiero eliminar esta a la izq del padre
                    else
                    {
                        padre->fijarHijoIzq(izMax);
                    }
                    //eliminar nodo sobrante
                }
                else
                {
                    izMax->fijarHijoDer(aux->obtenerHijoDer());
                    izMax->fijarHijoIzq(aux->obtenerHijoIzq());
                    if (val > padre->obtenerDato())
                    {
                        padre->fijarHijoDer(izMax);
                    }
                    //Si el nodo que quiero eliminar esta a la izq del padre
                    else
                    {
                        padre->fijarHijoIzq(izMax);
                    }
                    padreMax->fijarHijoDer(NULL);
                }
                delete aux;
                aux = NULL;
            }
            //Preguntar que pasa si el padre solo tiene un hijo, se puede int < NULL?
            //Si tine un hijo
            else
            {
                //Si el nodo que quiero eliminar esta a la derecha del padre
                if (val > padre->obtenerDato())
                {
                    //Si el hijo del nodo que quiero eliminar esta a la izq
                    if (aux->obtenerHijoIzq() != NULL)
                    {
                        padre->fijarHijoDer(aux->obtenerHijoIzq());
                        delete aux;
                        aux = NULL;
                    }
                    //Si el hijo del nodo que quiero eliminar esta a la der
                    else
                    {
                        padre->fijarHijoDer(aux->obtenerHijoDer());
                        delete aux;
                        aux = NULL;
                    }
                }
                //Si el nodo que quiero eliminar esta a la izq del padre
                else
                {
                    //Si el hijo del nodo que quiero eliminar esta a la izq
                    if (aux->obtenerHijoIzq() != NULL)
                    {
                        padre->fijarHijoIzq(aux->obtenerHijoIzq());
                        delete aux;
                        aux = NULL;
                    }
                    //Si el hijo del nodo que quiero eliminar esta a la der
                    else
                    {
                        padre->fijarHijoIzq(aux->obtenerHijoDer());
                        delete aux;
                        aux = NULL;
                    }
                }
            }
            elim = true;
        }
    }
    return elim;
}
template <class T>
bool ArbolBinario<T>::buscar(T &val)
{
    bool encontrado = false;
    if (esVacio())
        return encontrado;
    NodoBinario<T> *aux = this->raiz;
    while (aux != NULL && !encontrado)
    {
        if (val > aux->obtenerDato())
            aux = aux->obtenerHijoDer();
        else if (val < aux->obtenerDato())
            aux = aux->obtenerHijoIzq();
        else
            encontrado = true;
    }
    return encontrado;
}
template <class T>
void ArbolBinario<T>::preOrden(NodoBinario<T> *inicio)
{
    if (inicio != NULL)
    {
        cout << inicio->obtenerDato() << ", ";
        preOrden(inicio->obtenerHijoIzq());
        preOrden(inicio->obtenerHijoDer());
    }
}
template <class T>
void ArbolBinario<T>::posOrden(NodoBinario<T> *inicio)
{
    if (inicio != NULL)
    {
        posOrden(inicio->obtenerHijoIzq());
        posOrden(inicio->obtenerHijoDer());
        cout << inicio->obtenerDato() << ", ";
    }
}
template <class T>
void ArbolBinario<T>::inOrden(NodoBinario<T> *inicio)
{
    if (inicio != NULL)
    {
        inOrden(inicio->obtenerHijoIzq());
        cout << inicio->obtenerDato() << ", ";
        inOrden(inicio->obtenerHijoDer());
    }
}
template <class T>
void ArbolBinario<T>::nivelOrden(NodoBinario<T> *inicio)
{
    if (this->esVacio())
        cout << "VACIO" << endl;
    else
    {
        queue<NodoBinario<T> *> q;
        q.push(this->raiz);
        NodoBinario<T> *nodo;
        while (!q.empty())
        {
            nodo = q.front();
            q.pop();
            cout << nodo->obtenerDato() << ", ";
            if (nodo->obtenerHijoIzq() != NULL)
                q.push(nodo->obtenerHijoIzq());
            if (nodo->obtenerHijoDer() != NULL)
                q.push(nodo->obtenerHijoDer());
        }
    }
}
template <class T>
NodoBinario<T> *ArbolBinario<T>::getRaiz()
{
    return raiz;
}
template <class T>
int ArbolBinario<T>::altura()
{
    return altura(raiz);
}
template <class T>
int ArbolBinario<T>::tamano()
{
    return tamano(raiz);
}
template <class T>
void ArbolBinario<T>::preOrden()
{
    preOrden(raiz);
}
template <class T>
void ArbolBinario<T>::inOrden()
{
    inOrden(raiz);
}
template <class T>
void ArbolBinario<T>::posOrden()
{
    posOrden(raiz);
}
template <class T>
void ArbolBinario<T>::nivelOrden()
{
    nivelOrden(raiz);
}