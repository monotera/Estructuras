#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <string.h>
#include <algorithm>
#include "archivo.h"
#include "sistema.h"

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
};

bool sistema::cifrar()
{
    bool resp = false;
    ofstream file;
    datosBin dat;
    file.open("pru.bin", ios::out | ios::binary);
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
            //for (int j = 0; j < dat.TamNombreSec[i]; j++)
            //{
            //file.write((char *)&dat.nombreSec[i][j], sizeof(char));
            // }
            file.write((char *)&dat.longiSec[i], sizeof(long));
            file.write((char *)&dat.identacion[i], sizeof(short));
            file.write((char *)&dat.binary_code[i], sizeof(string));
        }

        file.close();
        resp = true;
    }
    return resp;
}
bool sistema::desCifrar(string nombre)
{
    cout << "Archivo--------------------------" << endl;
    bool res = false;
    datosBin datEx;
    ifstream newArchivo("pru.bin", ios::out | ios::binary);
    if (newArchivo.is_open())
    {
        newArchivo.read((char *)&datEx.cantiBases, sizeof(short));
        for (int i = 0; i < datEx.cantiBases; ++i)
        {
            datEx.caracterBase.push_back(' ');
            datEx.frecuenciaBase.push_back(0);
            newArchivo.read((char *)&datEx.caracterBase[i], sizeof(char));
            newArchivo.read((char *)&datEx.frecuenciaBase[i], sizeof(long));
        }
        newArchivo.read((char *)&datEx.cantiSecuencias, sizeof(int));
        cout << "Bases: " << datEx.cantiBases << " sec:" << datEx.cantiSecuencias << endl;
        for (int i = 0; i < datEx.cantiBases; ++i)
        {
            cout << datEx.caracterBase[i] << " " << datEx.frecuenciaBase[i] << ", ";
        }
        cout << endl;
        datEx.TamNombreSec.reserve(datEx.cantiSecuencias);
        datEx.nombreSec.reserve(datEx.cantiSecuencias);
        datEx.longiSec.reserve(datEx.cantiSecuencias);
        datEx.identacion.reserve(datEx.cantiSecuencias);
        datEx.binary_code.reserve(datEx.cantiSecuencias);
        for (int i = 0; i < datEx.cantiSecuencias; i++)
        {
            newArchivo.read((char *)&datEx.TamNombreSec[i], sizeof(short));
            cout << datEx.TamNombreSec[i] << endl;
            //datEx.nombreSec[i].reserve(datEx.TamNombreSec[i]);
            //for (int j = 0; j < datEx.TamNombreSec[i]; j++){
            //newArchivo.read((char *)&datEx.nombreSec[i][j], sizeof(char));
            //cout << datEx.nombreSec[i][j];
            //}
            newArchivo.read((char *)&datEx.longiSec[i], sizeof(long));
            cout << "longi: " << datEx.longiSec[i] << endl;
            newArchivo.read((char *)&datEx.identacion[i], sizeof(short));
            cout << "ide: " << datEx.identacion[i] << endl;
            newArchivo.read((char *)&datEx.binary_code[i], sizeof(string));
            cout << "Binary: " << datEx.binary_code[i] << endl;
        }
        crearFa(datEx);
        newArchivo.close();
    }
    
    return res;
}
void sistema::llenarStruct(datosBin &dat)
{
    long freq[18];
    char arr[18];
    short tama = arch.llenarArreglos(arr, freq);
    cout << "#bsaes" << tama << endl;
    this->arbolHuff.generarArbol(arr, freq, tama);
    arbolHuff.imprimirCodigos();
    dat.cantiBases = tama;
    for (int i = 0; i < tama; i++)
    {
        dat.caracterBase.push_back(arr[i]);
        dat.frecuenciaBase.push_back(freq[i]);
    }

    dat.cantiSecuencias = arch.getTamaSec();
    cout << "#sec: " << arch.getTamaSec() << endl;
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
        cout << endl;
        dat.nombreSec.push_back(nombreV);
        dat.longiSec.push_back(tamaSec);
        string binCod = arbolHuff.cifrar(secLinea[i]);
        dat.binary_code.push_back(binCod);
    }
}
bool sistema::crearFa(datosBin dat)
{
    bool res = false;
    /*ofstream newFile;
    newFile.open("borrarasdxz.fa", ios::out);
    if (newFile.is_open())
    {
        res = true;
        cout <<"Crear----------------------"<<endl;
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
            string desC = arbolHuff.desCifrar(dat.binary_code[i], dat.longiSec[i]);
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
    }*/
    return res;
}
