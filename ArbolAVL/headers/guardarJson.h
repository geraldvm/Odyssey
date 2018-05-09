//
// Created by andres on 05/05/18.
//

#ifndef ARBOLAVL_GUARDARJSON_H
#define ARBOLAVL_GUARDARJSON_H


#include <c++/5/string>
#include <QtCore/QJsonObject>

class guardarJson {

private:
    std::string dirUsers = "./usersInfo";
    std::string dirMetadata = "./metadata";

public:
    void guardarJsonUsers(QJsonObject archivo);
    void guardarJsonMetadata(QJsonObject archivo);

};


#endif //ARBOLAVL_GUARDARJSON_H
