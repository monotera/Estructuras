HuffmanArbol::HuffmanArbol()
{
    this->raiz = NULL;
}
struct HuffmanArbol::comparar
{

    bool operator()(HuffmanNodo *l, HuffmanNodo *r)

    {
        return (l->obtenerFreq() > r->obtenerFreq());
    }
};
void HuffmanArbol::generarArbol(char dato[], int freq[], int tama)
{
    HuffmanNodo *left, *right, *top;

    priority_queue<HuffmanNodo *, vector<HuffmanNodo *>, comparar> minHeap;
    for (int i = 0; i < tama; i++)
    {
        minHeap.push(new HuffmanNodo(dato[i], freq[i]));
    }
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();
        unsigned int nuevaFreq = left->obtenerFreq() + right->obtenerFreq();
        top = new HuffmanNodo(' ', nuevaFreq);
        top->fijarHijoDer(right);
        top->fijarHijoIzq(left);
        minHeap.push(top);
    }
    this->raiz = minHeap.top();
    guardarCodigos(this->raiz, "");
}
void HuffmanArbol::guardarCodigos(HuffmanNodo *inicio, string str)
{
    if (!inicio)
        return;
    if (inicio->obtenerDato() != ' ')
    {
        codigos.push_back(make_pair(inicio->obtenerDato(), str));
    }
    this->guardarCodigos(inicio->obtenerHijoIzq(), str + "0");
    this->guardarCodigos(inicio->obtenerHijoDer(), str + "1");
}
void HuffmanArbol::imprimirCodigos()
{
    vector<pair<char, string>>::iterator it;
    for (it = codigos.begin(); it != codigos.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }
}
string HuffmanArbol::obtenerCodigo(char caracter)
{
    string codigo = "";
    bool encontrado = false;
    vector<pair<char, string>>::iterator it;
    for (it = codigos.begin(); it != codigos.end() && !encontrado; ++it)
    {
        if (it->first == caracter)
            codigo = it->second;
    }
    return codigo;
}
string HuffmanArbol::cifrar(string sec)
{
    string cifrado;
    for (int i = 0; i < sec.size(); ++i)
    {
        cifrado += this->obtenerCodigo(sec[i]);
    }
    return cifrado;
}
string HuffmanArbol::desCifrar(string sec)
{
    HuffmanNodo *nodo = this->raiz;
    string desCifrado = "";
    for (int i = 0; i < sec.size() +1; i++)
    {
        if (nodo->esHoja())
        {
            desCifrado += nodo->obtenerDato();
            nodo = this->raiz;
        }
        if (sec[i] == '1')
        {
            nodo = nodo->obtenerHijoDer();
        }
        else
        {
            nodo = nodo->obtenerHijoIzq();
        }
    }
    return desCifrado;
}