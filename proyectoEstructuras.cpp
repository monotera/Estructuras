/*Realizado por Nelson Mosquera, Andres Torres y Richard Fonseca*/

#include <iostream>
#include <string.h>

using namespace std;
 
 int main (int argc, char* argv[]){
     /*-------------------------VARIABLES------------------------------*/
    char * comando = new char[strlen(argv[1])];
    comando = argv[1];
    char * archivo;
    /*-----------------------------------------------------------------*/
    /*------------------------Nelson Mosquera--------------------------*/
    //CODE
    /*-----------------------------------------------------------------*/
    /*------------------------Andres Torres----------------------------*/
    if(strcmp(comando,"codificar")==0){
        archivo = new char[strlen(argv[2])];
        archivo = argv[2];
        if((strstr(archivo,".fa")!=nullptr))
            cout << "Archivo valido" << endl;
        else
            cout << "Archivo invalido" << endl;
    }
    if(strcmp(comando,"decodificar")==0){
        archivo = new char[strlen(argv[2])];
        archivo = argv[2];
        if((strstr(archivo,".fa")!=nullptr))
            cout << "Archivo valido" << endl;
        else
            cout << "Archivo invalido" << endl;
    }
    else if(strcmp(comando,"ruta_mas_corta")==0){
        char *des = argv[2];
        if(atoi(argv[3])==0||atoi(argv[4])==0||atoi(argv[5])==0||atoi(argv[6])==0)
            cout << "Una de las coordenadas no es valida, asegurese que sean solo numeros enteros\n";
        cout << "Busca la descirpcion dentro del archivo e imprime la ruta y peso mas corto\n";
    }
    else if(strcmp(comando,"base_remota")==0){
        char *des = argv[2];
        if(atoi(argv[3])==0||atoi(argv[4])==0)
            cout << "Una de las coordenadas no es valida, asegurese que sean solo numeros enteros\n";
        cout << "baba\n";
    }
    /*-----------------------------------------------------------------*/
    /*------------------------Richard Fonseca--------------------------*/
    //CODE
    /*-----------------------------------------------------------------*/
 }