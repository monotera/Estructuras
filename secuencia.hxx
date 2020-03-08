#include "secuencia.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;


int secuencia::getAncho(){
    return this->ancho;
}
void secuencia::setAncho(int ancho){
    this->ancho = ancho;
}
list <string> secuencia::getLineas(){
    return this->linea;
}
void secuencia::agregarLinea(string lineaNueva){
    linea.push_back(lineaNueva);
}
int secuencia::esSubSecuencia(string sub){
    int cant = 0;
    list<string>::iterator it = linea.begin();
    size_t p;
    for(;it != linea.end();it++){
        p = (*it).find(sub);
        while(p!=string::npos){
            cant++;
            p = (*it).find(sub, p+sub.size());
        }
    }
    return cant;
}
int secuencia::enmascarar(string sub){
    return -1;
}
string secuencia::getDescripcione(){
    return this->descripcion;
}
void secuencia::setDescripcion(string nuevaDesc){
   this->descripcion = nuevaDesc;
}
int secuencia::setCantiBase(){
    list <string> :: iterator it;
    long cont = 0;
    int incompleto = 0;
    for(it = linea.begin(); it != linea.end();it++){
            vector <char> linea ((*it).begin(),(*it).end());
            for(int i = 0; i < (*it).length(); ++i){
                if(linea[i] == 'A' || linea[i] == 'C' || linea[i] == 'G' || linea[i] == 'T' || linea[i] == 'U'){
                    cont++;
                }
                if(linea[i] == '-'){
                    incompleto = -1;
                }
        }
    }
    this->cantiBase = cont;
    return  incompleto;
}
int secuencia::getCantiBase(){
    return this->cantiBase;
}
void secuencia::borrarLineas(){
    linea.clear();
}
