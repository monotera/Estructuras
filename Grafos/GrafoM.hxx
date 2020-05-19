#include <iostream>
#include <queue>
#include <algorithm>
#define INF 2000

template <class T, class C>
int GrafoM<T, C>::cantiVertices()
{
    return this->numVertices;
}
template <class T, class C>
T GrafoM<T, C>::obtenerVertice(ll indice)
{
    return vertices[indice];
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
void GrafoM<T, C>::insertarArista(T origen, T destino, C peso)
{
    ll indOr = buscarVertice(origen);
    ll inDes = buscarVertice(destino);
    if (indOr != -1 && inDes != -1)
    {
        if (!buscarArista(indOr, inDes))
        {
            matAristas[indOr][inDes] = peso;
        }
    }
}
template <class T, class C>
ll GrafoM<T, C>::buscarVertice(T vertice)
{
    ll indice = -1;
    for (int i = 0; i < numVertices && indice == -1; i++)
    {
        if (vertice == vertices[i])
            indice = i;
    }
    return indice;
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
void GrafoM<T, C>::imprimirGrafo()
{
    cout << endl;
    cout << "    ";
    for (int i = 0; i < numVertices; i++)
    {
        cout << vertices[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < numVertices; ++i)
    {
        cout << vertices[i] << "-> ";
        for (int j = 0; j < numVertices; j++)
        {
            cout << matAristas[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
template <class T, class C>
void GrafoM<T, C>::recorridoPlano()
{
    for (int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i] << ", ";
    }
    cout << endl;
}
template <class T, class C>
void GrafoM<T, C>::eliminarVertice(T vertice)
{
    ll ver = buscarVertice(vertice);
    if (ver != -1)
    {
        vertices.erase(vertices.begin() + ver);
        numVertices = vertices.size();
        vector<C> *aux = &matAristas[ver];
        aux->clear();
        matAristas.erase(matAristas.begin() + ver);
        for (int i = 0; i < numVertices; i++)
        {
            aux = &matAristas[i];
            aux->erase(aux->begin() + ver);
        }
    }
}
template <class T, class C>
void GrafoM<T, C>::eliminarArista(T origen, T destino)
{
    ll ori = buscarVertice(origen);
    ll des = buscarVertice(destino);
    if (ori != -1 && des != -1)
    {
        if (buscarArista(ori, des))
        {
            matAristas[ori][des] = 0;
        }
    }
}
template <class T, class C>
void GrafoM<T, C>::recorridoDFS(T inicio)
{
    bool visitados[vertices.size()] = {0};
    ll in = buscarVertice(inicio);
    if (in != -1)
        recorridoDFS(in, visitados);
    else
        cout << "El dato no existe" << endl;
}
template <class T, class C>
void GrafoM<T, C>::recorridoDFS(ll nodo, bool *visitados)
{
    visitados[nodo] = true;
    cout << vertices[nodo] << ", ";
    vector<C> aux = matAristas[nodo];
    for (int i = 0; i < aux.size(); ++i)
    {
        if (!visitados[i] && aux[i] != 0)
            recorridoDFS(i, visitados);
    }
}
template <class T, class C>
void GrafoM<T, C>::recorridoBFS(T inicio)
{
    bool visitados[vertices.size()] = {0};
    ll nodo = buscarVertice(inicio);
    queue<ll> colaV;
    colaV.push(nodo);
    if (nodo != -1)
    {
        while (!colaV.empty())
        {
            nodo = colaV.front();
            colaV.pop();
            if (!visitados[nodo])
            {
                cout << vertices[nodo] << ", ";
                visitados[nodo] = true;
                vector<C> aux = matAristas[nodo];
                for (int i = 0; i < aux.size(); ++i)
                {
                    if (aux[i] != 0)
                        colaV.push(i);
                }
            }
        }
    }
    else
        cout << "El dato no existe" << endl;
}
template <class T, class C>
void GrafoM<T, C>::prim(T inicio, vector<T> &nuevosV, vector<T> &pred, vector<C> &nuevasA)
{
    vector<pair<int, int>> listaMenores;
    nuevosV.push_back(inicio);
    pred.push_back(inicio);
    nuevasA.push_back(0);
    menorPeso(listaMenores);
    int in = 0;
    bool ori = false, des = false;
    while (nuevosV.size() != numVertices && !ori)
    {
        pair<int, int> aux = listaMenores[in];
        for (int j = 0; j < nuevosV.size() && !des; ++j)
        {
            if (vertices[aux.first] == nuevosV[j])
            {
                ori = true;
            }
            if (vertices[aux.second] == nuevosV[j])
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
void GrafoM<T, C>::dijkstra(T inicio, vector<T> &s, vector<T> &pred, vector<C> &dist)
{
    vector<T> q = vertices;
    for (int i = 0; i < numVertices; i++)
    {
        dist.push_back(100000);
    }
    pred.resize(numVertices);
    pred[0] = inicio;
    dist[0] = 0;
    while (!q.empty())
    {
        int menor = 100001;
        int ori;
        for (int i = 0; i < dist.size(); i++)
        {
            if (find(s.begin(), s.end(), vertices[i]) == s.end())
            {
                if (dist[i] < menor)
                {
                    menor = dist[i];
                    ori = i;
                }
            }
        }
        s.push_back(vertices[ori]);
        int indice = 0;
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i] == vertices[ori])
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
}
template <class T, class C>
vector<C **> GrafoM<T, C>::floydWarshall()
{
    vector<C **> v;
    int tam = vertices.size();
    C **path = new C *[tam];
    T **pred = new C *[tam];
    for (int i = 0; i < tam; i++)
    {
        path[i] = new C[tam];
        pred[i] = new C[tam];
    }
    for (int i = 0; i < vertices.size(); i++)
    {

        for (int j = 0; j < vertices.size(); j++)
        {
            if (matAristas[i][j] == 0 && i != j)
            {
                path[i][j] = INF;
            }
            else
                path[i][j] = matAristas[i][j];

            if (matAristas[i][j] < INF && i != j && matAristas[i][j] != 0)
            {
                pred[i][j] = i;
            }
            else
                pred[i][j] = -1;
        }
    }
    for (int k = 0; k < vertices.size(); k++)
        for (int i = 0; i < vertices.size(); i++)
            for (int j = 0; j < vertices.size(); j++)
            {
                int dt = path[i][k] + path[k][j];
                if (path[i][j] > dt)
                {
                    path[i][j] = dt;
                    pred[i][j] = pred[k][j];
                }
            }
    v.push_back(path);
    v.push_back(pred);
    return v;
}
template <class T, class C>
vector<T> GrafoM<T, C>::caminoFloyd(vector<C **> floyd, T origen, T destino)
{
    ll ori = buscarVertice(origen);
    ll des = buscarVertice(destino);
    int **path = floyd[0];
    int **pred = floyd[1];
    stack<ll> aux;
    vector<T> camino;
    if (ori != -1 && des != -1)
    {
        while (des != -1)
        {
            aux.push(des);
            des = pred[ori][des];
        }
    }
    while (!aux.empty())
    {
        camino.push_back(obtenerVertice(aux.top()));
        aux.pop();
    }
    return camino;
}
template <class T, class C>
vector<vector<vector<T>>> GrafoM<T, C>::caminosFloyd(vector<C **> floyd)
{
    vector<vector<vector<T>>> caminos;
    vector<vector<T>> aux;
    vector<T> camino;
    char l;
    for (ll i = 0; i < numVertices; i++)
    {
        for (ll j = 0; j < numVertices; j++)
        {
            camino = caminoFloyd(floyd, obtenerVertice(i), obtenerVertice(j));

            aux.push_back(camino);
        }
        caminos.push_back(aux);
        aux.clear();
    }
    return caminos;
}