#ifndef NODOAVL_H
#define NODOAVL_H
#include <iostream>
#include "listasimple.h"

using namespace std;
/**
 * Clase nodoAVl para crear el árbol AVL
 */
class NodoAVL {
    /**
     * Nodo que se encuentra a la izquierda
     */
    NodoAVL *izquierda = nullptr;
    /**
     * Nodo que se encuentra a la derecha
     */
    NodoAVL *derecha = nullptr;
    /**
     * Nombre del artista
     */
    string nombre;
    /**
     * Lista con los directorios de la canciones
     */
    ListaSimple<string> direccion;

public:
    /**
     * Constructor de nodo
     * @param cont : Contenido a agregar
     * @param dir : Lista con las direcciones de las canciones
     */
    NodoAVL(string cont, ListaSimple<string> dir);
    /**
     * Setter nodo derecha
     * @param der : Nodo a agregar
     */
    void setDerecha(NodoAVL* der);
    /**
     * Setter nodo izquierda
     * @param izq : Nodo a agregar
     */
    void setIzquierda(NodoAVL* izq);
    /**
     * Getter nodo derecha
     * @return : Nodo al al derecha
     */
    NodoAVL* getDerecha();
    /**
     * Getter nodo Izquierda
     * @return : Nodo a la izquierda
     */
    NodoAVL* getIzquierda();
    /**
     * Getter nombre de artista
     * @return : Nombre
     */
    string getNombre();
    /**
     * Getter lista de direcciones
     * @return : Lista con las direcciones
     */
    ListaSimple<string> getDireccion();

};

#endif // NODOAVL_H
