//
// Created by andres on 11/05/18.
//

#ifndef ARBOLAVL_CANCION_H
#define ARBOLAVL_CANCION_H


#include <QtCore/QJsonObject>

using namespace std;
class cancion {

private:
    string nombre;
    string dir;
    QJsonObject metadata;
    void setMetadata(QJsonObject in);

public:
    cancion(string in, QJsonObject data, string direccion);
    string get(string key);
    string getDir();
    QJsonObject getMetadata();

};


#endif //ARBOLAVL_CANCION_H
