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
    nodoGeneral<T>* nodo = new nodoGeneral<T>;
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
template <class T>
bool arbolGeneral<T>::insertarNodo(T padre, T n)
{
    //Si el arbol esta vacio:
    //crear nuevo nodo, asignar el dato, poner ese nodo como raiz
    
    //Si hay al menos un nodo en el arbol:
    //-Revisar el nodo donde estoy para ver si coincide con padre
    //-Si es padre, insertar ahi el nuevo hijo
    //-Si no es el padre, revisar cada nodo hijo y llamar a insertar alli
    //

}
template <class T>
bool arbolGeneral<T>::eliminarNdo(T n)
{
    //Verificar que el arbol no este vacio

    //Si es la raiz la que quiero eliminar
    //-Hacer delete a raiz
    //-Poner raiz en nulo

    //Si hay almenos un nodo en el arbol:
    //-Si alguno de los hijos es el que quiero eliminar
    //-Si ninguno es el que quiero eliminar: 
    //-revisar cada nodo hijo y llamar a eliminar alli

}
template <class T>
bool arbolGeneral<T>::buscar(T n)
{
    //Verificar que el arbol no este vacio
    //Comparo dato en el nodo actual con dato parametro
    //Si es ese, retorno que lo encontre
    //Si no, para cada nodo hijo hacer el llamado a buscar

}
template <class T>
int arbolGeneral<T>::altura()
{
    if(this->esVacio())
        return -1;
    else
    {
        return this->altura(this->raiz);
    }
    

}
template <class T>
int arbolGeneral<T>::altura(nodoGeneral<T>* nodo)
{
    int alt = -1;

    if(nodo->esHoja()){
        alt = 0;
    }
    else
    {
        list<nodoGeneral<T>*>::iterator it;
        for(it = nodo->desc.begin(); it!= nodo->desc.end(); ++it){
            alth = this->altura(*it);
            if(alt < alth+1)
                alt = alth+1;   
        }
    }   

    return alt;
}
template <class T>
unsigned int arbolGeneral<T>::tamano()
{
    //Si el arbol esta vacio, retorno 0
    //para cada uno de los hijos, llamo a tamano
    //acumulo esos tamanos en una variable 
    //retorno ese valor acumulado + 1
}
template <class T>
void arbolGeneral<T>::preOrder()
{
    if(!this->vacio())
        this->preOrder(this->raiz);

}
template <class T>
void arbolGeneral<T>::preOrder(nodoGeneral<T>* nodo){
    cout << nodo->obtenerDato() << "    ";

    list<nodoGeneral<T>*>::iterator it;
    for(it = nodo->desc.begin(); it!= nodo->desc.end(); ++it){
        this->preOrder(*it);
    }
}
template <class T>
void arbolGeneral<T>::posOrden()
{
    //Llamar a pos orden sobre cada hijo
    //imprimir en pantalla el daro del nodo actual

}
template <class T>
void arbolGeneral<T>::nivelOrden()
{
    //NO ES RECURRENTE
    //ubicarme en la raiz 
    //poner la raiz en una cola
    //-Hacer un ciclo mientras haya algo en la cola
    //-imprimo su dato
    //-inserto en la cola todos sus hijos 
}
