//
// Created by andres on 27/04/18.
//

#ifndef ARBOLAVL_NODOAVL_H
#define ARBOLAVL_NODOAVL_H
#include <iostream>

using namespace std;

class NodoAVL {

    NodoAVL *izquierda = nullptr;
    NodoAVL *derecha = nullptr;
    string nombre;
    string direccion;

public:

    NodoAVL(string cont, string dir);
    void setDerecha(NodoAVL* der);
    void setIzquierda(NodoAVL* izq);
    NodoAVL* getDerecha();
    NodoAVL* getIzquierda();
    string getNombre();
    string getDireccion();

};

#endif //ARBOLAVL_NODOAVL_H
