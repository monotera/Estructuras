#include <iostream>
#include <list>
#include <string>
#include "archivo.h"
#include "sistema.h"

using namespace std;

archivo sistema::getArchivo(){
    return arch;
}
int sistema::cargarArchivo(string nombre){
    return -1;
}
int sistema::guardar(string nombre){
    return -1;
}