#include <iostream>
#include <list>
#include <string>
#include "secuencia.h"
#include "archivo.h"
#include <fstream>
#include <algorithm>
using namespace std;

string archivo::getNombreArchivo()
{
    nombre.erase(nombre.end() - 3, nombre.end());
    return nombre;
}
void archivo::setNombreArchivo(string nombrew)
{
    this->nombre = nombrew;
}
list<secuencia> archivo::getSecuencias()
{
    return this->secuencias;
}
void archivo::agregarSecuencia(secuencia nuevaSec)
{
    this->secuencias.push_back(nuevaSec);
}
int archivo::getTamaSec()
{
    return this->secuencias.size();
}
int archivo::listar_sec()
{
    if (secuencias.size() > 0)
    {
        int sec_incompleta;
        list<secuencia>::iterator it;
        for (it = secuencias.begin(); it != secuencias.end(); it++)
        {
            sec_incompleta = it->setCantiBase();
            if (sec_incompleta == 0)
                cout << "Secuencia " << it->getDescripcione() << " contiene " << it->getCantiBase() << " bases" << endl;
            else if (sec_incompleta == -1)
                cout << "Secuencia " << it->getDescripcione() << " contiene al menos " << it->getCantiBase() << " bases" << endl;
        }
        return 0;
    }
    return -1;
}
int archivo::enmascarar(string sub)
{
    int resp = 0;
    list<secuencia>::iterator it = secuencias.begin();
    for (; it != secuencias.end(); it++)
        resp += (*it).enmascarar(sub);
    return resp;
}

int archivo::esSubSecuencia(string sub)
{
    int resp = 0;
    list<secuencia>::iterator it = secuencias.begin();
    for (; it != secuencias.end(); it++)
        resp += (*it).esSubSecuencia(sub);
    return resp;
}

string archivo::histograma(string desc)
{
    string resp = "";
    list<secuencia>::iterator it = secuencias.begin();
    for (; it != secuencias.end(); it++)
    {
        string descUpper = (*it).getDescripcione();
        transform(descUpper.begin(), descUpper.end(), descUpper.begin(), (int (*)(int))std::toupper);
        if (descUpper == desc)
            resp = (*it).histograma();
    }
    return resp;
}
int archivo::guardar(string nombre)
{

    ofstream arch(nombre, ios::out);
    int i = 0;
    if (arch.is_open())
    {
        list<secuencia>::iterator it;
        for (it = secuencias.begin(); it != secuencias.end(); ++it)
        {
            arch << ">" + it->getDescripcione() << endl;
            list<string>::iterator its;
            list<string> actual = it->getLineas();
            for (its = actual.begin(); its != actual.end(); its++)
            {
                arch << *its << endl;
            }
        }
        return 0;
    }
    return -1;
}
void archivo::borrarSec()
{
    this->secuencias.clear();
}
vector<string> archivo::secuenciasLinea()
{
    vector<string> secLinea;
    list<secuencia>::iterator it;
    for (it = secuencias.begin(); it != secuencias.end(); it++)
    {
        string linea = (*it).getSecuenciaLinea();
        secLinea.push_back(linea);
    }
    return secLinea;
}
vector<string> archivo::getNombreSec()
{
    vector<string> nombres;
    list<secuencia>::iterator it;
    for (it = secuencias.begin(); it != secuencias.end(); it++)
    {
        string linea = (*it).getDescripcione();
        nombres.push_back(linea);
    }
    return nombres;
}
vector<short> archivo::getIdentaciones()
{
    vector<short> ide;
    short num;
    list<secuencia>::iterator it;
    for (it = secuencias.begin(); it != secuencias.end(); it++)
    {
        num = (*it).getIndentacion();
        ide.push_back(num);
    }
    return ide;
}
short archivo::llenarArreglos(char car[], long fre[])
{
    list<secuencia>::iterator it = secuencias.begin();
    int frec[19];
    int a, c, g, t, u, r, y, k, m, s, w, b, d, h, v, n, x, inc;
    a = c = g = t = u = r = y = k = m = s = w = b = d = h = v = n = x = inc = 0;
    for (; it != secuencias.end(); it++)
    {
        it->crearLista(frec);
        a += frec[0];
        c += frec[1];
        g += frec[2];
        t += frec[3];
        u += frec[4];
        r += frec[5];
        y += frec[6];
        k += frec[7];
        m += frec[8];
        s += frec[9];
        w += frec[10];
        b += frec[11];
        d += frec[12];
        h += frec[13];
        v += frec[14];
        n += frec[15];
        x += frec[16];
        inc += frec[17];
    }
    short i = 0;
    if (a != 0)
    {
        car[i] = 'A';
        fre[i] = a;
        i++;
    }
    if (c != 0)
    {
        car[i] = 'C';
        fre[i] = c;
        i++;
    }
    if (g != 0)
    {
        car[i] = 'G';
        fre[i] = g;
        i++;
    }
    if (t != 0)
    {
        car[i] = 'T';
        fre[i] = t;
        i++;
    }
    if (u != 0)
    {
        car[i] = 'U';
        fre[i] = u;
        i++;
    }
    if (r != 0)
    {
        car[i] = 'R';
        fre[i] = r;
        i++;
    }
    if (y != 0)
    {
        car[i] = 'Y';
        fre[i] = y;
        i++;
    }
    if (k != 0)
    {
        car[i] = 'K';
        fre[i] = k;
        i++;
    }
    if (m != 0)
    {
        car[i] = 'M';
        fre[i] = m;
        i++;
    }
    if (s != 0)
    {
        car[i] = 'S';
        fre[i] = s;
        i++;
    }
    if (w != 0)
    {
        car[i] = 'W';
        fre[i] = w;
        i++;
    }
    if (b != 0)
    {
        car[i] = 'B';
        fre[i] = b;
        i++;
    }
    if (d != 0)
    {
        car[i] = 'D';
        fre[i] = d;
        i++;
    }
    if (h != 0)
    {
        car[i] = 'H';
        fre[i] = h;
        i++;
    }
    if (v != 0)
    {
        car[i] = 'V';
        fre[i] = v;
        i++;
    }
    if (n != 0)
    {
        car[i] = 'N';
        fre[i] = n;
        i++;
    }
    if (x != 0)
    {
        car[i] = 'X';
        fre[i] = x;
        i++;
    }
    if (inc != 0)
    {
        car[i] = '-';
        fre[i] = inc;
        i++;
    }
    return i;
}
secuencia archivo::buscarSec(string sec)
{
    list<secuencia>::iterator it = secuencias.begin();
    secuencia secu("F");
    for (; it != secuencias.end(); it++)
    {
        if ((*it).getDescripcione() == sec)
        {
            secu = *it;
        }
    }
    return secu;
}
vector<NodoGrafo> archivo::generarVertices(string nombre){
    secuencia sec = buscarSec(nombre);
    list <string> lineas = sec.getLineas();
    list<string>::iterator it = lineas.begin();
    vector<NodoGrafo> nodos;
    int x = 0;
    for (; it != lineas.end(); it++)
    {
        string linea = *it;
        for (int y = 0; y < linea.size(); y++)
        {
            NodoGrafo nodo(x,y,linea[y]);
            nodos.push_back(nodo);            
        }
        x++;        
    }
    return nodos;
} 