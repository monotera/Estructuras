#include "Sistema.h"
using namespace std;

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        string file = argv[1];
        Sistema sys;
        list<int> l;
        set<int> s;
        deque<int> v;
        list<int>::iterator itl;
        set<int>::iterator its;
        deque<int>::iterator itd;
        sys.uploadFile(file);
        sys.fillTree();
        sys.fillSet();
        sys.fillVec();
        cout << endl
             << "El tiempo del arbol fue   : " << sys.getTiempo_arbol() << endl
             << "El tiempo del set fue     : " << sys.getTiempo_set() << endl
             << "El tiempo del vector fue  : " << sys.getTiempo_vec() << endl;
        l = sys.getInOrderList();
        s = sys.getSet();
        v = sys.getVec();
        cout << endl
             << "El tamano del arbol fue   : " << l.size() << endl
             << "El tamano del set fue     : " << s.size() << endl
             << "El tamano del vector fue  : " << v.size() << endl;
        if(sys.isEqual()){
            cout << "Tienen el mismo contenido" <<endl;
        }
        else {
            cout << "No tienen el mismo contenido" <<endl;
        }
    }
    else
        cout << "ERROR!" << endl;
}
