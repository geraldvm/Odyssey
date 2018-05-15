//
// Created by andres on 11/05/18.
//

#ifndef ARBOLAVL_HASHMAP_H
#define ARBOLAVL_HASHMAP_H

#include "ListaSimple.h"

template <typename V,typename I>
class hashMap {

private:
    ListaSimple<I> listaIds;

public:
    int size;
    void newPair(V val, I id);
    I get(V val);
    I fromId(int i);
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

template<typename V, typename I>
I hashMap<V, I>::get(V val) {
    return listaIds.get(0);
}


#endif //ARBOLAVL_HASHMAP_H
