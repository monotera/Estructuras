#include "secuencia.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>


using namespace std;

void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr);


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
    string combinado = "";
    for(;it != linea.end();it++)
        combinado+=(*it);
    p = combinado.find(sub);
    while(p!=string::npos){
        cant++;
        p = combinado.find(sub, p+sub.size());
    }
    return cant;
}
int secuencia::enmascarar(string sub){
    int cantiEnmascarar = esSubSecuencia(sub);
    string replaceSTR;
    string temp;
    for(int i = 0; i < sub.size(); ++i)
        replaceSTR += "X";
    list<string>::iterator it = linea.begin();
    int ancho = (*it).size();
    for(;it != linea.end();it++)
        temp+=(*it);  
    findAndReplaceAll(temp,sub,replaceSTR); 
    it = linea.begin();
    int util = 0;
    for(;it != linea.end();it++){
        if((*it).size()==ancho)
            (*it)=temp.substr(util*ancho,ancho+1);
        else
            (*it)=temp.substr(util*ancho,(*it).size());        
        util++;
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
    nuevaDesc.erase(nuevaDesc.begin(),nuevaDesc.begin()+1);
   this->descripcion = nuevaDesc;
}
int secuencia::setCantiBase(){
    list <string> :: iterator it;
    long cont = 0;
    int incompleto = 0;
    for(it = linea.begin(); it != linea.end();it++){
            vector <char> linea ((*it).begin(),(*it).end());
            for(int i = 0; i < (*it).length(); ++i){
                if(linea[i] == 'A' || linea[i] == 'C'  || linea[i] == 'G' ||
                   linea[i] == 'T' || linea[i] == 'U'  || linea[i] == 'R' ||
                   linea[i] == 'Y' || linea[i] == 'K'  || linea[i] == 'M' ||
                   linea[i] == 'S' || linea[i] == 'W'  || linea[i] == 'B' ||
                   linea[i] == 'D' || linea[i] == 'H'  || linea[i] == 'V' ||
                   linea[i] == 'N' || linea[i] == 'X' )
                    cont++;
                else if(linea[i] == '-')
                    incompleto = -1;
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
    if(a!=0)resp+="A: "+to_string(a)+"\n"; 
    c = esSubSecuencia("C");
    if(c!=0)resp+="C: "+to_string(c)+"\n";
    g = esSubSecuencia("G");
    if(g!=0)resp+="G: "+to_string(g)+"\n";
    t = esSubSecuencia("T");
    if(t!=0)resp+="T: "+to_string(t)+"\n";
    u = esSubSecuencia("U");
    if(u!=0)resp+="U: "+to_string(u)+"\n";
    r = esSubSecuencia("R");
    if(r!=0)resp+="R: "+to_string(r)+"\n";
    y = esSubSecuencia("Y");
    if(y!=0)resp+="Y: "+to_string(y)+"\n";
    k = esSubSecuencia("K");
    if(k!=0)resp+="K: "+to_string(k)+"\n";
    m = esSubSecuencia("M");
    if(m!=0)resp+="M: "+to_string(m)+"\n";
    s = esSubSecuencia("S");
    if(s!=0)resp+="S: "+to_string(s)+"\n";
    w = esSubSecuencia("W");
    if(w!=0)resp+="W: "+to_string(w)+"\n";
    b = esSubSecuencia("B");  
    if(b!=0)resp+="B: "+to_string(b)+"\n";
    d = esSubSecuencia("D"); 
    if(d!=0)resp+="D: "+to_string(d)+"\n";
    h = esSubSecuencia("H"); 
    if(h!=0)resp+="H: "+to_string(h)+"\n";
    v = esSubSecuencia("V"); 
    if(v!=0)resp+="V: "+to_string(v)+"\n";
    n = esSubSecuencia("N"); 
    if(n!=0)resp+="N: "+to_string(n)+"\n";
    x = esSubSecuencia("X");
    if(x!=0)resp+="X: "+to_string(x)+"\n";
    inc = esSubSecuencia("-");
    if(inc!=0)resp+="-: "+to_string(inc)+"\n";
    
    return resp;
}
string secuencia::getSecuenciaLinea(){
    string secLinea = "";
    list <string>::iterator it;
    for(it = linea.begin(); it != linea.end(); it++){
        secLinea += *it;
    }
    return secLinea;

}
int secuencia::getIndentacion(){
    return this->linea.front().size();
}
void secuencia::crearLista(int f[]){
    list<int> resp;
    f[0] = esSubSecuencia("A"); 
    f[1] = esSubSecuencia("C");
    f[2] = esSubSecuencia("G");
    f[3] = esSubSecuencia("T");
    f[4] = esSubSecuencia("U");
    f[5] = esSubSecuencia("R");
    f[6] = esSubSecuencia("Y");
    f[7] = esSubSecuencia("K");
    f[8] = esSubSecuencia("M");
    f[9] = esSubSecuencia("S");
    f[10] = esSubSecuencia("W");
    f[11] = esSubSecuencia("B");  
    f[12] = esSubSecuencia("D"); 
    f[13] = esSubSecuencia("H"); 
    f[14] = esSubSecuencia("V"); 
    f[15] = esSubSecuencia("N"); 
    f[16] = esSubSecuencia("X");
    f[17] = esSubSecuencia("-");
}