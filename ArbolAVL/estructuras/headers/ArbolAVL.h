//
// Created by andres on 27/04/18.
//

#ifndef ARBOLAVL_ARBOLAVL_H
#define ARBOLAVL_ARBOLAVL_H


#include "NodoAVL.h"
#include "ListaSimple.h"

class ArbolAVL {

    NodoAVL* root;
    int factorNivel = 0;

public:
    ArbolAVL(string nombre, ListaSimple<string> direccion);
    void agregarValor(string nombre, ListaSimple<string> direccion);
    void eliminarValor(string nombre);
    ListaSimple<string> buscarValor(string nombre);

private:
    ListaSimple<string> resultado;
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
