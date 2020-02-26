// reading a text file
#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

void contiene(char *palabraBuscar, list<string> linea);
void separateWords(char *str, queue<char *> &palabras);
void comienza(char *palabraBuscar, list<string> linea);

int main(int argc, char *argv[])
{
    string line;
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
        comienza(palabraBuscar, linea);
        contiene(palabraBuscar, linea);
        string rev(palabraBuscar);
        reverse(rev.begin(),rev.end());
        strcpy(palabraBuscar,rev.c_str());
        contiene(palabraBuscar,linea);
        myfile.close();
    }
    else
        cout << "Unable to open file";
    return 0;
}

void contiene(char *palabraBuscar, list<string> linea)
{
    cout << "--------------------------------------------------------" << endl;
    list<string>::iterator it;
    queue<char *> palabra;
    char *str;
    int cantiPal = 0, numLinea = 1;
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
                cantiPal++;
            }
            palabra.pop();
        }
        numLinea++;
    }
    cout << "Hay " << cantiPal << " palabras que contienen " << palabraBuscar << endl;
}
void comienza(char *palabraBuscar, list<string> linea)
{
    cout << "--------------------------------------------------------------" << endl;
    list<string>::iterator it;
    queue<char *> palabra;
    char *str;
    int cantiPal = 0, numLinea = 1;
    bool bandera = true;
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
                cout << "Linea " << numLinea << ": " << palabra.front() << palabra.front() << endl;
                cantiPal++;
            }
            palabra.pop();
            bandera = true;
        }
        numLinea++;
    }
    cout << "Hay " << cantiPal << " palabras que comienzan por " << palabraBuscar << endl;
}

void separateWords(char *str, queue<char *> &palabras)
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

