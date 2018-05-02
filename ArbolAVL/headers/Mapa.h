//
// Created by andres on 01/05/18.
//

#ifndef ARBOLAVL_MAPA_H
#define ARBOLAVL_MAPA_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

class mapa {

private:
    std::vector<int> keys;
    std::map<std::string, int> passMap;
    std::string dirMap = "./mapInfo";
    int generarId(std::string nombre);

public:
    void leerMapa();
    void guardarMapa();
    void escribirPass(std::string nombre, std::string pass);
    bool confirmarPass(std::string pass, std::string nombre);
};


#endif //ARBOLAVL_MAPA_H
