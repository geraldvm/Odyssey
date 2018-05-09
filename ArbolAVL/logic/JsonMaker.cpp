//
// Created by andres on 05/05/18.
//

#include <utility>
#include "../headers/JsonMaker.h"

JsonMaker::JsonMaker(string titulo, string artista, string album, string genero, int numeroPista, int numeroDisco, int anno) {
    QJsonObject aux;
    aux.insert("titulo", QString::fromStdString(titulo));
    aux.insert("artista", QString::fromStdString(artista));
    aux.insert("album", QString::fromStdString(album));
    aux.insert("genero", QString::fromStdString(genero));
    aux.insert("numeroPista", QString::fromStdString(to_string(numeroPista)));
    aux.insert("numeroDisco", QString::fromStdString(to_string(numeroDisco)));
    aux.insert("anno", QString::fromStdString(to_string(anno)));
    jsonObject = aux;

}

JsonMaker::JsonMaker(string user, string nombre, string apellido, int edad, QJsonArray favoritos, int pass, QJsonArray amigosUsers) {
    QJsonObject aux;
    aux.insert("usuario", QString::fromStdString(user));
    aux.insert("nombre", QString::fromStdString(nombre));
    aux.insert("apellido", QString::fromStdString(apellido));
    aux.insert("edad", QString::fromStdString(to_string(edad)));
    aux.insert("favoritos", favoritos);
    aux.insert("pass", QString::fromStdString(to_string(pass)));
    aux.insert("amigos", amigosUsers);
    jsonObject = aux;
}

QJsonObject JsonMaker::getJson() {
    return jsonObject;
}

bool JsonMaker::modificarMetadata(string titulo, vector<vector<string>> cambios) {
    bool cambioEfectuado = false;
    QJsonObject obj;
    //buscar objeto por nombre en estructura donde se guarda
    for (int i = 0; i < cambios[0].size(); i++) {
        if (cambios[0][i] == "anno" || cambios[0][i] == "numeroDisco" || cambios[0][i] == "numeroPista") {
            obj.insert(QString::fromStdString(cambios[0][i]),stoi(cambios[1][i]));
        } else {
            obj.insert(QString::fromStdString(cambios[0][i]),QString::fromStdString(cambios[1][i]));
        }
    }
    return cambioEfectuado;
}


