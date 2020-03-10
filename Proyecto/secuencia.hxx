#include "secuencia.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>


using namespace std;

void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr);

int secuencia::getAncho(){
    return this->ancho;
}
void secuencia::setAncho(int ancho){
    this->ancho = ancho;
}
list <string> secuencia::getLineas(){
    return this->linea;
}
void secuencia::agregarLinea(string lineaNueva){
    linea.push_back(lineaNueva);
}
int secuencia::esSubSecuencia(string sub){
    int cant = 0;
    list<string>::iterator it = linea.begin();
    size_t p;
    for(;it != linea.end();it++){
        p = (*it).find(sub);
        while(p!=string::npos){
            cant++;
            p = (*it).find(sub, p+sub.size());
        }
    }
    return cant;
}
int secuencia::enmascarar(string sub){
    int cantiEnmascarar = esSubSecuencia(sub);
    string replaceSTR;
    for(int i = 0; i < sub.size(); ++i)
        replaceSTR += "X";
    list<string>::iterator it = linea.begin();
    for(;it != linea.end();it++){
        findAndReplaceAll(*it,sub,replaceSTR);   
    }
    return cantiEnmascarar;
}
void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);
 
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceStr);
		// Get the next occurrence from the current position
		pos =data.find(toSearch, pos + replaceStr.size());
	}
}
string secuencia::getDescripcione(){
    return this->descripcion;
}
void secuencia::setDescripcion(string nuevaDesc){
   this->descripcion = nuevaDesc;
}
int secuencia::setCantiBase(){
    list <string> :: iterator it;
    long cont = 0;
    int incompleto = 0;
    for(it = linea.begin(); it != linea.end();it++){
            vector <char> linea ((*it).begin(),(*it).end());
            for(int i = 0; i < (*it).length(); ++i){
                if(linea[i] == 'A' || linea[i] == 'C' || linea[i] == 'G' || linea[i] == 'T' || linea[i] == 'U'){
                    cont++;
                }
                if(linea[i] == '-'){
                    incompleto = -1;
                }
        }
    }
    this->cantiBase = cont;
    return  incompleto;
}
int secuencia::getCantiBase(){
    return this->cantiBase;
}
void secuencia::borrarLineas(){
    linea.clear();
}

string secuencia::histograma(){
    string resp = "";
    int a,c,g,t,u,r,y,k,m,s,w,b,d,h,v,n,x,inc;
    a = esSubSecuencia("A");  
    c = esSubSecuencia("C");
    g = esSubSecuencia("G");
    t = esSubSecuencia("T");
    u = esSubSecuencia("U");
    r = esSubSecuencia("R");
    y = esSubSecuencia("Y");
    k = esSubSecuencia("K");
    m = esSubSecuencia("M");
    s = esSubSecuencia("S");
    w = esSubSecuencia("W");
    b = esSubSecuencia("B");  
    d = esSubSecuencia("D"); 
    h = esSubSecuencia("H"); 
    v = esSubSecuencia("V"); 
    n = esSubSecuencia("N"); 
    x = esSubSecuencia("X");
    inc = esSubSecuencia("-");
    resp+="A: "+to_string(a)+"\n"+"C: "+to_string(c)+"\n"+"G: "+to_string(g)+"\n"+
    "T: "+to_string(t)+"\n"+"U: "+to_string(u)+"\n"+"R: "+to_string(r)+"\n"+
    "Y: "+to_string(y)+"\n"+"K: "+to_string(k)+"\n"+"M: "+to_string(k)+"\n"+
    "S: "+to_string(s)+"\n"+"W: "+to_string(w)+"\n"+"B: "+to_string(b)+"\n"+
    "D: "+to_string(d)+"\n"+"H: "+to_string(h)+"\n"+"V: "+to_string(v)+"\n"+
    "N: "+to_string(n)+"\n"+"X: "+to_string(x)+"\n"+"-: "+to_string(inc)+"\n";
    return resp;
}