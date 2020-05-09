#include <iostream>
#include <vector>
#include "Grafo.h"

using namespace std;

int main()
{
    Grafo<char, int> g;
    g.insertarVertice('a');
    g.insertarVertice('b');
    g.insertarVertice('c');
    g.insertarVertice('d');
    g.insertarVertice('e');
    g.prueba();
    cout << g.cantiVertices() << " " << g.cantiAristas() << endl;
    g.insertarArista('a', 'c', 3);
    g.insertarArista('b', 'c', 1);
    g.insertarArista('b', 'e', 6);
    g.insertarArista('d', 'a', 2);
    g.insertarArista('e', 'c', 5);
    g.prueba();
    cout << g.cantiVertices() << " " << g.cantiAristas() << endl;
    //g.eliminarArista('a','c');
    //g.eliminarArista('b','c');
    //g.eliminarArista('b','e');
    g.eliminarVertice('a');
    g.prueba();
    g.eliminarVertice('b');
    g.prueba();
    g.eliminarVertice('e');
    g.prueba();
    g.eliminarVertice('d');
    g.prueba();
    cout << g.cantiVertices() << " " << g.cantiAristas() << endl;
}