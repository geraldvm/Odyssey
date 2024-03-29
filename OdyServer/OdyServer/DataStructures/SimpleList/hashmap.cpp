#include "hashmap.h"
#include <fstream>

void hashmap::leerMapa() {
    std::string line;
    std::string line2;
    std::ifstream file (dirMap);
    int i = 0;
    if (file.is_open()) {
        while (getline(file,line)) {
            if (i == 0) {
                i++;
                line2 = line;
            } else {
                passMap.newPair(line2,stoi(line));
                i--;
            }
        }
        file.close();
    }
}

void hashmap::guardarMapa() {
    std::ofstream file(dirMap, std::ios::binary);
    int j = 0;
    for (int i = 0; i < passMap.size; i++) {
        file << passMap.fromVals(i) + "\n";
        file << std::to_string(passMap.fromId(i)) +"\n";
        j++;
    }
    file.close();
}

void hashmap::escribirPass(std::string nombre, std::string pass) {
    int id = generarId(nombre);
    passMap.newPair(pass,id);
}

int hashmap::generarId(std::string nombre) {
    int id = 0;
    for (char i : nombre) {
        id += i;
    }
    keys.push_back(id);
    return id;
}

bool hashmap::confirmarPass(std::string pass, std::string nombre) {
    return generarId(nombre) == passMap.get(pass);
}
