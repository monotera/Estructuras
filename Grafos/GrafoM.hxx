#include <iostream>
#include <queue>

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