#ifndef ARBOLBB_H
#define ARBOLBB_H

#include "nodobb.h"
#include <QString>
#include <iostream>
#include "DataStructures/SimpleList/listasimple.h"

template<class T>
class arbolBB
{
    public:
        void insertAux(NodoBB* node, T data);
        void insert(T data);
        ListaSimple<QJsonObject> preorder();
        NodoBB* deleteNode(QJsonObject data);
        bool search(QString userName);

    private:
        NodoBB* root = nullptr;
        int size = 0;
        void preorderAux(NodoBB* node, ListaSimple<QJsonObject>* usuarios);
        NodoBB* deleteNode(NodoBB* root, T data);
        NodoBB* minValueNode(NodoBB* node);

};

#endif // ARBOLBB_H
