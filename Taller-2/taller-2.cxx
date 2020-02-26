// reading a text file
#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include <queue>
#include <algorithm>
#include "encontrar_palabras.h"

using namespace std;

int main(int argc, char *argv[])
{
    string line;
    encontrar_palabras encontrar;
    ifstream myfile(argv[1]);
    char *palabraBuscar;
    list<string> linea;
    
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            linea.push_back(line);
        }

        linea.pop_front();
        palabraBuscar = new char[(*linea.begin()).size()];
        strcpy(palabraBuscar, (*linea.begin()).c_str());
        linea.pop_front();
        encontrar.comienza(palabraBuscar,linea);
        encontrar.contiene(palabraBuscar, linea);
        string rev(palabraBuscar);
        reverse(rev.begin(),rev.end());
        strcpy(palabraBuscar,rev.c_str());
        encontrar.contiene(palabraBuscar,linea); 
        
        myfile.close();
    }
    else
        cout << "Unable to open file";
    return 0;
}

