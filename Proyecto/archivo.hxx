#include <iostream>
#include <list>
#include<string>
#include "secuencia.h"
#include "archivo.h"
#include <fstream>
#include <algorithm>
using namespace std;


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
int archivo::enmascarar(string sub){
    int resp = 0;
    list<secuencia>::iterator it = secuencias.begin();
    for(;it!=secuencias.end();it++)
        resp+=(*it).enmascarar(sub);
    return resp;
}

int archivo::esSubSecuencia(string sub){
    int resp = 0;
    list<secuencia>::iterator it = secuencias.begin();
    for(;it!=secuencias.end();it++)
        resp+=(*it).esSubSecuencia(sub);
    return resp;
}

string archivo::histograma(string desc){
    string resp = "";
    list<secuencia>::iterator it = secuencias.begin();
    for(;it!=secuencias.end();it++){
        string descUpper = (*it).getDescripcione();
        transform(descUpper.begin(), descUpper.end(), descUpper.begin(), (int (*)(int))std::toupper);
        if(descUpper == desc)
            resp = (*it).histograma();
    }
    return resp;
}
int archivo::guardar(string nombre){

    ofstream arch(nombre + ".fa",ios::out);
    int i = 0;
    if(arch.is_open()){
        list <secuencia> :: iterator it;
        for(it = secuencias.begin(); it != secuencias.end();++it){
            arch << it->getDescripcione()<<endl;
            list <string> :: iterator its;
            list <string> actual = it->getLineas();
            for(its = actual.begin(); its != actual.end(); its++){
                arch << *its << endl;
            }
        }
        return 0;
    }
    return -1;
}
void archivo::borrarSec(){
    this->secuencias.clear();
}