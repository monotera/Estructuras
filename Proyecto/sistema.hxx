#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include "archivo.h"
#include "sistema.h"
#include <bitset>

using namespace std;

/*-1  = el archivo no se pudo abrir
    0  = el archivo esta vacio
    1  = el archivo tiene una secuencia
    2 o mayor = el archivo tiene n secuencias*/
int sistema::cargarArchivo(string nombre)
{

    if (conteo() > 0)
        arch.borrarSec();
    string line;
    ifstream myFile(nombre);
    if (myFile.is_open())
    {
        int cont = 0;
        secuencia sec;
        arch.setNombreArchivo(nombre);
        getline(myFile, line);
        if (line.find(">") != string::npos)
        {
            sec.setDescripcion(line);
        }
        while (getline(myFile, line))
        {
            if (line.find(">") != string::npos)
            {
                if (sec.getDescripcione().size() > 0)
                {
                    arch.agregarSecuencia(sec);
                    sec.borrarLineas();
                    cont++;
                }
                sec.setDescripcion(line);
            }
            else
                sec.agregarLinea(line);
        }
        if (sec.getDescripcione().size() > 0)
        {
            arch.agregarSecuencia(sec);
            cont++;
        }
        return cont;
    }
    return -1;
}
int sistema::conteo()
{
    return arch.getTamaSec();
}
int sistema::listar_secuencias()
{
    return arch.listar_sec();
}
int sistema::enmascarar(string sub)
{
    transform(sub.begin(), sub.end(), sub.begin(), (int (*)(int))std::toupper);
    return arch.enmascarar(sub);
}
int sistema::guardar(string nombre)
{
    return arch.guardar(nombre);
}
string sistema::getNombre()
{
    return arch.getNombreArchivo();
}

int sistema::esSubSecuencia(string sub)
{
    transform(sub.begin(), sub.end(), sub.begin(), (int (*)(int))std::toupper);
    return arch.esSubSecuencia(sub);
}

string sistema::histograma(string desc)
{
    transform(desc.begin(), desc.end(), desc.begin(), (int (*)(int))std::toupper);
    return arch.histograma(desc);
}
struct sistema::datosBin
{
    short cantiBases;
    vector<char> caracterBase;
    vector<long> frecuenciaBase;
    int cantiSecuencias;
    vector<short> TamNombreSec;
    vector<vector<char>> nombreSec;
    vector<long> longiSec;
    vector<short> identacion;
    vector<string> binary_code;
    vector<string> secu;
};

bool sistema::cifrar(string nombreF)
{
    bool resp = false;
    ofstream file;
    datosBin dat;
    int contador = 0;
    file.open(nombreF, ios::out | ios::binary);
    if (file.is_open())
    {
        llenarStruct(dat);
        //-------------------------------------------------------------------------
        file.write((char *)&dat.cantiBases, sizeof(short));
        for (int i = 0; i < dat.cantiBases; i++)
        {
            file.write((char *)&dat.caracterBase[i], sizeof(char));
            file.write((char *)&dat.frecuenciaBase[i], sizeof(long));
        }
        file.write((char *)&dat.cantiSecuencias, sizeof(int));
        for (int i = 0; i < dat.cantiSecuencias; i++)
        {
            file.write((char *)&dat.TamNombreSec[i], sizeof(short));
            vector<char> aux = dat.nombreSec[i];
            for (int j = 0; j < dat.TamNombreSec[i]; j++)
            {
                file.write((char *)&aux[j], sizeof(char));
            }
        }
        for (int i = 0; i < dat.cantiSecuencias; i++)
        {
            file.write((char *)&dat.longiSec[i], sizeof(long));
            file.write((char *)&dat.identacion[i], sizeof(short));
            //----------------------------------------------------------------------
            string cod = dat.binary_code[i];
            int z = 0;
            while (z < cod.size())
            {
                char t = 0;
                for (int l = 0; l < 8; l++)
                {
                    if (cod[z] == '1')
                    {
                        t += 1 << (7 - l);
                    }
                    z++;
                }
                file.write((char *)&t, sizeof(char));
            }
        }
        file.close();
        resp = true;
    }
    return resp;
}
bool sistema::desCifrar(string nombreF)
{
    bool res = false;
    datosBin datEx;
    ifstream newArchivo(nombreF, ios::out | ios::binary);
    if (newArchivo.is_open())
    {
        res = true;
        newArchivo.read((char *)&datEx.cantiBases, sizeof(short));

        datEx.caracterBase.resize(datEx.cantiBases);
        datEx.frecuenciaBase.resize(datEx.cantiBases);
        for (int i = 0; i < datEx.cantiBases; ++i)
        {
            newArchivo.read((char *)&datEx.caracterBase[i], sizeof(char));
            newArchivo.read((char *)&datEx.frecuenciaBase[i], sizeof(long));
        }
        newArchivo.read((char *)&datEx.cantiSecuencias, sizeof(int));

        char *arr = new char[datEx.cantiBases];
        long *freq = new long[datEx.cantiBases];
        for (int i = 0; i < datEx.cantiBases; ++i)
        {
            arr[i] = datEx.caracterBase[i];
            freq[i] = datEx.frecuenciaBase[i];
        }
        arbolHuff.generarArbol(arr, freq, datEx.cantiBases);
        datEx.TamNombreSec.resize(datEx.cantiSecuencias);
        for (int i = 0; i < datEx.cantiSecuencias; i++)
        {
            newArchivo.read((char *)&datEx.TamNombreSec[i], sizeof(short));
            vector<char> aux;
            aux.resize(datEx.TamNombreSec[i]);
            for (int j = 0; j < datEx.TamNombreSec[i]; j++)
            {
                newArchivo.read((char *)&aux[j], sizeof(char));
            }
            datEx.nombreSec.push_back(aux);
        }

        datEx.longiSec.resize(datEx.cantiSecuencias);
        datEx.identacion.resize(datEx.cantiSecuencias);
        for (int i = 0; i < datEx.cantiSecuencias; i++)
        {
            newArchivo.read((char *)&datEx.longiSec[i], sizeof(long));
            newArchivo.read((char *)&datEx.identacion[i], sizeof(short));
            char dir;
            int l = 0;
            char y;
            vector<char> q;
            bitset<8> uno(1);
            bitset<8> cero(0);
            HuffmanNodo *nodo = arbolHuff.getRaiz();
            int cantiPal = 0;
            string secI = "";
            bool fin = false;
            cout << datEx.longiSec[i] << endl;
            if (datEx.longiSec[i] >= 9999999 || datEx.longiSec[i] < 0)
            {
                return false;
            }
            while (!fin)
            {
                newArchivo.read((char *)&y, sizeof(char));
                for (int j = 0; j < 8 && !fin; j++)
                {
                    q.push_back(y >> 7 - j);
                    bitset<8> we((q[l] >> 0) & 0x1);
                    if (we == uno)
                    {
                        dir = '1';
                    }
                    else if (we == cero)
                    {
                        dir = '0';
                    }
                    nodo = arbolHuff.deCodificar(nodo, dir, cantiPal, secI);
                    if (cantiPal == datEx.longiSec[i])
                    {
                        fin = true;
                    }
                    l++;
                }
            }
            datEx.secu.push_back(secI);
        }
    }
    crearFa(datEx);
    newArchivo.close();

    return res;
}
void sistema::llenarStruct(datosBin &dat)
{
    long freq[18];
    char arr[18];
    short tama = arch.llenarArreglos(arr, freq);
    this->arbolHuff.generarArbol(arr, freq, tama);
    dat.cantiBases = tama;
    for (int i = 0; i < tama; i++)
    {
        dat.caracterBase.push_back(arr[i]);
        dat.frecuenciaBase.push_back(freq[i]);
    }

    dat.cantiSecuencias = arch.getTamaSec();
    vector<string> descriSec = arch.getNombreSec();
    vector<string> secLinea = arch.secuenciasLinea();
    dat.identacion = arch.getIdentaciones();

    for (int i = 0; i < dat.cantiSecuencias; i++)
    {
        short tamaNom = descriSec[i].size();
        long tamaSec = secLinea[i].size();
        string nombre = descriSec[i];
        dat.TamNombreSec.push_back(tamaNom);
        vector<char> nombreV;
        for (int j = 0; j < dat.TamNombreSec[i]; j++)
        {
            nombreV.push_back(nombre[j]);
        }
        dat.nombreSec.push_back(nombreV);
        dat.longiSec.push_back(tamaSec);
        string binCod = arbolHuff.cifrar(secLinea[i]);
        dat.binary_code.push_back(binCod);
    }
}
bool sistema::crearFa(datosBin dat)
{
    bool res = false;
    ofstream newFile;
    newFile.open("borrar.fa", ios::out);
    if (newFile.is_open())
    {
        res = true;
        char *arr = new char[dat.cantiBases];
        long *freq = new long[dat.cantiBases];
        for (int i = 0; i < dat.cantiBases; ++i)
        {
            arr[i] = dat.caracterBase[i];
            freq[i] = dat.frecuenciaBase[i];
        }
        arbolHuff.generarArbol(arr, freq, dat.cantiBases);
        for (int i = 0; i < dat.cantiSecuencias; i++)
        {
            vector<char> nombre;
            nombre.clear();
            nombre = dat.nombreSec[i];
            newFile << ">";
            for (int j = 0; j < dat.TamNombreSec[i]; j++)
            {
                newFile << nombre[j];
            }
            string desC = dat.secu[i];
            int k = 0;
            newFile << endl;
            for (int j = 0; j < dat.longiSec[i]; j++, k++)
            {
                if (k == dat.identacion[i])
                {
                    newFile << endl;
                    k = 0;
                }
                newFile << desC[j];
            }
            newFile << endl;
        }
        newFile.close();
        cargarArchivo("borrar.fa");
        remove("borrar.fa");
    }
    return res;
}
void sistema::generarGrafo(string nombre)
{
    grafo.reiniciarGrafo();
    llenarVertices(nombre);
    llenarConex();
}
bool sistema::llenarVertices(string nombre)
{
    bool res = false;
    vector<NodoGrafo> nodos = arch.generarVertices(nombre);
    if (nodos.size() != 0)
    {
        for (int i = 0; i < nodos.size(); i++)
        {
            grafo.insertarVertice(nodos[i]);
        }
        res = true;
    }
    return res;
}
bool sistema::llenarConex()
{
    for (int i = 0; i < grafo.cantiVertices(); i++)
    {
        NodoGrafo aux = grafo.obtenerVertice(i);
        vector<NodoGrafo> vecinos = grafo.obtenerVeci(aux);
        for (int j = 0; j < vecinos.size(); j++)
        {
            grafo.insertarArista(aux, vecinos[j], aux.calcularConexion(vecinos[j].getLetra()));
        }
    }
    return true;
}

string sistema::ruta_mas_corta(string nombre, int i, int j, int x, int y)
{
    string resp = "";
    generarGrafo(nombre);
    if (grafo.cantiVertices() != 0)
    {
        int ori = grafo.buscarCordenadas(i, j);
        int des = grafo.buscarCordenadas(x, y);
        if (ori == -1)
            resp = "1";
        else if (des == -1)
            resp = "2";
        else
        {
            NodoGrafo origen = grafo.obtenerVertice(ori);
            NodoGrafo destino = grafo.obtenerVertice(des);
            vector<NodoGrafo> camino = grafo.generarCamino(origen, destino);
            for (int i = 0; i < camino.size(); i++)
            {
                cout << camino[i].getX() << " " << camino[i].getY()<<", ";
                resp += camino[i].getLetra();
                if (i != camino.size() - 1)
                    resp += ", ";
            }
        }
    }
    return resp;
}