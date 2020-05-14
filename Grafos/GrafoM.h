#ifndef __GRAFOM__H__
#define __GRAFOM__H__

#include <vector>
#include <utility>

using namespace std;

typedef long long unsigned ll;

template <class T, class C>
class GrafoM
{
protected:
    vector <vector<C>> matAristas;
    vector<T> vertices;
    ll numVertices = 0;

public:
    int  cantiVertices();
    int  cantiAristas();
    void insertarVertice(T Vertice);
    void insertarArista(T origen, T destino, C peso);
    ll   buscarVertice(T vertice);
    bool buscarArista(ll origen, ll destino);
    void eliminarVertice(T vertice);
    void eliminarArista(T origen, T destino);
    void recorridoPlano();
    void imprimirGrafo();
    void recorridoDFS(T inicio);
    void recorridoDFS(ll inicio, bool *visitados);
    void recorridoBFS(T inicio);
    void prim(T inicio);
    void menorPeso(vector<pair<int,int>> &vistos);
    void dijkstra(T inicio);
};

#include "GrafoM.hxx"
#endif