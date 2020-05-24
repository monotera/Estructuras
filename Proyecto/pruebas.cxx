#include <iostream>
#include "sistema.h"
using namespace std;

int main(){
    sistema sys;
    sys.cargarArchivo("in_01.fa");
    cout << sys.conteo() << endl;
    sys.cifrar("o.fabin");
    sys.desCifrar("o.fabin");
    sys.guardar("rest.fa");
}