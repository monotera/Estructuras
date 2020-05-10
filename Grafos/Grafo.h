#ifndef __GRAFO__H__
#define __GRAFO__H__

#include <vector>
#include <utility>

using namespace std;

typedef long long unsigned ll;

template <class T, class C>
class Grafo
{
protected:
    vector<vector<pair<ll, C>>> aristas;
    vector<T> vertices;
    ll numVertices = 0;

public:
    int cantiVertices();
    int cantiAristas();
    void insertarVertice(T Vertice);
    void insertarArista(T origen, T destino, C peso);
    ll buscarVertice(T vertice);
    ll buscarArista(ll origen, ll destino);
    void eliminarVertice(T vertice);
    void eliminarArista(T origen, T destino);
    void recorridoPlano();
    void imprimirGrafo();
    void recorridoDFS(T inicio);
    void recorridoDFS(ll inicio, bool *visitados);
    void recorridoBFS(T inicio);
};

#include "Grafo.hxx"
#endif