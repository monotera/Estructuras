#include <iostream>
#include <vector>
#include "GrafoM.h"
#include <algorithm>

using namespace std;

int main()
{
    /*GrafoM<int, int> g;

    g.insertarVertice(1);
    g.insertarVertice(2);
    g.insertarVertice(3);
    g.insertarVertice(4);
    g.insertarVertice(5);
    g.insertarArista(1, 3, 6);
    g.insertarArista(1, 4, 3);
    g.insertarArista(2, 1, 3);
    g.insertarArista(3, 4, 2);
    g.insertarArista(4, 2, 1);
    g.insertarArista(4, 3, 1);
    g.insertarArista(5, 2, 4);
    g.insertarArista(5, 4, 2);
    g.imprimirGrafo();
    vector<int **> m = g.floydWarshall();
    int **path = m[0];
    int **pred = m[1];
    cout << "PATH" << endl;
    for (int i = 0; i < g.cantiVertices(); i++)
    {
        for (int j = 0; j < g.cantiVertices(); j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << "PRED" << endl;
    cout << "      ";
    for (int i = 0; i < g.cantiVertices(); i++)
    {
        cout << i << " ";
    }
    cout <<endl;
    for (int i = 0; i < g.cantiVertices(); i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < g.cantiVertices(); j++)
        {
            cout << pred[i][j] << " ";
        }
        cout << endl;
    }*/

    GrafoM<int, int> g2;
    g2.insertarVertice(1);
    g2.insertarVertice(2);
    g2.insertarVertice(3);
    g2.insertarVertice(4);
    g2.insertarVertice(5);
    g2.insertarArista(1,2,3);
    g2.insertarArista(1,3,8);
    g2.insertarArista(1,5,-4);
    g2.insertarArista(2,5,7);
    g2.insertarArista(2,4,1);
    g2.insertarArista(3,2,4);
    g2.insertarArista(4,3,-5);
    g2.insertarArista(4,1,2);
    g2.insertarArista(5,4,6);
    g2.imprimirGrafo();
    vector<int **> m = g2.floydWarshall();
    int **path = m[0];
    int **pred = m[1];
    cout << "PATH" << endl;
    for (int i = 0; i < g2.cantiVertices(); i++)
    {
        for (int j = 0; j < g2.cantiVertices(); j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << "PRED" << endl;
    cout << "      ";
    for (int i = 0; i < g2.cantiVertices(); i++)
    {
        cout << i << " ";
    }
    cout <<endl;
    for (int i = 0; i < g2.cantiVertices(); i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < g2.cantiVertices(); j++)
        {
            cout << pred[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> camino = g2.caminoFloyd(m,1,4);
    cout <<endl;
    for (int i = 0; i < camino.size(); i++)
    {
        cout << camino[i] <<", ";
    }
    cout <<endl;
    vector<vector<vector<int>>> caminos = g2.caminosFloyd(m);
    for (int i = 0; i < caminos.size(); i++)
    {
        vector<vector<int>> aux = caminos[i];
        for (int j = 0; j < aux.size(); j++)
        {
            cout << g2.obtenerVertice(i) << "-->" << g2.obtenerVertice(j) <<endl;
            cout << "PESO ===> " << path[i][j]<<endl;
            cout << "CAMINO ===> ";
            vector<int> cam = aux[j];
            for (int k = 0; k < cam.size(); k++)
            {
                cout << cam[k] <<" ";
            }
            cout <<endl;
        }
    }
    
}
