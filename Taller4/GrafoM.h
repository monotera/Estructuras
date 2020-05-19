#ifndef __GRAFOM__H__
#define __GRAFOM__H__

#include <vector>
#include <utility>
#define INF 2000
using namespace std;

typedef long long unsigned ll;

template <class T, class C>
class GrafoM
{
protected:
    vector<vector<C>> matAristas;
    vector<T> vertices;
    ll numVertices = 0;

public:
    int cantiVertices();
    int cantiAristas();
    void insertarVertice(T Vertice);
    void insertarArista(ll origen, ll destino, C peso);
    T obtenerVertice(ll indice);
    ll buscarVertice(T vertice);
    bool buscarArista(ll origen, ll destino);
    vector<vector<unsigned long>> prim(ll inicio);
    void generarCaminos(vector<T> &nuevosV, vector<T> &pred, vector<C> &nuevasA, vector<vector<unsigned long>> &caminos);
    void menorPeso(vector<pair<int, int>> &vistos);
    C obtenerCosto(unsigned long i, unsigned long j);
    vector<vector<unsigned long>> dijkstra(ll inicio);
};

#include "GrafoM.hxx"
#endif