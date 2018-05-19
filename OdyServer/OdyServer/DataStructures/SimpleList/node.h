#ifndef NODE_H
#define NODE_H



#include <iostream>
#include <stdio.h>
#include <stdlib.h>



//using namespace std;
template <class T>
/**
 * @brief The Node class: Clase implementada para la lista simple enlazada.
 * Contiene un dato, y una referencia al siguiente nodo.
 */
class Node {
    public:
        Node();
        Node(T data);
        ~Node();
        void setData(T data);
        void setNext(Node* next);
        T getData();
        void print();
        Node<T>* getNext();



    private:
        Node* next;
        T data;

};

#endif // NODE_H
