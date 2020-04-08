#include "arbolGeneral.h"
#include "nodoGeneral.h"

using namespace std;

template <class T>
arbolGeneral<T>::arbolGeneral()
{
    this->raiz = NULL;
}
template <class T>
arbolGeneral<T>::arbolGeneral(T val)
{
    nodoGeneral<T> *nodo = new nodoGeneral<T>;
    nodo->fijarDato(val);
    this->raiz = nodo;
}
template <class T>
arbolGeneral<T>::~arbolGeneral()
{
    delete this->raiz;
    this->raiz = NULL;
}
template <class T>
bool arbolGeneral<T>::esVacio()
{
    return this->raiz == NULL;
}
template <class T>
nodoGeneral<T> *arbolGeneral<T>::obtenerRaiz()
{
    return this->raiz;
}
template <class T>
void arbolGeneral<T>::fijarRaiz(nodoGeneral<T> *nraiz)
{
    this->raiz = nraiz;
}
//Si el arbol esta vacio:
//crear nuevo nodo, asignar el dato, poner ese nodo como raiz
//Si hay al menos un nodo en el arbol:
//-Revisar el nodo donde estoy para ver si coincide con padre
//-Si es padre, insertar ahi el nuevo hijo
//-Si no es el padre, revisar cada nodo hijo y llamar a insertar alli
template <class T>
bool arbolGeneral<T>::insertarNodo(T padre, T n)
{
    bool ins = false;

    if (this->esVacio())
    {
        nodoGeneral<T> *nodo = new nodoGeneral<T>;
        nodo->fijarDato(n);
        this->raiz = nodo;
        ins = true;
    }
    else
    {
        ins = this->raiz->insertarNodo(padre, n);
    }
    return ins;
}
//Verificar que el arbol no este vacio
//Si es la raiz la que quiero eliminar
//-Hacer delete a raiz
//-Poner raiz en nulo
//Si hay almenos un nodo en el arbol:
//-Si alguno de los hijos es el que quiero eliminar
//-Si ninguno es el que quiero eliminar:
//-revisar cada nodo hijo y llamar a eliminar alli
template <class T>
bool arbolGeneral<T>::eliminarNdo(T n)
{
    bool del = false;
    if (!this->esVacio())
    {
        if (n == raiz->obtenerDato())
        {
            delete raiz;
            raiz = NULL;
            del = true;
        }
        else
            del = this->raiz->eliminarNdo(n);
    }

    return del;
}
//Verificar que el arbol no este vacio
//Comparo dato en el nodo actual con dato parametro
//Si es ese, retorno que lo encontre
//Si no, para cada nodo hijo hacer el llamado a buscar
template <class T>
bool arbolGeneral<T>::buscar(T n)
{
    bool encontrado = false;
    if (!this->esVacio())
    {
        encontrado = this->raiz->buscar(n);
    }
    return encontrado;
}
template <class T>
int arbolGeneral<T>::altura()
{
    if (this->esVacio())
        return -1;
    else
    {
        return this->raiz->altura();
    }
}
//Si el arbol esta vacio, retorno 0
//para cada uno de los hijos, llamo a tamano
//acumulo esos tamanos en una variable
//retorno ese valor acumulado + 1
template <class T>
unsigned int arbolGeneral<T>::tamano()
{
    unsigned int tama = 0;
    if (!this->esVacio())
    {
        tama = this->raiz->tamano() + 1;
    }
    return tama;
}
template <class T>
void arbolGeneral<T>::preOrder()
{
    if (!this->esVacio())
        this->raiz->preOrder();
    else
        cout << "El arbol esta vacio" << endl;
    cout << endl;
}
//Llamar a pos orden sobre cada hijo
//imprimir en pantalla el daro del nodo actual
template <class T>
void arbolGeneral<T>::posOrden()
{
    if (!this->esVacio())
        this->raiz->posOrden();
    else
        cout << "El arbol esta vacio" << endl;
    cout << endl;
}
//NO ES RECURRENTE
//ubicarme en la raiz
//poner la raiz en una cola
//-Hacer un ciclo mientras haya algo en la cola
//-imprimo su dato
//-inserto en la cola todos sus hijos
template <class T>
void arbolGeneral<T>::nivelOrden()
{
    if (!this->esVacio())
    {
        for (int i = 0; i <= this->altura(); i++)
            this->raiz->nivelOrden(i, 0);
        std::cout << std::endl;
    }
    else
        std::cout << "Vacío \n";
}
