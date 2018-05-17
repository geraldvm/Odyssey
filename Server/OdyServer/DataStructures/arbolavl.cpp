
#include <iostream>
#include <cstring>
#include "nodoavl.h"
#include "arbolavl.h"

ArbolAVL::ArbolAVL(string cont, ListaSimple<string> dir) {
    root = new NodoAVL(cont,dir);
}

void ArbolAVL::agregarValor(string nombre, ListaSimple<string> direccion) {
    NodoAVL* aux = new NodoAVL(nombre,direccion);
    NodoAVL* raiz = root;
    agregarAux(raiz,aux);
    root = nivelar(raiz);
}

void ArbolAVL::agregarAux(NodoAVL* raiz, NodoAVL* nuevo) {
    if (nuevo->getNombre() < raiz->getNombre()) {
        agregarIzquierda(raiz,nuevo);
    } else {
        agregarDerecha(raiz,nuevo);
    }
}

void ArbolAVL::agregarIzquierda(NodoAVL* raiz, NodoAVL* nuevo) {
    if (raiz->getIzquierda() == nullptr) {
        raiz->setIzquierda(nuevo);
    } else {
        agregarAux(raiz->getIzquierda(),nuevo);
    }
}

void ArbolAVL::agregarDerecha(NodoAVL* raiz, NodoAVL* nuevo) {
    if (raiz->getDerecha() == nullptr) {
        raiz->setDerecha(nuevo);
    } else {
        agregarAux(raiz->getDerecha(),nuevo);
    }
}

ListaSimple<string> ArbolAVL::buscarValor(string nombre) {
    NodoAVL* raiz = root;
    buscarAux(nombre,raiz);
    return resultado;
}

void ArbolAVL::buscarAux(string nombre, NodoAVL* raiz) {
    if (strcmp(raiz->getNombre().c_str(),nombre.c_str()) == 0) {
        resultado = raiz->getDireccion();
        return;
    } else {
        if (nombre < raiz->getNombre()) {
            if (raiz->getIzquierda() == nullptr) {
                resultado.push_back("No se encuentra");
                return;
            }
            buscarAux(nombre, raiz->getIzquierda());
        } else {
            if (raiz->getDerecha() == nullptr) {
                resultado.push_back("No se encuentra");
                return;
            }
            buscarAux(nombre, raiz->getDerecha());
        }
    }
}

NodoAVL *ArbolAVL::nivelar(NodoAVL* raiz) {
    int factor = getDiferencia(raiz);
    if (factor > 1) {
        if (getDiferencia(raiz->getIzquierda()) > 0) {
            raiz = rotarLL(raiz);
        } else {raiz = rotarLR(raiz);}
    } else {
        if (factor < -1){
            if (getDiferencia(raiz->getDerecha()) > 0) {
                raiz = rotarRL(raiz);
            } else {raiz = rotarRR(raiz);}
        }
    }
    return raiz;
}

int ArbolAVL::getHeight(NodoAVL *raiz) {
    int heigth = 0;
    if (raiz != nullptr) {
        int heigth_izq = getHeight(raiz->getIzquierda());
        int heigth_der = getHeight(raiz->getDerecha());
        int mayor = max(heigth_izq,heigth_der);
        heigth = mayor + 1;
    }
    return heigth;
}

int ArbolAVL::getDiferencia(NodoAVL *raiz) {
    int heigth_izq = getHeight(raiz->getIzquierda());
    int heigth_der = getHeight(raiz->getDerecha());
    int factor = heigth_izq - heigth_der;
    return factor;
}

NodoAVL *ArbolAVL::rotarRR(NodoAVL *raiz) {
    NodoAVL* aux;
    aux = raiz->getDerecha();
    raiz->setDerecha(aux->getIzquierda());
    aux->setIzquierda(raiz);
    return aux;
}

NodoAVL *ArbolAVL::rotarLL(NodoAVL *raiz) {
    NodoAVL* aux;
    aux = raiz->getIzquierda();
    raiz->setIzquierda(aux->getDerecha());
    aux->setDerecha(raiz);
    return aux;
}

NodoAVL *ArbolAVL::rotarLR(NodoAVL *raiz) {
    NodoAVL *aux;
    aux = raiz->getIzquierda();
    raiz->setIzquierda(rotarRR(aux));
    return rotarLL(raiz);
}

NodoAVL *ArbolAVL::rotarRL(NodoAVL *raiz) {
    NodoAVL *aux;
    aux = raiz->getDerecha();
    raiz->setDerecha(rotarLL(aux));
    return rotarRR(raiz);
}
