#ifndef ABB_H
#define ABB_H
#include "Node/nodo.h"
#include <QString>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
template<typename T>
class ABB
{
    public:
        ABB();
        void insert(T data);
        void preorder();
        void inorder();
        void postorder();
        int findMin();
        int findMax();
        Nodo<T>* deleteNode(T data);
        QString printMin();
        QString printMax();

    private:
        Nodo<T>* root;
        int size;
        void insert(Nodo<T>* node, T data);
        void preorder(Nodo<T>* node);
        void inorder(Nodo<T>* node);
        void postorder(Nodo<T>* node);
        int findMin_aux();
        int findMax_aux();
        Nodo<T>* minValueNode(Nodo<T>* node);
        Nodo<T>* deleteNode(Nodo<T>* root, T data);
        QString printMin_aux();
        QString printMax_aux();

};
#endif // ABB_H
