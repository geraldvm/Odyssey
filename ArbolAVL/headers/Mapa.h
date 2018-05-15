//
// Created by andres on 01/05/18.
//

#ifndef ARBOLAVL_MAPA_H
#define ARBOLAVL_MAPA_H

#include <iostream>
#include <string>
#include <fstream>
#include "../estructuras/headers/ListaSimple.h"
#include "../estructuras/headers/hashMap.h"

class mapa {

private:
    ListaSimple<int> keys;
    hashMap<std::string, int> passMap;
    std::string dirMap = "../data/map/mapInfo";
    int generarId(std::string nombre);

public:
    void leerMapa();
    void guardarMapa();
    void escribirPass(std::string nombre, std::string pass);
    bool confirmarPass(std::string pass, std::string nombre);
};


#endif //ARBOLAVL_MAPA_H
