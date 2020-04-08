#include <iostream>
#include "ArbolBinario.h"
using namespace std;

int main()
{
    ArbolBinario<int> a;
    cout << a.getRaiz() << endl;
    int x = 12;
    a.insertar(x);
    x = 6;
    a.insertar(x);
    x = 14;
    a.insertar(x);
    x = 2;
    a.insertar(x);
    x = 13;
    a.insertar(x);
    x = 8;
    a.insertar(x);
    x = 19;
    a.insertar(x);
    x = 5;
    a.insertar(x);
    x = 1;
    a.insertar(x);
    x = 11;
    a.insertar(x);
    x = 21;
    a.insertar(x);
    x = 10;
    a.insertar(x);
    x = 7;
    a.insertar(x);
    x = 3;
    a.insertar(x);
    x = 15;
    a.insertar(x);
    x = 17;
    a.insertar(x);
    x = 20;
    a.insertar(x);

    cout << a.altura() << endl;
    cout << a.tamano() << endl;

    a.inOrden();
    cout << endl;
    a.posOrden();
    cout << endl;
    a.nivelOrden();
    cout << endl;
    a.preOrden();
    cout << endl;
    cout << "ELIMINACION" << endl
         << endl;
    x = 11;
    a.eliminar(x);
    x = 4;
    a.insertar(x);
    x = 17;
    a.eliminar(x);
    x = 19;
    a.eliminar(x);
    x = 18;
    a.insertar(x);
    x = 9;
    a.eliminar(x);

    a.inOrden();
    cout << endl;
    a.posOrden();
    cout << endl;
    a.nivelOrden();
    cout << endl;
    a.preOrden();
}
