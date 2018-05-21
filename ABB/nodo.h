#ifndef NODO_H
#define NODO_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template <class T>
class Nodo
{
public:
    Nodo();
    Nodo(T data);
    ~Nodo();
    void setData(T data);
    void setRight(Nodo* next);
    void setLeft(Nodo* left);
    int getData();
    Nodo* getLeft();
    Nodo* getRight();

private:
    Nodo* left;
    Nodo* right;
    T data;
};

#endif // NODO_H
