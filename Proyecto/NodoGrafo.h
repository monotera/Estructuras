#ifndef NODOGRAFO__H__
#define NODOGRAFO__H__
#include <math.h>
using namespace std;

class NodoGrafo
{
protected:
    char letra;
    int x;
    int y;
public:
    NodoGrafo(int x, int y, char letra);
    NodoGrafo();
    char getLetra();
    int getX();
    int getY();
    void setLetra(char letra);
    void setX(int x);
    void setY(int y);
    double calcularConexion(char letra);
};

#include "NodoGrafo.hxx"
#endif