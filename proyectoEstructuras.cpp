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
            if (atoi(palabra[3]) == 0 || atoi(palabra[4]) == 0 || atoi(palabra[5]) == 0 || atoi(palabra[6]) == 0)
                cout << "Una de las coordenadas no es valida, asegurese que sean solo numeros enteros\n";
            cout << "La secuencia dada no existe\n";
        }
        else if (strcmp(comando, "base_remota") == 0)
        {
            char *des = palabra[2];
            if (atoi(palabra[3]) == 0 || atoi(palabra[4]) == 0)
                cout << "Una de las coordenadas no es valida, asegurese que sean solo numeros enteros\n";
            cout << "La secuencia dada no existe\n";
        }
        /*-----------------------------------------------------------------*/
        /*------------------------Richard Fonseca--------------------------*/
        //los ayudas
        else if(strcmp(comando, "ayuda") == 0)
        {
            cout << "AYUDA \n";
            cout<<"Comandos disponibles: \n"
            <<"cargar \t"<<"conteo \t"<<"listar_secuencia \t"<<"histograma \n"
            <<"es_subsecuencia \t"<<"enmascarar \t"<<"guardar \t"<<"salir \n"
            <<"codificar \t"<<"decodificar \t"<<"ruta_mas_corta \t"<<"base_remota \n";

            cout<<"\nSe incluyen los comandos ayuda de cada comando, ayuda_nombre_del_comando \n";

            cout<<"ayuda_cargar \t"<<"ayuda_conteo \t"<<"ayuda_listar_secuencia \t"<<"ayuda_histograma \n"
            <<"ayuda_es_subsecuencia \t"<<"ayuda_enmascarar \t"<<"ayuda_guardar \t"<<"ayuda_salir \n"
            <<"ayuda_codificar \t"<<"ayuda_decodificar \t"<<"ayuda_ruta_mas_corta\t"<<"ayuda_base_remota\n";
        }
        else if(strcmp(comando, "ayuda_cargar") == 0)
        {
            cout << "AYUDA_CARGAR \n";
            cout<<"la manera correcta de llamar al comando cargar es: "<<"cargar";
        }
        else if(strcmp(comando, "ayuda_conteo") == 0)
        {
            cout << "AYUDA_CONTEO \n";
        cout<<"la manera correcta de llamar al comando conteo es: "<<"conteo";
        }
        else if(strcmp(comando, "ayuda_listar_secuencias") == 0)
        {
            cout << "AYUDA_LISTAR_SECUENCIAS \n";
            cout<<"la manera correcta de llamar al comando listar secuencias es: "<<"listar_secuencia";
        }
        else if(strcmp(comando, "ayuda_histograma") == 0)
        {
            cout << "AYUDA_HISTOGRAMA \n";
            cout<<"la manera correcta de llamar al comando histograma es: "<<"histograma";
        }
        
        else if(strcmp(comando, "ayuda_es_subsecuencia") == 0)
        {
            cout << "AYUDA_ES_SUBSECUENCIA \n";
            cout<<"la manera correcta de llamar al comando es subsecuencia es: "<<"es_subsecuencia";
        }
        else if(strcmp(comando, "ayuda_enmascarar") == 0)
        {
            cout << "AYUDA_ENMASCARAR \n";
            cout<<"la manera correcta de llamar al comando enmascarar es: "<<"enmascarar";
        }
        else if(strcmp(comando, "ayuda_guardar") == 0)
        {
            cout << "AYUDA_GUARDAR \n";
            cout<<"la manera correcta de llamar al comando guardar es: "<<"guardar";
        }
        else if(strcmp(comando, "ayuda_salir") == 0)
        {
            cout << "AYUDA_SALIR \n";
            cout<<"la manera correcta de llamar al comando salir es: "<<"salir";
        }
        else if(strcmp(comando, "ayuda_codificar") == 0)
        {
            cout << "AYUDA_CODIFICAR \n";
            cout<<"la manera correcta de llamar al comando codificar es: "<<"codificar";
        }
        else if(strcmp(comando, "ayuda_decodificar") == 0)
        {
            cout << "AYUDA_DECODIFICAR \n";
            cout<<"la manera correcta de llamar al comando decodificar es: "<<"decodificar";
        }
        else if(strcmp(comando, "ayuda_ruta_mas_corta") == 0)
        {
            cout << "AYUDA_RUTA_MAS_CORTA \n";
            cout<<"la manera correcta de llamar al comando ruta mas corta es: "<<"ruta_mas_corta";
        }
        else if(strcmp(comando, "ayuda_base_remota") == 0)
        {
            cout << "AYUDA_BASE_REMOTA \n";
            cout<<"la manera correcta de llamar al comando base remota es: "<<"base_remota";
        }
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
    