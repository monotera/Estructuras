#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <string.h>
#include "archivo.h"
#include "sistema.h"

using namespace std;



archivo sistema::getArchivo(){
    return arch;
 }
 /*-1  = el archivo no se pudo abrir
    0  = el archivo esta vacio
    1  = el archivo tiene una secuencia
    2 o mayor = el archivo tiene n secuencias*/
int sistema::cargarArchivo(string nombre){

    string line;
    ifstream myFile(nombre);
    if(myFile.is_open()){
        int cont = 0;
        secuencia sec;
        arch.setNombreArchivo(nombre);
        getline(myFile, line);
        if(line.find(">") != string::npos){
            sec.setDescripcion(line);
        }
        while(getline(myFile, line)){
            if(line.find(">") != string::npos){
                if(sec.getDescripcione().size() > 0){
                    arch.agregarSecuencia(sec);
                    sec.borrarLineas();
                    cont ++;
                }
                sec.setDescripcion(line);
            }
            else    
                sec.agregarLinea(line);
        }
        if(sec.getDescripcione().size() > 0){
            arch.agregarSecuencia(sec);
            cont++;
        }
       return cont;
        
    }
    return -1;

}
int sistema::conteo(){
    return arch.getTamaSec();
}
int sistema::listar_secuencias(){
    return arch.listar_sec();

}
int sistema::enmascarar(string sub){
    return arch.enmascarar(sub);
}
int sistema::guardar(string nombre){
    return -1;
}
string sistema::getNombre(){
    return  arch.getNombreArchivo();
}

int sistema::esSubSecuencia(string sub){
    return arch.esSubSecuencia(sub);
}

string sistema::histograma(string desc){
    return arch.histograma(desc);
}