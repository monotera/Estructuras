/*Realizado por Nelson Mosquera, Andres Torres y Richard Fonseca*/

#include <iostream>
#include <string.h>
#include <string>
#include "sistema.h"
#include "archivo.h"
#include "secuencia.h"

int countWords(char *str, char palabra[][50]);

using namespace std;

int main(int argc, char *argv[])
{
    char *comando = new char[2];
    char *archivo;
    char *secuencia, *descriSecuencia, sec[200];
    char palabra[20][50];
    sistema sys;
    if (argc > 1)
    {
        comando = new char[strlen(argv[1])];
        for (int i = 0; i < argc; i++)
        {
            strcpy(palabra[i], argv[i]);
        }
        strcpy(comando, palabra[1]);
    }
    else
        cout << "No ingreso un comando" << endl;

    while (true)
    {
        if (strcmp(comando, "cargar") == 0)
        {
            if (argc == 3)
            {
                archivo = new char[strlen(palabra[2])];
                strcpy(archivo, palabra[2]);
                cout << "---CARGAR---" << endl;
                int cantiSec = sys.cargarArchivo(archivo);
                if(cantiSec == -1)
                    cout << "El archivo no se pudo abrir" << endl;
                else if(cantiSec == 0)
                    cout << "El archivo " << sys.getNombre()<<" esta vacio" << endl;
                else if(cantiSec == 1)
                    cout << "1 secuencia cargada correctamente desde " << sys.getNombre() << endl;
                else
                    cout << cantiSec <<" secuencias cargadas correctamente desde " << sys.getNombre() << endl;
            }
            else
                cout << "El numero de comandos es invalido" << endl;
        }
        else if (strcmp(comando, "conteo") == 0)
        {
            cout << "---CONTEO---" << endl;
            int cantiSec = sys.conteo();
            if(cantiSec == 0)
                cout << "No hay secuencias cargadas en memoria" << endl;
            else if(cantiSec == 1)
                cout << "1 secuencia cargada en memoria "  << endl;
            else
                cout << cantiSec <<" secuencias cargadas en memoria "<< endl;
        }
        else if (strcmp(comando, "listar_secuencias") == 0)
        {
            cout << "---LISTAR SECUENCIA---" << endl;
            if(sys.listar_secuencias() == -1)
                cout << "No hay secuencias cargadas en memoria" <<endl;
        }
        else if (strcmp(comando, "histograma") == 0)
        {
            if (argc == 3)
            {
                descriSecuencia = new char[strlen(palabra[2])];
                strcpy(descriSecuencia, palabra[2]);
                cout << "---HISTOGRAMA---" << endl;
            }
            else
                cout << "El numero de comandos es invalido" << endl;
        }
        else if (strcmp(comando, "es_subsecuencia") == 0)
        {
            if (argc == 3)
            {
                secuencia = new char[strlen(palabra[2])];
                strcpy(secuencia, palabra[2]);
                cout << "---ES_SUBSECUENCIA---" << endl;
                if(sys.getArchivo().getSecuencias().empty())
                    cout << "No hay secuencias cargas en memoria.\n";
                else if(sys.esSubSecuencia(secuencia)==0)
                    cout << "La secuencia dada no existe.\n";
                else
                    cout << "La secuencia dada se repite " << sys.esSubSecuencia(secuencia) << " veces.\n";                
            }
            else
                cout << "El numero de comandos es invalido" << endl;
        }
        else if (strcmp(comando, "enmascarar") == 0)
        {
            if (argc == 3)
            {
                secuencia = new char[strlen(palabra[2])];
                strcpy(secuencia, palabra[2]);
                cout << "---ENMASCARAR---" << endl;
                int cantiSec = sys.enmascarar(secuencia);
                if(sys.conteo() == 0){
                    cout << "No hay secuencias cargadas en memoria." <<endl;
                }
                else if(cantiSec == 0)
                    cout << "La secuencia dada no existe, por tanto no se enmascara nada." <<endl;
                else if(cantiSec == 1)
                    cout << "1 secuencia ha sido enmascarada."<<endl;
                else
                    cout << cantiSec << " secuencias han sido enmascaradas." << endl;
            }
            else
                cout << "El numero de comandos es invalido" << endl;
        }
        else if (strcmp(comando, "guardar") == 0)
        {
            if (argc == 3)
            {
                archivo = new char[strlen(palabra[2])];
                strcpy(archivo, palabra[2]);
                cout << "---GUARDAR---" << endl;
            }
            else
                cout << "El numero de comandos es invalido" << endl;
        }
        else if (strcmp(comando, "salir") == 0)
        {
            exit(1);
        }
        else if (strcmp(comando, "codificar") == 0)
        {
            archivo = new char[strlen(palabra[2])];
            archivo = palabra[2];
            if ((strstr(archivo, ".fa") != nullptr))
                cout << "---Codificar (Archivo valido)---" << endl;
            else
                cout << "Archivo invalido" << endl;
        }
        else if (strcmp(comando, "decodificar") == 0)
        {
            archivo = new char[strlen(palabra[2])];
            archivo = palabra[2];
            if ((strstr(archivo, ".fa") != nullptr))
                cout << "---Decodificar (Archivo valido)---" << endl;
            else
                cout << "Archivo invalido" << endl;
        }
        else if (strcmp(comando, "ruta_mas_corta") == 0)
        {
            char *des = palabra[2];
            if (argc == 7)
            {
                if (atoi(palabra[3]) == 0 || atoi(palabra[4]) == 0 || atoi(palabra[5]) == 0 || atoi(palabra[6]) == 0)
                    cout << "Una de las coordenadas no es valida, asegurese que sean solo numeros enteros\n";
                cout << "La secuencia dada no existe\n";
                cout << "---Ruta mas corta---\n";
            }
            else
                cout << "El numero de comandos es invalido" << endl;
        }
        else if (strcmp(comando, "base_remota") == 0)
        {
            if (argc == 5)
            {
                char *des = palabra[2];
                if (atoi(palabra[3]) == 0 || atoi(palabra[4]) == 0)
                    cout << "Una de las coordenadas no es valida, asegurese que sean solo numeros enteros\n";
                cout << "---Base remota---";
                cout << "La secuencia dada no existe\n";
            }
            else
                cout << "El numero de comandos es invalido" << endl;
        }
        else if (strcmp(comando, "ayuda") == 0)
        {
            cout << "AYUDA \n";
            cout << "Comandos disponibles: \n"
                 << "cargar \t"
                 << "conteo \t"
                 << "listar_secuencia \t"
                 << "histograma \n"
                 << "es_subsecuencia \t"
                 << "enmascarar \t"
                 << "guardar \t"
                 << "salir \n"
                 << "codificar \t"
                 << "decodificar \t"
                 << "ruta_mas_corta \t"
                 << "base_remota \n";

            cout << "\nSe incluyen los comandos ayuda de cada comando, ayuda_nombre_del_comando \n";

            cout << "ayuda_cargar \t"
                 << "ayuda_conteo \t"
                 << "ayuda_listar_secuencia \t"
                 << "ayuda_histograma \n"
                 << "ayuda_es_subsecuencia \t"
                 << "ayuda_enmascarar \t"
                 << "ayuda_guardar \t"
                 << "ayuda_salir \n"
                 << "ayuda_codificar \t"
                 << "ayuda_decodificar \t"
                 << "ayuda_ruta_mas_corta\t"
                 << "ayuda_base_remota\n";
        }
        else if (strcmp(comando, "ayuda_cargar") == 0)
        {
            cout << "AYUDA_CARGAR \n";
            cout << "la manera correcta de llamar al comando cargar es: "
                 << "cargar nombre_archivo\n";
            cout << "nombre_archivo: Nombre del archivo del que desea cargar las secuencias para subir a la memoria\n";
        }
        else if (strcmp(comando, "ayuda_conteo") == 0)
        {
            cout << "AYUDA_CONTEO \n";
            cout << "la manera correcta de llamar al comando conteo es: "
                 << "conteo";
        }
        else if (strcmp(comando, "ayuda_listar_secuencias") == 0)
        {
            cout << "AYUDA_LISTAR_SECUENCIAS \n";
            cout << "la manera correcta de llamar al comando listar secuencias es: "
                 << "listar_secuencia";
        }
        else if (strcmp(comando, "ayuda_histograma") == 0)
        {
            cout << "AYUDA_HISTOGRAMA \n";
            cout << "la manera correcta de llamar al comando histograma es: "
                 << "histograma descripcion_secuencia\n";
            cout << "descripcion_secuencia: Descripcion de la secuencia de la cual se desea generar el histograma(la descripcion es diferente a la secuencia en si)\n";
        }

        else if (strcmp(comando, "ayuda_es_subsecuencia") == 0)
        {
            cout << "AYUDA_ES_SUBSECUENCIA \n";
            cout << "la manera correcta de llamar al comando es subsecuencia es: "
                 << "es_subsecuencia secuencia\n";
            cout << "secuencia: Secuencia que desea buscar dentro de las secuencias actualmente cargadas\n";
        }
        else if (strcmp(comando, "ayuda_enmascarar") == 0)
        {
            cout << "AYUDA_ENMASCARAR \n";
            cout << "la manera correcta de llamar al comando enmascarar es: "
                 << "enmascarar secuencia\n";
            cout << "secuencia: La secuencia que el usuario desea enmascarar(todos los codigos se reemplazan por X si la secuencia existe)\n";
        }
        else if (strcmp(comando, "ayuda_guardar") == 0)
        {
            cout << "AYUDA_GUARDAR \n";
            cout << "la manera correcta de llamar al comando guardar es: "
                 << "guardar nombre_archivo\n";
            cout << "nombre_archivo: Nombre del archivo donde se guardaran las secuencias cargadas en memoria\n";
        }
        else if (strcmp(comando, "ayuda_salir") == 0)
        {
            cout << "AYUDA_SALIR \n";
            cout << "la manera correcta de llamar al comando salir es: "
                 << "salir";
        }
        else if (strcmp(comando, "ayuda_codificar") == 0)
        {
            cout << "AYUDA_CODIFICAR \n";
            cout << "la manera correcta de llamar al comando codificar es: "
                 << "codificar nombre_archivo.fabin\n";
            cout << "nombre_archivo.fabin: Nombre que se le dara al archivo binario en el que se guardara la codificacion de las secuencias.\n";
        }
        else if (strcmp(comando, "ayuda_decodificar") == 0)
        {
            cout << "AYUDA_DECODIFICAR \n";
            cout << "la manera correcta de llamar al comando decodificar es: "
                 << "decodificar nombre_archivo.fabin\n";
            cout << "nombre_archivo.fabin: Nombre del archivo del que se cargan las secuencias a decodificar para despues ser cargadas en memoria\n";
        }
        else if (strcmp(comando, "ayuda_ruta_mas_corta") == 0)
        {
            cout << "AYUDA_RUTA_MAS_CORTA \n";
            cout << "la manera correcta de llamar al comando ruta mas corta es: "
                 << "ruta_mas_corta descirpcion_secuencia i j x y\n";
            cout << "descripcion_secuencia: Secuencia a recorrer buscando la ruta mas corta\n";
            cout << "i,j,x,y: Numeros enteros que representan coordenadas en el grafo. [i,j] representa la posicion inicial y [x,y] representa el destino\n";
        }
        else if (strcmp(comando, "ayuda_base_remota") == 0)
        {
            cout << "AYUDA_BASE_REMOTA \n";
            cout << "la manera correcta de llamar al comando base remota es: "
                 << "base_remota descripcion_secuencia i j\n";
            cout << "descripcion_secuencia: Secuencia a recorrer buscando la base igual a la dada mas alejada\n";
            cout << "i,j: Numeros enteros que representan la posicion de la que se tomara el dato para la comparacion\n";
        }
        else
            cout << "comando invalido" << endl;
        cout << "\n$ ";
        for (int i = 0; i < argc; i++)
        {
            memset(palabra[i], 0, 50);
        }
        strcpy(comando, " ");
        cin.getline(sec, 200);
        argc = countWords(sec, palabra);
        if (argc > 1)
        {
            strcpy(comando, palabra[1]);
        }
        else
            cout << "No ingreso un comando" << endl;
    }
}
int countWords(char *str, char palabra[][50])
{
    if (str == NULL)
        return -1;
    else
    {
        int cont = 1;
        char *p;
        p = strtok(str, " ,");
        strcpy(palabra[0], "Comandos");
        while (p != NULL)
        {
            strcpy(palabra[cont], p);
            cont++;
            p = strtok(NULL, " ,");
        }
        return cont;
    }
}