//
// Created by andres on 27/04/18.
//

#ifndef ARBOLAVL_ARBOLAVL_H
#define ARBOLAVL_ARBOLAVL_H


#include "NodoAVL.h"

class ArbolAVL {

    NodoAVL* root;
    int factorNivel = 0;

public:
    ArbolAVL(string nombre, string direccion);
    void agregarValor(string nombre, string direccion);
    void eliminarValor(string nombre);
    string buscarValor(string nombre);

private:
    string resultado;
    int getHeight(NodoAVL* raiz);
    int getDiferencia(NodoAVL* raiz);
    void agregarAux(NodoAVL* raiz, NodoAVL* nuevo);
    void agregarDerecha(NodoAVL* raiz, NodoAVL* nuevo);
    void agregarIzquierda(NodoAVL* raiz, NodoAVL* nuevo);
    void buscarAux(string nombre, NodoAVL* raiz);
    NodoAVL* nivelar(NodoAVL* raiz);
    NodoAVL* rotarLL(NodoAVL* raiz);
    NodoAVL* rotarLR(NodoAVL* raiz);
    NodoAVL* rotarRR(NodoAVL* raiz);
    NodoAVL* rotarRL(NodoAVL* raiz);

};


#endif //ARBOLAVL_ARBOLAVL_H
