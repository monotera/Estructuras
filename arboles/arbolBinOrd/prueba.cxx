#include <iostream>
#include "ArbolBinario.h"
using namespace std;

int main()
{
    ArbolBinario<int> a;
    cout << a.getRaiz() << endl;
    int x = 5;
    a.insertar(x);
    x = 15;
    a.insertar(x);
    x = 10;
    a.insertar(x);
    x = 7;
    a.insertar(x);
    x = 3;
    a.insertar(x);
    a.inOrden();
    cout << endl;
    a.posOrden();
    cout << endl;
    a.nivelOrden();
    cout << endl;
    a.preOrden();
    cout << endl;
    if (a.insertar(x))
        cout << "FAIL" << endl;
    x = -5;
    a.insertar(x);
    x = 0;
    a.insertar(x);
    x = 4;
    a.insertar(x);
    x = 16;
    a.insertar(x);
    x = 7;
    a.insertar(x);
    x = -8;
    a.insertar(x);
    x = -1;
    a.insertar(x);
    x = 11;
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
    x = 15;
    a.eliminar(x);

    a.inOrden();
    cout << endl;
    a.posOrden();
    cout << endl;
    a.nivelOrden();
    cout << endl;
    a.preOrden();
}
