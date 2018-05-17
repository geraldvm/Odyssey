#include <c++/5/iostream>
#include "cancion.h"

void Cancion::setMetadata(QJsonObject in) {
    metadata = in;
}

Cancion::Cancion(string in, QJsonObject data, string direccion) {
    nombre = in;
    metadata = data;
    dir = direccion;

}

string Cancion::get(string key) {
    return metadata.value(QString::fromStdString(key)).toString().toStdString();
}

string Cancion::getDir() {
    return dir;
}

QJsonObject Cancion::getMetadata() {
    return metadata;
}
