#ifndef NODOAVL_H
#define NODOAVL_H

#include <iostream>
#include "simplelist.h"

using namespace std;

class NodoAVL {

    NodoAVL *izquierda = nullptr;
    NodoAVL *derecha = nullptr;
    string nombre;
    SimpleList<string> direccion;

public:

    NodoAVL(string cont, SimpleList<std::string> dir) {
        nombre = cont;
        direccion = dir;
    }
    void setDerecha(NodoAVL* der);
    void setIzquierda(NodoAVL* izq);
    NodoAVL* getDerecha();
    NodoAVL* getIzquierda();
    string getNombre();
    SimpleList<string> getDireccion();

};

#endif // NODOAVL_H
