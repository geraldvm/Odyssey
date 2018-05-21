#include "nodo.h"


template<typename T>
Nodo<T>::Nodo()
{
    this->data = NULL;
    this->left = NULL;
    this->right = NULL;
}
template<typename T>
Nodo<T>::~Nodo()
{

}
template<typename T>
Nodo<T>::Nodo(T data)
{
    this->data = data;
    this->right = NULL;
    this->left = NULL;
}

template<typename T>
void Nodo<T>::setData(T data) {
    this->data=data;
}

template<typename T>
void Nodo<T>::setRight(Nodo* next) {
    this->right=next;
}

template<typename T>
void Nodo<T>::setLeft(Nodo* left) {
    this->left=left;
}
template<typename T>
T Nodo<T>::getData() {
    return this->data;
}

template<typename T>
Nodo *Nodo<T>::getLeft() {
    return this->left;
}
template<typename T>
Nodo *Nodo<T>::getRight() {
    return this->right;
}
