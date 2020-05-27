#include <iostream>
#include "sistema.h"
#include <math.h>
#include "NodoGrafo.h"
using namespace std;

int main(){
    char i;
    sistema sys;
    sys.cargarArchivo("prue.fa");
    //sys.generarGrafo("24.6jsd12.Tut");
    sys.ruta_mas_corta("Loach", 9,29,2,9);
    sys.base_remota("Loach",1,0);







    
    /*sys.cargarArchivo("AligSeq85678.fa");
    cout << sys.conteo() << endl;
    sys.enmascarar("TTAC");
    //sys.cifrar("o.fabin");
    //sys.desCifrar("o.fabin");
    sys.guardar("rest.fa");*/
}