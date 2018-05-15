//
// Created by andres on 27/04/18.
//

#ifndef ARBOLAVL_NODOAVL_H
#define ARBOLAVL_NODOAVL_H
#include <iostream>
#include "ListaSimple.h"

using namespace std;

class NodoAVL {

    NodoAVL *izquierda = nullptr;
    NodoAVL *derecha = nullptr;
    string nombre;
    ListaSimple<string> direccion;

public:

    NodoAVL(string cont, ListaSimple<string> dir);
    void setDerecha(NodoAVL* der);
    void setIzquierda(NodoAVL* izq);
    NodoAVL* getDerecha();
    NodoAVL* getIzquierda();
    string getNombre();
    ListaSimple<string> getDireccion();

};

#endif //ARBOLAVL_NODOAVL_H
