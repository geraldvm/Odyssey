//
// Created by andres on 27/04/18.
//

#ifndef ARBOLAVL_ARBOLAVL_H
#define ARBOLAVL_ARBOLAVL_H


#include "NodoAVL.h"
#include "ListaSimple.h"
/**
 * The ArbolAVL class : Clase que corresponde a un árbol de tipo AVL para almacenar los artistas
 */
class ArbolAVL {
    /**
     * Raíz del árbol
     */
    NodoAVL* root;
    /**
     * Factor de nivel, para verificar si el árbol se encuentra dentro del rango de balance permitido
     */
    int factorNivel = 0;

public:
    /**
     * Constructor de la clase
     * @param nombre : Nombre del artista a agregar
     * @param direccion : Direcciónes de los directorios donde se encuentran las canciones
     */
    ArbolAVL(string nombre, ListaSimple<string> direccion);
    /**
     * Agregar un valor al árbol
     * @param nombre : Nombre del artista a agregar
     * @param direccion : Direcciónes de los directorios donde se encuentran las canciones
     */
    void agregarValor(string nombre, ListaSimple<string> direccion);
    /**
     * Función para buscar un valor en el árbol
     * @param nombre : Nombre de la canción a buscar
     * @return : Lista
     */
    ListaSimple<string> buscarValor(string nombre);

private:
    /**
     * Variable para almacenar el contenido de un nodo
     */
    ListaSimple<string> resultado;
    /**
     * Función para obtener la altura del árbol
     * @param raiz : Lugar desde donde se va a iniciar el recorrido
     * @return : Entero con el valor de altura
     */
    int getHeight(NodoAVL* raiz);
    /**
     * Función para obtener el factor de balance
     * @param raiz : Lugar donde se va a iniciar la medición
     * @return : Entero con el valor de diferencia
     */
    int getDiferencia(NodoAVL* raiz);
    /**
     * Función auxiliar para agregar un valor al árbol
     * @param raiz : Lugar desde donde se va a iniciar el desplpazamiento
     * @param nuevo : Nodo a agregar
     */
    void agregarAux(NodoAVL* raiz, NodoAVL* nuevo);
    /**
     * Verifica si hay un valor a la derecha para agregar el nodo
     * @param raiz : Posible padre del nodo
     * @param nuevo : Nodo a agregar
     */
    void agregarDerecha(NodoAVL* raiz, NodoAVL* nuevo);
    /**
     * Verifica si hay un valor a la izquierda para agregar el nodo
     * @param raiz : Posible padre del nodo
     * @param nuevo : Nodo a agregar
     */
    void agregarIzquierda(NodoAVL* raiz, NodoAVL* nuevo);
    /**
     * Función auxiliar para buscr un valor
     * @param nombre : Nombre del artista a buscar
     * @param raiz :Nodo donde se va a buscar
     */
    void buscarAux(string nombre, NodoAVL* raiz);
    /**
     * Función para nivelar el árbol en caso de ser necesario
     * @param raiz : Nodo desde donde se va a iniciar
     * @return : Nuevo nodo raíz
     */
    NodoAVL* nivelar(NodoAVL* raiz);
    /**
     * Función para rotar de izquierda a izquierda una rama
     * @param raiz
     * @return nuevo nodo raíz
     */
    NodoAVL* rotarLL(NodoAVL* raiz);
    /**
     * Función para rotar una rama de izquierda a derecha
     * @param raiz
     * @return nuevo nodo raíz
     */
    NodoAVL* rotarLR(NodoAVL* raiz);
    /**
     * Función para rotar una rama de derecha a derecha
     * @param raiz
     * @return nuevo nodo raíz
     */
    NodoAVL* rotarRR(NodoAVL* raiz);
    /**
     * Función para rotar una rama de derecha a izquierda
     * @param raiz
     * @return nuevo nodo raíz
     */
    NodoAVL* rotarRL(NodoAVL* raiz);

};


#endif //ARBOLAVL_ARBOLAVL_H
