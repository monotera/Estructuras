#include <iostream>
#include <list>
#include<string>
#include "secuencia.h"
#include "archivo.h"

using namespace std;

int archivo::archivos(){
    return -1;
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
void archivo::agregarSecuencia(secuencia nuevaSec){
   this->secuencias.push_back(nuevaSec);
}
int archivo::listarSecuencias(){
    return -1;
}
int archivo::conteo(){
    return -1;
}
int archivo::getTamaSec(){
    return this->secuencias.size();
}
int archivo::listar_sec(){
    if(secuencias.size() > 0){
        int sec_incompleta;
        list <secuencia> :: iterator it;
        for(it = secuencias.begin(); it != secuencias.end(); it++){
            sec_incompleta = it->setCantiBase(); 
            imprimirSec(*it,sec_incompleta);
                
        }
        return 0;
    }
    return -1;
}
void archivo::imprimirSec(secuencia sec, int sec_incompleta){
    cout <<endl<< sec.getDescripcione() << endl;
    list <string> temp = sec.getLineas();
    list <string> :: const_iterator it;
    for(it = temp.begin(); it != temp.end(); it++){
        cout << *it << endl;
    }
    if(sec_incompleta == 0)
        cout << "Secuencia " << sec.getDescripcione() << " contiene " << sec.getCantiBase() <<" bases"<<endl;
    else if (sec_incompleta == -1)
        cout << "Secuencia " << sec.getDescripcione() << " contiene al menos " << sec.getCantiBase() <<" bases"<<endl;
}

int archivo::esSubSecuencia(string sub){
    int resp = 0;
    list<secuencia>::iterator it = secuencias.begin();
    for(;it!=secuencias.end();it++)
        resp+=(*it).esSubSecuencia(sub);
    return resp;
}
/*histograma(Pdescripcion), Obtiene el histograma de la secuencia con la descripcion dada, en caso de que exista*/