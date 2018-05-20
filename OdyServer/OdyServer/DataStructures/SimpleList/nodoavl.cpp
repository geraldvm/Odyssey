#include "nodoavl.h"

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

SimpleList<string> NodoAVL::getDireccion() {
    return direccion;
}
