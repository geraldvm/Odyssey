//
// Created by andres on 11/05/18.
//

#ifndef ARBOLAVL_NODOLISTASIMPLE_H
#define ARBOLAVL_NODOLISTASIMPLE_H

template <typename T>
/**
 * Nodo para una lista Simple
 * @tparam T : Tipo de dato a almacenar
 */
class NodoListaSimple {
private:
    /**
     * Contenido del nodo
     */
    T contenido;
    /**
     * Indice del nodo
     */
    int i = 0;
    /**
     * Nodo siguiente
     */
    NodoListaSimple* siguiente = nullptr;

public:
    /**
     * Getter índice
     * @return índice
     */
    int indice() {
        return i;
    }
    /**
     * Getter contenido
     * @return : Contenido del nodo
     */
    T get() {
        return contenido;
    }
    /**
     * Getter nodo siguiente
     * @return : nodo Siguiente
     */
    NodoListaSimple<T>* next() {
        return siguiente;
    }
    /**
     * Setter de contenido
     * @param cont : Contenido del nodo
     */
    void set(T cont) {
        contenido = cont;
    }
    /**
     * Constructor de la clase
     * @param indice : Índice del nodo actual
     * @param cont : Contenido
     */
    NodoListaSimple(int indice, T cont) {
        set(cont);
        i = indice;
    }
    /**
     * Setter nodo Siguiente
     * @param n : Nodo a agregar
     */
    void setNext(NodoListaSimple *n) {
        siguiente = n;
    }

};


#endif //ARBOLAVL_NODOLISTASIMPLE_H
