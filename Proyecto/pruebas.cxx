#include <iostream>
#include "sistema.h"
using namespace std;

int main(){
    sistema sys;
    sys.cargarArchivo("in_00.fa");
    cout << sys.conteo() << endl;
    //sys.crearFa();
    //sys.cifrar("o.fabin");
    //sys.desCifrar("o.fabin");
    cout << sys.conteo();
    sys.listar_secuencias();
    sys.guardar("fail.fa");
}