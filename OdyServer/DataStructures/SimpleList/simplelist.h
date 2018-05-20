#ifndef SIMPLELIST_H
#define SIMPLELIST_H


#include "node.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <QString>

/*insertar al inicio, insertar al final,
 * insertar en un posición,
 * eliminar al inicio, eliminar al final,
 * eliminar por posición, editar por posición
 * y obtener por posición.
 */
template<typename T>
/**
 * @brief The SimpleList class: Es una estructura de datos dinámica,
 * la lista enlazada simple posee una referencia al nodo siguiente, y además, en cada nodo guarda
 * un dato de tipo genérico.
 */
class SimpleList {

    public:
        SimpleList();
        ~SimpleList();
        /**
         * @brief addFirst: Método que inserta a un nuevo
         * valor en la posición 0.
         * @param data: Dato que
         * el usuario desea ingresar.
         */
        void addFirst(T data);
        /**
         * @brief getLength
         * @return size of SimpleList
         */
        int getLength();
        /**
         * @brief addLast: Agrega el un nuevo dato
         * al final de la lista.
         * @param data: Dato por agregar.
         */
        void addLast(T data);
        /**
         * @brief addPos: Agregar un dato en la posición deseada.
         * @param data: Dato que se desea ingresar.
         * @param pos: Posición en la que se desea ingresar el dato.
         */
        void addPos(T data, int pos);
        /**
         * @brief deleteFirst: Elimina el nodo ubicado en la posición 0 de la lista.
         */
        void deleteFirst();
        /**
         * @brief deleteLast: Elimina el nodo ubicado en la última posición de la lista.
         */
        void deleteLast();
        /**
         * @brief deletePos: Elimina el nodo de la posición seleccionada.
         * @param pos: Posición a eliminar.
         */
        void deletePos(int pos);
        /**
         * @brief editPos: Cambia el valor del dato en la posición seleccionada.
         * @param data: Nuevo dato.
         * @param pos: Posición que se cambiará el dato.
         */
        void editPos(T data, int pos);
        /**
         * @brief findPos: Método de búsqueda por posición.
         * @param pos: Posición que se quiere obtener el dato.
         * @return Retorna el valor del dato en la posición deseada.
         */
        T findPos(int pos);
        /**
         * @brief imprimir: Imprime los valores de la lista secuencialmente.
         */
        void print();
        /**
         * @brief print: Método implementado para que la interfaz gráfica
         * lo emplee para poder imprimir los datos de la lista.
         * @return un QString con los valores de la lista
         */
        QString getString();
        /**
         * @brief getPos: Es el método findPos(pos), implementado para la interfaz gráfica.
         * @param pos: Posición que se desea obtener.
         * @return Retorna el valor de la posición seleccionada en tipo QString.
         */
        QString getPos(int pos);
        T get(int i);
    private:
        Node<T>* head;
        int size;
        bool isEmpty();

};


#endif // SIMPLELIST_H
