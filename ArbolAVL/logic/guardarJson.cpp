//
// Created by andres on 05/05/18.
//

#include <fstream>
#include <QtCore/QJsonArray>
#include "../headers/guardarJson.h"

void guardarJson::guardarJsonUsers(QJsonObject archivo) {
    std::ofstream file(dirUsers, std::ios::binary | std::ofstream::app);
    file << "\n" + archivo.value("usuario").toString().toStdString() + "\n";
    file << archivo.value("nombre").toString().toStdString() + "\n";
    file << archivo.value("apellido").toString().toStdString() + "\n";
    file << archivo.value("edad").toString().toStdString() + "\n";
    file << "[\n";
    auto qJsonArray = archivo.value("favoritos").toArray();
    for (auto &&i : qJsonArray) {
        file << i.toString().toStdString() + "\n";
    }
    file << "]\n";
    file << archivo.value("pass").toString().toStdString() + "\n";
    qJsonArray = archivo.value("amigos").toArray();
    file << "[\n";
    for (auto &&i : qJsonArray) {
        file << i.toString().toStdString() + "\n";
    }
    file << "]";
    file.close();
}

void guardarJson::guardarJsonMetadata(QJsonObject archivo) {
    std::ofstream file(dirMetadata, std::ios::binary | std::ofstream::app);
    file << archivo.value("titulo").toString().toStdString() + "\n";
    file << archivo.value("artista").toString().toStdString() + "\n";
    file << archivo.value("album").toString().toStdString() + "\n";
    file << archivo.value("genero").toString().toStdString() + "\n";
    file << archivo.value("numeroPista").toString().toStdString() + "\n";
    file << archivo.value("numeroDisco").toString().toStdString() + "\n";
    file << archivo.value("anno").toString().toStdString() + "\n";
    file.close();
}
