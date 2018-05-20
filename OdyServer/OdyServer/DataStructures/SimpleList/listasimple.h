#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H


#include "nodolistasimple.h"

template <typename T>
class ListaSimple {

private:
    NodoListaSimple<T>* inicio = nullptr;

public:
    int size = 0;

    void push_back(T cont) {
        if (inicio == nullptr) {
            inicio = new NodoListaSimple<T>(size,cont);
        } else {
            NodoListaSimple<T> *aux = inicio;
            for (int i = 0; i < size; i++) {
                if (inicio->next() == nullptr) {
                    inicio->setNext(new NodoListaSimple<T>(size,cont));
                } else {
                    inicio = inicio->next();
                }
            }
            inicio = aux;
        }
        size++;
    }

    T get(int indice) {
        NodoListaSimple<T> *aux = inicio;
        if (indice == 0) { return inicio->get();}
        for (int i = 0; i < indice; i++) {
            inicio = inicio->next();
        }
        T cont = inicio->get();
        inicio = aux;
        return cont;
    }

    ListaSimple() {

    }
};
#endif // LISTASIMPLE_H
