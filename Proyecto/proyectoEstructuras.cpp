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

    while (true)
    {
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
        if (strcmp(comando, "cargar") == 0)
        {
            if (argc == 3)
            {
                archivo = new char[strlen(palabra[2])];
                strcpy(archivo, palabra[2]);
                cout << "---CARGAR---" << endl;
                int cantiSec = sys.cargarArchivo(archivo);
                if (cantiSec == -1)
                    cout << "El archivo no se pudo abrir" << endl;
                else if (cantiSec == 0)
                    cout << "El archivo " << sys.getNombre() << " esta vacio" << endl;
                else if (cantiSec == 1)
                    cout << "1 secuencia cargada correctamente desde " << sys.getNombre() << endl;
                else
                    cout << cantiSec << " secuencias cargadas correctamente desde " << sys.getNombre() << endl;
            }
            else
                cout << "El numero de comandos es invalido" << endl;
        }
        else if (strcmp(comando, "conteo") == 0)
        {
            cout << "---CONTEO---" << endl;
            int cantiSec = sys.conteo();
            if (cantiSec == 0)
                cout << "No hay secuencias cargadas en memoria" << endl;
            else if (cantiSec == 1)
                cout << "1 secuencia cargada en memoria " << endl;
            else
                cout << cantiSec << " secuencias cargadas en memoria " << endl;
        }
        else if (strcmp(comando, "listar_secuencias") == 0)
        {
            cout << "---LISTAR SECUENCIA---" << endl;
            if (sys.listar_secuencias() == -1)
                cout << "No hay secuencias cargadas en memoria" << endl;
        }
        else if (strcmp(comando, "histograma") == 0)
        {
            if (argc == 3)
            {
                descriSecuencia = new char[strlen(palabra[2])];
                strcpy(descriSecuencia, palabra[2]);
                cout << "---HISTOGRAMA---" << endl;
                string resp = sys.histograma(descriSecuencia);
                if (resp == "")
                    cout << "Secuencia invalida.\n";
                else
                    cout << resp;
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
                int sub = sys.esSubSecuencia(secuencia);
                if (sys.conteo() == 0)
                    cout << "No hay secuencias cargas en memoria.\n";
                else if (sub == 0)
                    cout << "La secuencia dada no existe.\n";
                else
                    cout << "La secuencia dada se repite " << sub << " veces.\n";
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
                if (sys.conteo() == 0)
                {
                    cout << "No hay secuencias cargadas en memoria." << endl;
                }
                else if (cantiSec == 0)
                    cout << "La secuencia dada no existe, por tanto no se enmascara nada." << endl;
                else if (cantiSec == 1)
                    cout << "1 secuencia ha sido enmascarada." << endl;
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
                if (sys.conteo() == 0)
                {
                    cout << "No hay secuencias cargadas en memoria." << endl;
                }
                else if (sys.guardar(archivo) == 0)
                {
                    cout << "Las secuncias han sido guardadas en " << archivo << endl;
                }
                else if (sys.guardar(archivo) == -1)
                {
                    cout << "Error guardando en " << archivo << endl;
                }
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
            if ((strstr(archivo, ".fabin") != nullptr))
            {
                cout << "---Codificar (Archivo valido)---" << endl;
                if (sys.conteo() == 0)
                {
                    cout << "No hay archivos cargado" << endl;
                }
                else
                {
                    string nom = archivo;
                    if (sys.cifrar(nom))
                    {
                        cout << "Secuencias codificadas y almacenadas en " << nom << endl;
                    }
                    else
                    {
                        cout << "No se pueden guardar las secuencias cargadas en " << nom << endl;
                    }
                }
            }
            else
                cout << "Archivo invalido" << endl;
        }
        else if (strcmp(comando, "decodificar") == 0)
        {
            archivo = new char[strlen(palabra[2])];
            archivo = palabra[2];
            if ((strstr(archivo, ".fabin") != nullptr))
            {
                cout << "---Decodificar (Archivo valido)---" << endl;
                string nom = archivo;
                if (!sys.desCifrar(nom))
                {
                    cout << " No se pueden cargar las secuencias en " << nom << endl;
                }
                else
                {
                    cout << "Secuencias decodificadas desde " << nom << " y cargadas en memoria.";
                }
            }
            else
                cout << "Archivo invalido" << endl;
        }
        else if (strcmp(comando, "ruta_mas_corta") == 0)
        {
            char *des = palabra[2];
            if (argc == 7)
            {
                cout << "---RUTA MAS CORTA---\n";
                string resp = sys.ruta_mas_corta(des, atoi(palabra[3]), atoi(palabra[4]), atoi(palabra[5]), atoi(palabra[6]));
                if (resp == "")
                    cout << "La secuencia dada no existe.\n";
                else if (resp == "1")
                    cout << "La base en la posición [" << palabra[3] << "," << palabra[4] << "] no existe.\n";
                else if (resp == "2")
                    cout << "La base en la posición [" << palabra[5] << "," << palabra[6] << "] no existe.\n";
                else
                    cout << "La ruta mas corta entre la base en [" << palabra[3] << "," << palabra[4] << "] y la base en [" << palabra[5] << "," << palabra[6] << "] es: " << resp;
            }
            else
                cout << "El numero de comandos es invalido" << endl;
            cout << endl;
        }
        else if (strcmp(comando, "base_remota") == 0)
        {
            if (argc == 5)
            {
                char *des = palabra[2];
                cout << "---Base remota---\n";
                string resp = sys.base_remota(des, atoi(palabra[3]), atoi(palabra[4]));
                if (resp == "")
                    cout << "La secuencia dada no existe.\n";
                else if (resp == "1")
                    cout << "La base en la posición [" << palabra[3] << "," << palabra[4] << "] no existe.\n";
                else
                    cout << resp << endl;
            }
            else
                cout << "El numero de comandos es invalido" << endl;
        }
        else if (strcmp(comando, "ayuda") == 0)
        {
            if (argc == 2)
            {
                cout << "AYUDA \n";
                cout << "Comandos disponibles: \n"
                     << "-> cargar \n"
                     << "-> conteo \n"
                     << "-> listar_secuencia \n"
                     << "-> histograma \n"
                     << "-> es_subsecuencia \n"
                     << "-> enmascarar \n"
                     << "-> guardar \n"
                     << "-> salir \n"
                     << "-> codificar \n"
                     << "-> decodificar \n"
                     << "-> ruta_mas_corta \n"
                     << "-> base_remota \n";

                cout << "\nSe incluyen los comandos ayuda de cada comando, ayuda_nombre_del_comando \n";

                cout << "-> ayuda cargar \n"
                     << "-> ayuda conteo \n"
                     << "-> ayuda listar_secuencia \n"
                     << "-> ayuda histograma \n"
                     << "-> ayuda es_subsecuencia \n"
                     << "-> ayuda enmascarar \n"
                     << "-> ayuda guardar \n"
                     << "-> ayuda salir \n"
                     << "-> ayuda codificar \n"
                     << "-> ayuda decodificar \n"
                     << "-> ayuda ruta_mas_corta\n"
                     << "-> ayuda base_remota\n";
            }
            else if (argc == 3)
            {
                char *ayudaComando = new char[strlen(palabra[2])];
                strcpy(ayudaComando, palabra[2]);
                if (strcmp(ayudaComando, "cargar") == 0)
                {
                    cout << "AYUDA CARGAR \n";
                    cout << "la manera correcta de llamar al comando cargar es: "
                         << "cargar nombre_archivo\n";
                    cout << "nombre_archivo: Nombre del archivo del que desea cargar las secuencias para subir a la memoria\n";
                }
                else if (strcmp(ayudaComando, "conteo") == 0)
                {
                    cout << "AYUDA CONTEO \n";
                    cout << "la manera correcta de llamar al comando conteo es: "
                         << "conteo";
                }
                else if (strcmp(ayudaComando, "listar_secuencias") == 0)
                {
                    cout << "AYUDA LISTAR_SECUENCIAS \n";
                    cout << "la manera correcta de llamar al comando listar secuencias es: "
                         << "listar_secuencia";
                }
                else if (strcmp(ayudaComando, "histograma") == 0)
                {
                    cout << "AYUDA HISTOGRAMA \n";
                    cout << "la manera correcta de llamar al comando histograma es: "
                         << "histograma descripcion_secuencia\n";
                    cout << "descripcion_secuencia: Descripcion de la secuencia de la cual se desea generar el histograma(la descripcion es diferente a la secuencia en si)\n";
                }

                else if (strcmp(ayudaComando, "es_subsecuencia") == 0)
                {
                    cout << "AYUDA ES_SUBSECUENCIA \n";
                    cout << "la manera correcta de llamar al comando es subsecuencia es: "
                         << "es_subsecuencia secuencia\n";
                    cout << "secuencia: Secuencia que desea buscar dentro de las secuencias actualmente cargadas\n";
                }
                else if (strcmp(ayudaComando, "enmascarar") == 0)
                {
                    cout << "AYUDA ENMASCARAR \n";
                    cout << "la manera correcta de llamar al comando enmascarar es: "
                         << "enmascarar secuencia\n";
                    cout << "secuencia: La secuencia que el usuario desea enmascarar(todos los codigos se reemplazan por X si la secuencia existe)\n";
                }
                else if (strcmp(ayudaComando, "guardar") == 0)
                {
                    cout << "AYUDA GUARDAR \n";
                    cout << "la manera correcta de llamar al comando guardar es: "
                         << "guardar nombre_archivo\n";
                    cout << "nombre_archivo: Nombre del archivo donde se guardaran las secuencias cargadas en memoria\n";
                }
                else if (strcmp(ayudaComando, "salir") == 0)
                {
                    cout << "AYUDA SALIR \n";
                    cout << "la manera correcta de llamar al comando salir es: "
                         << "salir";
                }
                else if (strcmp(ayudaComando, "codificar") == 0)
                {
                    cout << "AYUDA CODIFICAR \n";
                    cout << "la manera correcta de llamar al comando codificar es: "
                         << "codificar nombre_archivo.fabin\n";
                    cout << "nombre_archivo.fabin: Nombre que se le dara al archivo binario en el que se guardara la codificacion de las secuencias.\n";
                }
                else if (strcmp(ayudaComando, "decodificar") == 0)
                {
                    cout << "AYUDA DECODIFICAR \n";
                    cout << "la manera correcta de llamar al comando decodificar es: "
                         << "decodificar nombre_archivo.fabin\n";
                    cout << "nombre_archivo.fabin: Nombre del archivo del que se cargan las secuencias a decodificar para despues ser cargadas en memoria\n";
                }
                else if (strcmp(ayudaComando, "ruta_mas_corta") == 0)
                {
                    cout << "AYUDA RUTA_MAS_CORTA \n";
                    cout << "la manera correcta de llamar al comando ruta mas corta es: "
                         << "ruta_mas_corta descirpcion_secuencia i j x y\n";
                    cout << "descripcion_secuencia: Secuencia a recorrer buscando la ruta mas corta\n";
                    cout << "i,j,x,y: Numeros enteros que representan coordenadas en el grafo. [i,j] representa la posicion inicial y [x,y] representa el destino\n";
                }
                else if (strcmp(ayudaComando, "base_remota") == 0)
                {
                    cout << "AYUDA BASE_REMOTA \n";
                    cout << "la manera correcta de llamar al comando base remota es: "
                         << "base_remota descripcion_secuencia i j\n";
                    cout << "descripcion_secuencia: Secuencia a recorrer buscando la base igual a la dada mas alejada\n";
                    cout << "i,j: Numeros enteros que representan la posicion de la que se tomara el dato para la comparacion\n";
                }
                else
                    cout << "Error, el comando no existe" << endl;
            }
        }

        else
            cout << "comando invalido" << endl;
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