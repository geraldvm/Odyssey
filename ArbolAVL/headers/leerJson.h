//
// Created by andres on 05/05/18.
//

#ifndef ARBOLAVL_LEERJSON_H
#define ARBOLAVL_LEERJSON_H


#include <QtCore/QJsonArray>
#include "../estructuras/headers/ListaSimple.h"
#include <fstream>
#include <QtCore/QJsonObject>
#include <c++/5/iostream>

class leerJson {
private:
    ListaSimple<QJsonObject> listaArchivosJson = ListaSimple<QJsonObject>();
    std::string dirUsers = "../data/users/usersInfo";
    std::string dirMetadata = "../data/metadata/metadata";

public:
    ListaSimple<QJsonObject> getUsersInfo();
    ListaSimple<QJsonObject> getMetadata();
};


#endif //ARBOLAVL_LEERJSON_H
