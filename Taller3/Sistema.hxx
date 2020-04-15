#include "Sistema.h"
#include <fstream>
#include <ctime>
#include <math.h>
#include <algorithm>

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
                if (!avl.esVacio())
                {
                    avl.valorMax(mayor);
                    avl.eliminar(mayor);
                }
            }
        }
        clock_t end_time = std::clock();
        this->fillInOrderList();
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
                if (find(vec.begin(), vec.end(), cod) == vec.end())
                {
                    vec.push_back(cod);
                    push_heap(vec.begin(), vec.end());
                }
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
        this->tiempo_vec = (end_time - init_time) / double(CLOCKS_PER_SEC);
    }
}
bool Sistema::isEqual()
{
    sort(vec.begin(), vec.end());
    list<int>::iterator it = inOrderList.begin();
    set<int>::iterator its = set1.begin();
    deque<int>::iterator itv = vec.begin();
    if (inOrderList.size() == vec.size() && vec.size() == set1.size())
    {

        for (; it != inOrderList.end(); it++, itv++, its++)
        {
            if (*it != *itv && *itv != *its)
                return false;
        }
        return true;
    }
    return false;
}
void Sistema::fillInOrderList()
{
    if (!avl.esVacio())
    {
        avl.inOrdenL(this->inOrderList);
    }
}
list<int> Sistema::getInOrderList()
{
    return this->inOrderList;
}
set<int> Sistema::getSet()
{
    return this->set1;
}
deque<int> Sistema::getVec()
{
    return this->vec;
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