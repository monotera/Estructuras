#include <iostream>
#include <vector>
#include "GrafoM.h"

using namespace std;

int main()
{
    GrafoM<char, int> g;

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
    g.insertarArista('a','c',1);
    g.insertarArista('a','d',1);
    g.insertarArista('a','j',1);
    g.insertarArista('b','a',1);
    g.insertarArista('b','d',1);
    g.insertarArista('b','e',1);
    g.insertarArista('b','h',1);
    g.insertarArista('b','j',1);
    g.insertarArista('b','l',1);
    g.insertarArista('c','i',1);
    g.insertarArista('c','k',1);
    g.insertarArista('d','i',1);
    g.insertarArista('e','h',1);
    g.insertarArista('f','e',1);
    g.insertarArista('h','g',1);
    g.insertarArista('i','k',1);
    g.insertarArista('j','c',1);
    g.insertarArista('j','g',1);
    g.insertarArista('l','d',1);
    g.insertarArista('l','f',1);
    g.imprimirGrafo();
    cout << "RECORRIDO DFS" << endl;
    g.recorridoDFS('b');
    cout << "\nRECORRIDO BFS" << endl;
    g.recorridoBFS('b');
}
