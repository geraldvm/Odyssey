//
// Created by andres on 05/05/18.
//

#ifndef ARBOLAVL_GUARDARJSON_H
#define ARBOLAVL_GUARDARJSON_H


#include <c++/5/string>
#include <QtCore/QJsonObject>
#include <fstream>
#include <QtCore/QJsonArray>

class guardarJson {

private:
    std::string dirUsers = "../data/users/usersInfo";
    std::string dirMetadata = "../data/metadata/metadata";

public:
    void guardarJsonUsers(QJsonObject archivo);
    void guardarJsonMetadata(QJsonObject archivo);

};


#endif //ARBOLAVL_GUARDARJSON_H
