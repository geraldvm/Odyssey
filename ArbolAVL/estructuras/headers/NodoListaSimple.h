//
// Created by andres on 11/05/18.
//

#ifndef ARBOLAVL_NODOLISTASIMPLE_H
#define ARBOLAVL_NODOLISTASIMPLE_H

template <typename T>

class NodoListaSimple {
private:
    T contenido;
    int i = 0;
    NodoListaSimple* siguiente = nullptr;

public:

    int indice() {
        return i;
    }

    T get() {
        return contenido;
    }

    NodoListaSimple<T>* next() {
        return siguiente;
    }

    void set(T cont) {
        contenido = cont;
    }

    NodoListaSimple(int indice, T cont) {
        set(cont);
        i = indice;
    }

    void setNext(NodoListaSimple *n) {
        siguiente = n;
    }

};


#endif //ARBOLAVL_NODOLISTASIMPLE_H
