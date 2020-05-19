#include <iostream>
#include <queue>
#include <algorithm>

template <class T, class C>
C GrafoM<T, C>::obtenerCosto(unsigned long i, unsigned long j)
{
    return matAristas[i][j];
}

template <class T, class C>
int GrafoM<T, C>::cantiVertices()
{
    return this->numVertices;
}
template <class T, class C>
int GrafoM<T, C>::cantiAristas()
{
    int cantiAristas = 0;

    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (matAristas[i][j] != 0)
            {
                cantiAristas++;
            }
        }
    }
    return cantiAristas;
}
template <class T, class C>
void GrafoM<T, C>::insertarVertice(T vertice)
{
    if (numVertices == 0 || buscarVertice(vertice) == -1)
    {
        this->vertices.push_back(vertice);
        for (int i = 0; i < numVertices; ++i)
        {
            vector<C> *aux = &matAristas[i];
            aux->push_back(0);
        }
        numVertices = this->vertices.size();
        vector<C> nuevaFila(numVertices, 0);
        matAristas.push_back(nuevaFila);
    }
}
template <class T, class C>
ll GrafoM<T, C>::buscarVertice(T vertice)
{
    ll indice = -1;
    for (int i = 0; i < numVertices && indice == -1; i++)
    {
        if (vertice.X == vertices[i].X && vertice.Y == vertices[i].Y)
            indice = i;
    }
    return indice;
}
template <class T, class C>
T GrafoM<T, C>::obtenerVertice(ll indice)
{
    return vertices[indice];
}
template <class T, class C>
void GrafoM<T, C>::insertarArista(ll indOr, ll inDes, C peso)
{
    if (indOr != -1 && inDes != -1)
    {
        if (!buscarArista(indOr, inDes))
        {
            matAristas[indOr][inDes] = peso;
        }
    }
}
template <class T, class C>
bool GrafoM<T, C>::buscarArista(ll origen, ll destino)
{
    bool encontrado = false;
    if (matAristas[origen][destino] != 0)
    {
        encontrado = true;
    }
    return encontrado;
}
template <class T, class C>
void GrafoM<T, C>::generarCaminos(vector<T> &nuevosV, vector<T> &pred, vector<C> &nuevasA, vector<vector<unsigned long>> &caminos)
{
    vector<ll> indicesV;
    vector<unsigned long> camino;
    bool encontrado = false;
    for (int i = 0; i < nuevosV.size(); i++)
    {
        indicesV.push_back(buscarVertice(nuevosV[i]));
    }
    for (int i = 0; i < nuevosV.size(); i++)
    {
        camino.clear();
        int indice = i;
        camino.push_back(i);
        while (indice != 0)
        {
            int aux = -1;

            for (int j = 0; j < nuevosV.size() && !encontrado; j++)
            {
                if (indice == indicesV[j])
                {
                    encontrado = true;
                    aux = j;
                }
            }
            indice = buscarVertice(pred[aux]);
            camino.push_back(indice);
            encontrado = false;
        }
        caminos.push_back(camino);
    }
}
template <class T, class C>
vector<vector<unsigned long>> GrafoM<T, C>::prim(ll inicio)
{
    vector<T> nuevosV;
    vector<T> pred;
    vector<C> nuevasA;
    vector<pair<int, int>> listaMenores;
    vector<vector<unsigned long>> caminos;
    nuevosV.push_back(vertices[inicio]);
    pred.push_back(vertices[inicio]);
    nuevasA.push_back(0);
    menorPeso(listaMenores);
    int in = 0;
    bool ori = false, des = false;

    while (nuevosV.size() != numVertices)
    {
        pair<int, int> aux = listaMenores[in];
        for (int j = 0; j < nuevosV.size() && !des; ++j)
        {
            if (vertices[aux.first].X == nuevosV[j].X && vertices[aux.first].Y == nuevosV[j].Y)
            {
                ori = true;
            }
            if (vertices[aux.second].X == nuevosV[j].X && vertices[aux.second].Y == nuevosV[j].Y)
            {
                des = true;
            }
        }
        if (ori && !des)
        {
            nuevosV.push_back(vertices[aux.second]);
            pred.push_back(vertices[aux.first]);
            listaMenores.erase(listaMenores.begin() + in);
            in = -1;
            nuevasA.push_back(matAristas[aux.first][aux.second]);
        }
        in++;
        des = false;
        ori = false;
    }
    generarCaminos(nuevosV, pred, nuevasA, caminos);
    return caminos;
}
template <class T, class C>
void GrafoM<T, C>::menorPeso(vector<pair<int, int>> &vistos)
{
    pair<int, int> aux;
    vector<C> temp;
    C menorPeso = 100000;
    bool existe = false;
    int cantiA = cantiAristas();
    while (vistos.size() != cantiA)
    {
        for (int i = 0; i < numVertices; i++)
        {
            temp = matAristas[i];
            for (int j = 0; j < numVertices; j++)
            {

                if (temp[j] != 0)
                {
                    if (temp[j] <= menorPeso)
                    {
                        for (int k = 0; k < vistos.size(); k++)
                        {
                            pair<int, int> aux2 = vistos[k];
                            if (aux2.first == i && aux2.second == j)
                            {
                                existe = true;
                            }
                        }
                        if (!existe)
                        {
                            menorPeso = matAristas[i][j];
                            aux.first = i;
                            aux.second = j;
                        }
                    }
                    existe = false;
                }
            }
        }
        vistos.push_back(aux);
        menorPeso = 100000;
    }
}
template <class T, class C>
vector<vector<unsigned long>> GrafoM<T, C>::dijkstra(ll inicio)
{
    vector<T> s;
    vector<T> pred;
    vector<C> dist;
    vector<vector<unsigned long>> caminos;
    vector<T> q = vertices;
    for (int i = 0; i < numVertices; i++)
    {
        dist.push_back(100000);
    }
    pred.resize(numVertices);
    pred[inicio] = obtenerVertice(inicio);
    dist[inicio] = 0;
    bool encontrado = false;
    while (!q.empty())
    {
        int menor = 100001;
        int ori;
        for (int i = 0; i < dist.size(); i++)
        {
            for (int k = 0; k < s.size() && !encontrado; ++k)
            {
                if (s[k].X == vertices[i].X && s[k].Y == vertices[i].Y)
                {
                    encontrado = true;
                }
            }
            if (!encontrado)
            {
                if (dist[i] < menor)
                {
                    menor = dist[i];
                    ori = i;
                }
            }
            encontrado = false;
        }
        s.push_back(vertices[ori]);
        int indice = 0;
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i].X == vertices[ori].X && q[i].Y == vertices[ori].Y)
            {
                indice = i;
            }
        }
        q.erase(q.begin() + indice);
        vector<C> temp = matAristas[ori];
        for (int i = 0; i < numVertices; i++)
        {
            if (temp[i] != 0)
            {
                if (dist[i] > (dist[ori] + matAristas[ori][i]))
                {
                    dist[i] = dist[ori] + matAristas[ori][i];
                    pred[i] = vertices[ori];
                }
            }
        }
    }
    generarCaminos(vertices, pred, dist, caminos);
    return caminos;
}