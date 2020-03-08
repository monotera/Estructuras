#include "encontrar_palabras.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

void encontrar_palabras::comienza(char *palabraBuscar, list<string> linea)
{
    cout << "--------------------------------------------------------------" << endl;
    list<string>::iterator it;
    queue<char *> palabra;
    char *str;
    int  numLinea = 1;
    bool bandera = true;
    cantiPalabras = 0;
    for (it = linea.begin(); it != linea.end(); ++it)
    {
        char *str = new char[(*it).size()];
        strcpy(str, (*it).c_str());
        separateWords(str, palabra);
        while (!palabra.empty())
        {
            for (int i = 0; i < strlen(palabraBuscar); ++i)
            {
                if (palabraBuscar[i] != (palabra.front())[i])
                {
                    bandera = false;
                }
            }
            if (bandera)
            {
                cout << "Linea " << numLinea << ": " << palabra.front() << endl;
                cantiPalabras++;
            }
            palabra.pop();
            bandera = true;
        }
         numLinea++;
    }
    cout << "Hay " << cantiPalabras << " palabras que comienzan por " << palabraBuscar << endl;
}

void encontrar_palabras::separateWords(char *str, queue<char *> &palabras)
{
    int cont = 0;
    char *p;
    p = strtok(str, " ,");
    while (p != NULL)
    {
        palabras.push(p);
        cont++;
        p = strtok(NULL, " ,");
    }
}
void encontrar_palabras::contiene (char *palabraBuscar, list<string> linea)
{
    cout << "--------------------------------------------------------" << endl;
    list<string>::iterator it;
    queue<char *> palabra;
    char *str;
    int  numLinea = 1;
    cantiPalabras = 0;
    for (it = linea.begin(); it != linea.end(); ++it)
    {
        char *str = new char[(*it).size()];
        strcpy(str, (*it).c_str());
        separateWords(str, palabra);
        while (!palabra.empty())
        {
            if (strstr(palabra.front(), palabraBuscar) != nullptr)
            {
                cout << "Linea " << numLinea << ": " << palabra.front() << endl;
                cantiPalabras++;
            }
            palabra.pop();
        }
        numLinea++;
    }
    cout << "Hay " << cantiPalabras << " palabras que contienen " << palabraBuscar << endl;
}
