#include "leerjson.h"
#include <QTextStream>
using namespace std;

ListaSimple<QJsonObject> leerJson::getUsersInfo() {
    listaArchivosJson = ListaSimple<QJsonObject>();
    QJsonObject obj = QJsonObject();
    QJsonArray array;
    int lineaActual = 0;
    int contadorArreglo = 0;
    string str;
    ifstream file (dirUsers);

    while(getline(file,str)) {
        if (lineaActual == 5) {
            obj.insert("pass",QString::fromStdString(str));
            lineaActual++;
        }
        if (str == "[") {
            lineaActual = -1;
            array = QJsonArray();
        }
        if (lineaActual == 3) {
            obj.insert("edad",QString::fromStdString(str));
            lineaActual++;
        }
        if (lineaActual == 2) {
            obj.insert("apellido",QString::fromStdString(str));
            lineaActual++;
        }
        if (lineaActual == 1) {
            obj.insert("nombre",QString::fromStdString(str));
            lineaActual++;
        }
        if (lineaActual == 0) {
            obj.insert("usuario",QString::fromStdString(str));
            lineaActual++;
        }
        if (lineaActual == -1 && str != "[") {
            if (str != "]") {
                array.push_back(QString::fromStdString(str));
            } else {
                if (contadorArreglo == 0) {
                    obj.insert("favoritos", array);
                    array = QJsonArray();
                    lineaActual = 5;
                    contadorArreglo = 1;
                } else {
                    obj.insert("amigos", array);
                    lineaActual = 0;
                    contadorArreglo = 0;
                    listaArchivosJson.push_back(obj);
                    obj = QJsonObject();
                }
            }
        }

    }
    return listaArchivosJson;
}

ListaSimple<QJsonObject> leerJson::getMetadata() {
    listaArchivosJson = ListaSimple<QJsonObject>();
    QJsonObject obj = QJsonObject();
    int lineaActual = 0;
    QString letra;
    string str;
    ifstream file(dirMetadata);
    while(getline(file,str)) {
        if (lineaActual == -1 && str != "]") {
            letra += QString::fromStdString(str);
        }
        if (lineaActual == 8) {
            lineaActual = -1;
        }
        if (lineaActual == 7) {
            obj.insert("calificacion",QString::fromStdString(str));
            lineaActual++;
        }
        if (lineaActual == 6) {
            obj.insert("anno",QString::fromStdString(str));
            lineaActual++;
        }
        if (lineaActual == 5) {
            obj.insert("numeroDisco",QString::fromStdString(str));
            lineaActual++;
        }
        if (lineaActual == 4) {
            obj.insert("numeroPista",QString::fromStdString(str));
            lineaActual++;
        }
        if (lineaActual == 3) {
            obj.insert("genero",QString::fromStdString(str));
            lineaActual++;
        }
        if (lineaActual == 2) {
            obj.insert("album",QString::fromStdString(str));
            lineaActual++;
        }
        if (lineaActual == 1) {
            obj.insert("artista",QString::fromStdString(str));
            lineaActual++;
        }
        if (lineaActual == 0) {
            obj.insert("titulo",QString::fromStdString(str));
            lineaActual++;
        }
        if (str == "]") {
            lineaActual = 0;
            obj.insert("letra",letra);
            listaArchivosJson.push_back(obj);
            obj = QJsonObject();
        }
    }
    return listaArchivosJson;
}
