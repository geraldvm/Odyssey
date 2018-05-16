#include "node.h"

// Constructor por defecto
template<typename T>
Node<T>::Node()
{
    data = NULL;
    next = NULL;
}

// Constructor por parámetro
template<typename T>
Node<T>::Node(T _data)
{
    data = _data;
    next = NULL;
}

template<typename T>
void Node<T>::setData(T _data) {
    data=_data;
}



template<typename T>
Node<T>::~Node() {
    delete next;
}

template<class T>
void Node<T>::setNext(Node* _next) {
    next=_next;

}

template<class T>
T Node<T>::getData() {
    return data;
}

template<class T>
Node<T> *Node<T>::getNext() {
    return next;
}

template<class T>
void Node<T>::print() {
    std::cout << data << "-> ";
    //std::string str =std::to_string(data);
    //printf(std::to_string(data));
}
