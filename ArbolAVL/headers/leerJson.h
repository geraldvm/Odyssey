//
// Created by andres on 05/05/18.
//

#ifndef ARBOLAVL_LEERJSON_H
#define ARBOLAVL_LEERJSON_H


#include <QtCore/QJsonArray>
#include <vector>

class leerJson {
private:
    std::vector<QJsonObject> listaArchivosJson;

public:
    std::vector<QJsonObject> getUsersInfo();
    std::vector<QJsonObject> getMetadata();
};


#endif //ARBOLAVL_LEERJSON_H
