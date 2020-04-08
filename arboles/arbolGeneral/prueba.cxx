#include <iostream>
#include "arbolGeneral.h"

int main()
{
    int valor1 = 15;
    bool resul;
    arbolGeneral<int> miArbol(valor1);

    int valor2 = 10;
    resul = miArbol.insertarNodo(valor1, valor2);
    valor2 = 45;
    resul = miArbol.insertarNodo(valor1, valor2);
    valor2 = 25;
    resul = miArbol.insertarNodo(valor1, valor2);

    valor1 = 10;
    valor2 = 12;
    resul = miArbol.insertarNodo(valor1, valor2);
    valor2 = 16;
    resul = miArbol.insertarNodo(valor1, valor2);

    valor1 = 45;
    valor2 = 30;
    resul = miArbol.insertarNodo(valor1, valor2);
    valor2 = 35;
    resul = miArbol.insertarNodo(valor1, valor2);

    valor1 = 25;
    valor2 = 34;
    resul = miArbol.insertarNodo(valor1, valor2);

    valor1 = 34;
    valor2 = 52;
    resul = miArbol.insertarNodo(valor1, valor2);
    std::cout << "\nRecorrido en preorden: ";
    miArbol.preOrder();
    std::cout << "\nRecorrido en posorden: ";
    miArbol.posOrden();
    std::cout << "Recorrido por niveles: ";
    miArbol.nivelOrden();

    std::cout << "Altura: " << miArbol.altura() << std::endl;
    std::cout << "Tamaño: " << miArbol.tamano() << std::endl;
    valor2 = 34;
    if (miArbol.buscar(valor2))
        std::cout << "Valor " << valor2 << " se encuentra en el árbol. " << std::endl;
    else
        std::cout << "Valor " << valor2 << " no se encuentra en el árbol. " << std::endl;

    valor2 = 50;
    if (miArbol.buscar(valor2))
        std::cout << "Valor " << valor2 << " se encuentra en el árbol. " << std::endl;
    else
        std::cout << "Valor " << valor2 << " no se encuentra en el árbol. " << std::endl;

    resul = miArbol.eliminarNdo(15);

    std::cout << "Recorrido en preorden: ";
    miArbol.preOrder();
    std::cout << "Recorrido en posorden: ";
    miArbol.posOrden();
    std::cout << "Recorrido por niveles: ";
    miArbol.nivelOrden();

    std::cout << "Altura: " << miArbol.altura() << std::endl;
    std::cout << "Tamaño: " << miArbol.tamano() << std::endl;
}