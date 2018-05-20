#include <c++/5/iostream>
#include "cancion.h"

void cancion::setMetadata(QJsonObject in) {
    metadata = in;
}

cancion::cancion(string in, QJsonObject data, string direccion) {
    nombre = in;
    metadata = data;
    dir = direccion;

}

string cancion::get(string key) {
    return metadata.value(QString::fromStdString(key)).toString().toStdString();
}

string cancion::getDir() {
    return dir;
}

QJsonObject cancion::getMetadata() {
    return metadata;
}
