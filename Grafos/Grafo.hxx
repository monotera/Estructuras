#include <iostream>

template <class T, class C>
int Grafo<T, C>::cantiVertices()
{
    return this->numVertices;
}
template <class T, class C>
int Grafo<T, C>::cantiAristas()
{
    int suma = 0;
    vector<pair<ll, C>> temp;

    for (int i = 0; i < this->aristas.size(); ++i)
    {
        temp = aristas[i];
        suma += temp.size();
    }
    return suma;
}
template <class T, class C>
void Grafo<T, C>::insertarVertice(T vertice)
{
    if (numVertices == 0 || buscarVertice(vertice) == -1)
    {
        this->vertices.push_back(vertice);
        vector<pair<ll, C>> aux;
        this->aristas.push_back(aux);
        numVertices = this->vertices.size();
    }
}

template <class T, class C>
void Grafo<T, C>::insertarArista(T origen, T destino, C peso)
{
    ll ori = buscarVertice(origen);
    ll des = buscarVertice(destino);
    if (ori != -1 && des != -1)
    {
        if (buscarArista(ori, des) == -1)
        {
            vector<pair<ll, C>> *aux = &aristas[ori];
            pair<ll, C> nAri(des, peso);
            aux->push_back(nAri);
        }
    }
}

template <class T, class C>
ll Grafo<T, C>::buscarVertice(T vertice)
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
ll Grafo<T, C>::buscarArista(ll origen, ll destino)
{
    ll encontrado = -1;
    vector<pair<ll, C>> aux = aristas[origen];
    for (int i = 0; i < aux.size() && encontrado == -1; i++)
    {
        pair<ll, C> temp = aux[i];
        if (temp.first == destino)
            encontrado = i;
    }
    return encontrado;
}

template <class T, class C>
void Grafo<T, C>::eliminarVertice(T vertice)
{
    ll ver = buscarVertice(vertice);
    if (ver != -1)
    {
        vector<pair<ll, C>> *aux = &aristas[ver];
        aux->clear();
        aristas.erase(aristas.begin() + ver);
        for (int i = 0; i < aristas.size(); i++)
        {
            aux = &aristas[i];
            for (int j = 0; j < aux->size(); j++)
            {
                pair<ll, C> temp = (*aux)[j];
                if (temp.first == ver)
                {
                    aux->erase(aux->begin() + j);
                }
            }
           // eliminarArista(vertice,vertices[i]);
        }
        vertices.erase(vertices.begin() + ver);
        numVertices = vertices.size();
    }
}

template <class T, class C>
void Grafo<T, C>::eliminarArista(T origen, T destino)
{
    ll ori = buscarVertice(origen);
    ll des = buscarVertice(destino);
    if (ori != -1 && des != -1)
    {
        
        ll ariIn = buscarArista(ori, des);
        if (ariIn != -1)
        {
            vector<pair<ll, C>> *aux = &aristas[ori];
            aux->erase(aux->begin() + ariIn);
        }
    }
}
template <class T, class C>
void Grafo<T, C>::recorridoPlano()
{
    for (int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i] << ", ";
    }
    cout << endl;
}
template <class T, class C>
void Grafo<T, C>::prueba()
{
    cout << endl;
    for (int i = 0; i < vertices.size(); ++i)
    {
        cout << vertices[i] << "-> ";
        vector<pair<ll,C>> aux = aristas[i];
        for (int j = 0; j < aux.size(); j++)
        {
            pair<ll,C> temp = aux[j];
            cout << temp.first << " " << temp.second <<", ";
        }
        cout << endl;
        
    }
    cout << endl;
}