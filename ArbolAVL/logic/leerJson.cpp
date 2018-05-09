//
// Created by andres on 05/05/18.
//

#include <fstream>
#include <QtCore/QJsonObject>
#include <c++/5/iostream>
#include "../headers/leerJson.h"

using namespace std;

vector<QJsonObject> leerJson::getUsersInfo() {
    QJsonObject obj = QJsonObject();
    string str;
    QJsonArray array;
    int lineaActual = 0;
    int contadorArreglo = 0;
    ifstream in("./usersInfo", ios::binary);

    while(getline(in, str)) {
        if (lineaActual == 5) {
            obj.insert("pass",stoi(str));
            lineaActual++;
        }
        if (str == "[") {
            lineaActual = -1;
            array = QJsonArray();
        }
        if (lineaActual == 3) {
            obj.insert("edad",stoi(str));
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
            obj.insert("usuario", QString::fromStdString(str));
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

std::vector<QJsonObject> leerJson::getMetadata() {
    QJsonObject obj = QJsonObject();
    string str;
    int lineaActual = 0;
    ifstream in("./metadata", ios::binary);

    while(getline(in, str)) {
        if (lineaActual == 6) {
            obj.insert("anno",stoi(str));
            lineaActual = 0;
            listaArchivosJson.push_back(obj);
            obj = QJsonObject();
        }
        if (lineaActual == 5) {
            obj.insert("numeroDisco",stoi(str));
            lineaActual++;
        }
        if (lineaActual == 4) {
            obj.insert("numeroPista",stoi(str));
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
    }
    return listaArchivosJson;
}
