#include "arbolBinario.h"
#include <iostream> 

using namespace std;

template <class T>
bool arbolBinario<T>::esVacio(){
    return true;
}
/*template <class T>
T& arbolBinario<T>::datoRaiz(){

}*/
template <class T>
int arbolBinario<T>::altura(){
    return -1;
}
template <class T>
int arbolBinario<T>::tamano(){
    return -1;
}
template <class T>
bool arbolBinario<T>::insertarIzq(T& val, nodoBinario<T> *padre){
    return true;
}
template <class T>
bool arbolBinario<T>::insertarDer(T& val, nodoBinario<T> *padre){
    return true;
}
template <class T>
bool arbolBinario<T>::buscar(T& val){
    return true;
}
template <class T>
void arbolBinario<T>::preOrden(){
    
}

