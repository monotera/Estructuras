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
    g.insertarVertice('f');
    g.insertarVertice('g');
    g.insertarVertice('h');
    g.insertarVertice('i');
    g.insertarVertice('j');
    g.insertarVertice('k');
    g.insertarVertice('l');
    g.insertarArista('a','c',0);
    g.insertarArista('a','d',0);
    g.insertarArista('a','j',0);
    g.insertarArista('b','a',0);
    g.insertarArista('b','d',0);
    g.insertarArista('b','e',0);
    g.insertarArista('b','h',0);
    g.insertarArista('b','j',0);
    g.insertarArista('b','l',0);
    g.insertarArista('c','i',0);
    g.insertarArista('c','k',0);
    g.insertarArista('d','i',0);
    g.insertarArista('e','h',0);
    g.insertarArista('f','e',0);
    g.insertarArista('h','g',0);
    g.insertarArista('i','k',0);
    g.insertarArista('j','c',0);
    g.insertarArista('j','g',0);
    g.insertarArista('l','d',0);
    g.insertarArista('l','f',0);
    g.imprimirGrafo();
    cout << "RECORRIDO DFS" << endl;
    g.recorridoDFS('b');
    cout << "\nRECORRIDO BFS" << endl;
    g.recorridoBFS('b');
}