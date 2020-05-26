#ifndef __GRAFOM__H__
#define __GRAFOM__H__

#include <vector>
#include <utility>
#include <stack>
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
    void reiniciarGrafo();
    int  cantiVertices();
    int  cantiAristas();
    void insertarVertice(T Vertice);
    void insertarArista(T origen, T destino, C peso);
    ll   buscarVertice(T vertice);
    T    obtenerVertice(ll indice);
    bool buscarArista(ll origen, ll destino);
    void eliminarVertice(T vertice);
    void eliminarArista(T origen, T destino);
    void recorridoPlano();
    void imprimirGrafo();
    void recorridoDFS(T inicio);
    bool tieneCiclo();
    bool tieneCicloR(ll inicio,bool *visitados,vector<ll> &stack);
    void recorridoDFS(ll inicio, bool *visitados);
    void recorridoBFS(T inicio);
    void recorridoDFSpila(T inicio);
    void prim(T inicio,vector<T> &camino,vector<T> &predecesor ,vector<C> &pesos);
    void menorPeso(vector<pair<int,int>> &vistos);
    void dijkstra(T inicio, vector<T> &s, vector<T> &pred,  vector<C> &dist);
    vector<C**> floydWarshall();
    vector<T> caminoFloyd(vector<C**> floyd, T ori,T destino);
    vector<vector<vector<T>>> caminosFloyd(vector<C**> floyd);
    vector<T> generarCamino(T ori,T destino);
    vector<T> obtenerVeci(T origen);
    int buscarCordenadas(int x, int y);
    
};

#include "GrafoM.hxx"
#endif