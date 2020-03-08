#include <iostream>
#include <list>
#include<string>
#include "secuencia.h"
#include "archivo.h"

using namespace std;

int archivo::archivos(){

}
string archivo::getNombreArchivo(){
    return this->nombre;
}
void archivo::setNombreArchivo(string nombre){
    this->nombre = nombre;
}
list <secuencia> archivo::getSecuencias(){
    return this->secuencias;
}
void archivo::setSecuencias(list <secuencia> nuevaSec){
   
}
list <string> archivo::getDescripciones(){
    return this->descripcion;
}
void archivo::setDescripciones(list <string> nuevaDesc){
   
}
int archivo::listarSecuencias(){

}
int archivo::conteo(){

}
/*histograma(Pdescripcion), Obtiene el histograma de la secuencia con la descripcion dada, en caso de que exista*/