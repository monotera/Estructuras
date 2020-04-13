#include "Sistema.h"
#include <fstream>
#include <ctime>
#include <math.h>

void Sistema::uploadFile(string fName)
{
    string line;
    ifstream myFile(fName);
    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            this->l.push_back(line);
        }
    }
    else
    {
        cout << "Fail to open" << endl;
    }
}
void Sistema::fillTree()
{
    if (!this->l.empty())
    {
        clock_t init_time = clock();
        int mayor = 0;
        list<string>::iterator it;
        for (it = l.begin(); it != l.end(); it++)
        {
            if ((*it)[0] == 'A' || (*it)[0] == 'a')
            {
                cod = atoi((*it).substr(1, 7).c_str());
                avl.insertar(cod);
            }
            else
            {
                inOrderList.clear();
                avl.inOrdenL(this->inOrderList);
                mayor = this->inOrderList.back();
                avl.eliminar(mayor);
            }
        }
        clock_t end_time = std::clock();
        cout << avl.tamano() << endl;
        this->tiempo_arbol = (end_time - init_time) / double(CLOCKS_PER_SEC);
    }
}

void Sistema::fillSet()
{
    if (!this->l.empty())
    {
        clock_t init_time = clock();
        list<string>::iterator it;
        set<int>::reverse_iterator its;
        for (it = l.begin(); it != l.end(); it++)
        {
            if ((*it)[0] == 'A' || (*it)[0] == 'a')
            {
                cod = atoi((*it).substr(1, 7).c_str());
                set1.insert(cod);
            }
            else
            {
                if (!set1.empty())
                {
                    its = set1.rbegin();
                    set1.erase(*its);
                }
            }
        }
        cout <<endl <<set1.size()<<endl;
        clock_t end_time = std::clock();
        this->tiempo_set = (end_time - init_time) / double(CLOCKS_PER_SEC);
    }
}
void Sistema::fillVec()
{
    if (!this->l.empty())
    {
        list<string>::iterator it;
        clock_t init_time = clock();
        for (it = l.begin(); it != l.end(); it++)
        {
            if ((*it)[0] == 'A' || (*it)[0] == 'a')
            {
                cod = atoi((*it).substr(1, 7).c_str());
                vec.push_back(cod);
                push_heap(vec.begin(), vec.end());
            }
            else
            {
                if (!vec.empty())
                {
                    pop_heap(vec.begin(), vec.end());
                    vec.pop_back();
                }
            }
        }
        clock_t end_time = std::clock();
        cout << vec.size();
        this->tiempo_vec = (end_time - init_time) / double(CLOCKS_PER_SEC);
    }
}

double Sistema::getTiempo_arbol()
{
    return this->tiempo_arbol;
}
double Sistema::getTiempo_set()
{
    return this->tiempo_set;
}
double Sistema::getTiempo_vec()
{
    return this->tiempo_vec;
}