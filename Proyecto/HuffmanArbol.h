#ifndef HUFFMANARBOL_H_INCLUDED
#define HUFFMANARBOL_H_INCLUDED

#include "HuffmanNodo.h"
#include <utility>
#include <vector>
using namespace std;

class HuffmanArbol
{
private:
    HuffmanNodo *raiz;
    vector <pair <char,string>> codigos;

public:
    HuffmanArbol();
    void generarArbol(char dato[], int freq[],int size);
    struct comparar;
    void guardarCodigos(HuffmanNodo *inicio, string str);
    void imprimirCodigos();
    string obtenerCodigo(char caracter);
    string cifrar(string secunecia);
    string desCifrar(string cif);
};




#include "HuffmanArbol.hxx"
#endif 