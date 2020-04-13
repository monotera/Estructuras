#include <iostream>
#include "ArbolAVL.h"
using namespace std;

int main()
{
    ArbolAVL<int> a;
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
    a.inOrden();
    cout << endl;
    a.posOrden();
    cout << endl;
    a.nivelOrden();
    cout << endl;
    a.preOrden();
    cout << endl;
    a.insertar(x);
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
    x = 10;
    a.eliminar(x);

    a.inOrden();
    cout << endl;
    a.posOrden();
    cout << endl;
    a.nivelOrden();
    cout << endl;
    a.preOrden();
    cout << endl
         << a.altura() << endl;
    cout << a.tamano() << endl;

    cout << "ELIMINACION" << endl
         << endl;
    x = 5;
    a.eliminar(x);

    a.inOrden();
    cout << endl;
    a.posOrden();
    cout << endl;
    a.nivelOrden();
    cout << endl;
    a.preOrden();
    cout << endl
         << a.altura() << endl;
    cout << a.tamano() << endl;
    a.valorMax(x);
    cout << x<<endl;

}
