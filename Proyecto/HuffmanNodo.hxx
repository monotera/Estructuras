HuffmanNodo::HuffmanNodo(char dato, unsigned int freq) {
    this->der = NULL;
    this->izq = NULL;
    this->dato = dato;
    this->freq = freq;
}
HuffmanNodo::HuffmanNodo() {
    this->der = NULL;
    this->izq = NULL;
}
HuffmanNodo* HuffmanNodo::obtenerHijoIzq (){
    return this->izq;
}
HuffmanNodo* HuffmanNodo::obtenerHijoDer (){
    return this->der;
}
unsigned int HuffmanNodo::obtenerFreq(){
    return this->freq;
}
void HuffmanNodo::fijarHijoDer(HuffmanNodo* der){
    this->der = der;
}
void HuffmanNodo::fijarHijoIzq(HuffmanNodo* izq){
    this->izq = izq;
}
char HuffmanNodo::obtenerDato(){
    return this->dato;
}
bool HuffmanNodo::esHoja(){
    return (this->der == NULL && this->izq == NULL);
}