#include <iostream>
#include <vector>
#include "GrafoM.h"
#include <algorithm>

using namespace std;

int main()
{
    GrafoM<int, int> g;

    g.insertarVertice(0);
    g.insertarVertice(1);
    g.insertarVertice(2);
    g.insertarVertice(3);
    g.insertarVertice(4);
    g.insertarVertice(5);
    g.insertarVertice(6);
    g.insertarVertice(7);
    g.insertarArista(0,1,5);
    g.insertarArista(0,7,8);
    g.insertarArista(0,4,9);
    g.insertarArista(1,3,15);
    g.insertarArista(1,2,12);
    g.insertarArista(1,7,4);
    g.insertarArista(2,3,3);
    g.insertarArista(2,6,11);
    g.insertarArista(3,6,9);
    g.insertarArista(4,7,5);
    g.insertarArista(4,5,4);
    g.insertarArista(4,6,20);
    g.insertarArista(5,2,1);
    g.insertarArista(5,6,13);
    g.insertarArista(7,2,7);
    g.insertarArista(7,5,6);
    
    /*g.insertarVertice('s');
    g.insertarVertice('t');
    g.insertarVertice('x');
    g.insertarVertice('y');
    g.insertarVertice('z');
    g.insertarArista('s','t',10);
    g.insertarArista('s','y',5);
    g.insertarArista('t','x',1);
    g.insertarArista('t','y',2);
    g.insertarArista('x','z',4);
    g.insertarArista('y','x',9);
    g.insertarArista('y','t',3);
    g.insertarArista('y','z',2);
    g.insertarArista('z','x',6);
    g.insertarArista('z','s',7);*/

    /*g.insertarVertice('f');
    g.insertarVertice('g');
    g.insertarVertice('h');
    g.insertarVertice('i');
    g.insertarVertice('j');
    g.insertarVertice('k');
    g.insertarVertice('l');
    g.insertarArista('a','c',12);
    g.insertarArista('a','d',19);
    g.insertarArista('a','j',18);
    g.insertarArista('b','a',17);
    g.insertarArista('b','d',16);
    g.insertarArista('b','e',15);
    g.insertarArista('b','h',14);
    g.insertarArista('b','j',13);
    g.insertarArista('b','l',20);
    g.insertarArista('c','i',11);
    g.insertarArista('c','k',84);
    g.insertarArista('d','i',9);
    g.insertarArista('e','h',8);
    g.insertarArista('f','e',7);
    g.insertarArista('h','g',6);
    g.insertarArista('i','k',5);
    g.insertarArista('j','c',4);
    g.insertarArista('j','g',3);
    g.insertarArista('l','d',2);
    g.insertarArista('l','f',1);*/
    g.imprimirGrafo();
    cout << "RECORRIDO DFS" << endl;
    g.recorridoDFS(0);
    cout << "\nRECORRIDO BFS" << endl;
    g.recorridoBFS(0);
   cout<<"\nRECORRIDO PRIM" <<endl;
   g.prim(0);
   cout<<"\nRECORRIDO DIJKSTRA" <<endl;
   g.dijkstra(0);

}
