#include "jsonmaker.h"
#include "DataStructures/SimpleList/simplelist.h"
#include <vector>

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

QJsonObject JsonMaker::getJson() {
    return jsonObject;
}

bool JsonMaker::modificarMetadata(string titulo, vector<string> cambios, vector<string> valor) {
    bool cambioEfectuado = false;
    QJsonObject obj;
    for (int i = 0; i < valor.size(); i++) {
        if (cambios[i] == "anno" || cambios[i] == "numeroDisco" || cambios[i] == "numeroPista") {
            obj.insert(QString::fromStdString(cambios[i]),stoi(valor[i]));
        } else {
            obj.insert(QString::fromStdString(cambios[i]),QString::fromStdString(valor[i]));
        }
    }
    return cambioEfectuado;
}
