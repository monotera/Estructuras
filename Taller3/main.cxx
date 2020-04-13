#include "Sistema.h"
using namespace std;

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        string file = argv[1];
        Sistema sys;
        sys.uploadFile(file);
        //sys.fillTree();
        sys.fillSet();
        sys.fillVec();
        cout << endl
             << sys.getTiempo_arbol() << " " << sys.getTiempo_set() << " " << sys.getTiempo_vec() << endl;
    }
    else
        cout << "ERROR!" << endl;
}
