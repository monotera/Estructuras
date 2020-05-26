NodoGrafo::NodoGrafo(){
}
NodoGrafo::NodoGrafo(int x, int y, char letra){
    this->letra = letra;
    this->x = x;
    this->y = y;
}
char NodoGrafo::getLetra(){
    return this->letra;
}
int NodoGrafo::getX(){
    return this->x;
}
int NodoGrafo::getY(){
    return this->y;
}
void NodoGrafo::setLetra(char letra){
    this->letra = letra;
}
void NodoGrafo::setX(int x){
    this->x = x;
}
void NodoGrafo::setY(int y){
    this->y = y;
}
double NodoGrafo::calcularConexion(char l){
    int resta=abs((int) letra - (int)l);
    return (double) 1/(1+resta);

}