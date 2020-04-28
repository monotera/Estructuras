#include <iostream>
#include "sistema.h"
using namespace std;

int main(){
    sistema sys;
    sys.cargarArchivo("asd.fa");
    cout << sys.conteo() << endl;
    //sys.crearFa();
    sys.cifrar();
    sys.desCifrar("pru.bin");
}