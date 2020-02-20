/*Realizado por Nelson Mosquera, Andres Torres y Richard Fonseca*/

#include <iostream>
#include <string.h>

int countWords(char *str, char palabra[][50]);

using namespace std;

int main(int argc, char *argv[])
{
    /*-------------------------VARIABLES------------------------------*/
    char *comando = new char[2];
    char *archivo;
    char *secuencia, *descriSecuencia, sec[200];
    char palabra[20][50];

    /*-----------------------------------------------------------------*/
    /*------------------------Nelson Mosquera--------------------------*/
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
            }
            else
                cout << "El numero de comandos es invalido" << endl;
        }
        else if (strcmp(comando, "conteo") == 0)
        {
            cout << "---CONTEO---" << endl;
        }
        else if (strcmp(comando, "listar_secuencias") == 0)
        {
            cout << "---LISTAR SECUENCIA---" << endl;
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

        /*-----------------------------------------------------------------*/
        /*------------------------Andres Torres----------------------------*/
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
            if(argc == 7){
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
            if(argc == 5){
                char *des = palabra[2];
                if (atoi(palabra[3]) == 0 || atoi(palabra[4]) == 0)
                    cout << "Una de las coordenadas no es valida, asegurese que sean solo numeros enteros\n";
                cout << "---Base remota---";
                cout << "La secuencia dada no existe\n";
            }
            else
                cout << "El numero de comandos es invalido" << endl;
        }
        /*-----------------------------------------------------------------*/
        /*------------------------Richard Fonseca--------------------------*/
        //CODE
        /*-----------------------------------------------------------------*/
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
