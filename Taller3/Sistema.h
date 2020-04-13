#ifndef __SISTEMA__H__
#define __SISTEMA__H__

#include <iostream>
#include <string>
#include <set>
#include <deque>
#include <algorithm>
#include "ArbolAVL.h"

using namespace std;


class Sistema
{
private:
    ArbolAVL<int> avl;
    deque <int> vec;
    set<int> set1;
    list<string> l;
    list<int> inOrderList;
    int cod;
    double tiempo_arbol = 0;
    double tiempo_set = 0;
    double tiempo_vec = 0;
public:
    void uploadFile(string fileName);
    void fillTree();
    void fillSet();
    void fillVec();
    double getTiempo_arbol();
    double getTiempo_set();
    double getTiempo_vec();
    deque <int> getVec();
    set<int> getSet();
    list<int> getInOrderList();
    void fillInOrderList();
};


#include "Sistema.hxx"
#endif