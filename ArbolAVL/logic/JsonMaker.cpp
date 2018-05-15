//
// Created by andres on 05/05/18.
//

#include <utility>
#include "../headers/JsonMaker.h"

JsonMaker::JsonMaker(string titulo, string artista, string album, string genero, int numeroPista, int numeroDisco, int anno, int calificacion, string letra) {
    QJsonObject aux;
    aux.insert("titulo", QString::fromStdString(titulo));
    aux.insert("artista", QString::fromStdString(artista));
    aux.insert("album", QString::fromStdString(album));
    aux.insert("genero", QString::fromStdString(genero));
    aux.insert("numeroPista", QString::fromStdString(to_string(numeroPista)));
    aux.insert("numeroDisco", QString::fromStdString(to_string(numeroDisco)));
    aux.insert("anno", QString::fromStdString(to_string(anno)));
    aux.insert("calificacion",QString::fromStdString(to_string(calificacion)));
    aux.insert("letra",QString::fromStdString(letra));
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

bool JsonMaker::modificarMetadata(string titulo, ListaSimple<ListaSimple<string>> cambios) {
    bool cambioEfectuado = false;
    QJsonObject obj;
    //buscar objeto por nombre en estructura donde se guarda
    for (int i = 0; i < cambios.get(0).size; i++) {
        if (cambios.get(0).get(i) == "anno" || cambios.get(0).get(i) == "numeroDisco" || cambios.get(0).get(i) == "numeroPista") {
            obj.insert(QString::fromStdString(cambios.get(0).get(i)),stoi(cambios.get(1).get(i)));
        } else {
            obj.insert(QString::fromStdString(cambios.get(0).get(i)),QString::fromStdString(cambios.get(1).get(i)));
        }
    }
    return cambioEfectuado;
}


