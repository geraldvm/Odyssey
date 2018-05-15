//
// Created by andres on 27/04/18.
//

#include "../headers/NodoAVL.h"

NodoAVL::NodoAVL(string cont, ListaSimple<string> dir) {
    nombre = cont;
    direccion = dir;
}

void NodoAVL::setDerecha(NodoAVL* der) {
    derecha = der;
}

void NodoAVL::setIzquierda(NodoAVL *izq) {
    izquierda = izq;
}

NodoAVL* NodoAVL::getDerecha() {
    return derecha;
}

NodoAVL* NodoAVL::getIzquierda() {
    return izquierda;
}

string NodoAVL::getNombre() {
    return nombre;
}

ListaSimple<string> NodoAVL::getDireccion() {
    return direccion;
}
