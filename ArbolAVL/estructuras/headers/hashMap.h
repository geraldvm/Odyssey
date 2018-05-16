//
// Created by andres on 11/05/18.
//

#ifndef ARBOLAVL_HASHMAP_H
#define ARBOLAVL_HASHMAP_H

#include "ListaSimple.h"

template <typename V,typename I>
/**
 * @brief The hashMap class : Clase que forma el hashMap para guardar las contraseñas
 */
class hashMap {

private:
    /**
     * @brief listaIds : Lista simple que contiene todos los índices que señalan las contraseñas
     */
    ListaSimple<I> listaIds;
    /**
     * @brief listaValores : Lista Simple que contiene las contraseñas
     */
    ListaSimple<string> listaValores;

public:
    /**
     * @brief size : Entero que contiene la cantidad de valores agregados
     */
    int size;
    /**
     * @brief newPair : Función que recibe la contraseña y el id para agregarlos
     * @param val : String contraseña
     * @param id : Valor que corresponde al indice
     */
    void newPair(V val, I id);
    /**
     * @brief get : Función para obtener el id de un valor
     * @param val : Valor a buscar
     * @return : id del valor
     */
    I get(V val);
    /**
     * @brief fromId : Busca en la lista de id según un índice
     * @param i : Indice a buscar
     * @return : id encontrado
     */
    I fromId(int i);
    /**
     * @brief fromVals : Busca por índice el la lista de Valores
     * @param i : Indice a buscar
     * @return : Valor
     */
    V fromVals(int i);
};

template<typename V, typename I>
void hashMap<V, I>::newPair(V val, I id) {
    size++;
    listaIds.push_back(id);
    listaValores.push_back(val);
}

template<typename V, typename I>
I hashMap<V, I>::fromId(int i) {
    return listaIds.get(i);
}

template <typename V,typename I>
V hashMap<V ,I>::fromVals(int i) {
    return listaValores.get(i);
};


template<typename V, typename I>
I hashMap<V, I>::get(V val) {
    for (int i = 0; i < size; i++){
        if (val == listaValores.get(i)) {
            return listaIds.get(i);
        }
    }
    return -1;
}




#endif //ARBOLAVL_HASHMAP_H
