#include "mysqldb.h"

MySQLDB::MySQLDB() {

    base = QSqlDatabase::addDatabase("QMYSQL");
    base.setHostName("localhost");
    base.setDatabaseName(nombreBase);
    base.setUserName("root");
    base.setPassword("odyserver");
    if (base.open()) {
        std::cout << "Base de datos abierta"<<std::endl;
    } else std::cout << "Error al abrir base de datos" << std::endl;

}

bool MySQLDB::agregarCancion(QJsonObject info){
    bool flag;
    QSqlQuery query;
    query.prepare("INSERT INTO metadata(titulo,artista,album,genero,pista,disco,anno,calificacion,letra)"
                  "VALUES (:title,:artist,:album,:genre,:pista,:disco,:anno,:score,:lyrics)");
    query.bindValue(":title",info.value("titulo").toString());
    query.bindValue(":artist",info.value("artista").toString());
    query.bindValue(":album",info.value("album").toString());
    query.bindValue(":genre",info.value("genero").toString());
    query.bindValue(":pista",info.value("numeroPista").toString());
    query.bindValue(":disco",info.value("numeroDisco").toString());
    query.bindValue(":anno",info.value("anno").toString());
    query.bindValue(":score",info.value("calificacion").toString());
    query.bindValue(":lyrics",info.value("letra").toString());
    flag = query.exec();
    return flag;

}

bool MySQLDB::eliminarCancion(QString nombre){
    bool flag;
    QSqlQuery query;
    flag = query.exec("DELETE FROM metadata WHERE titulo = '"+nombre+"'");
    return flag;
}

bool MySQLDB::modificarInfoCancion(QString nombre, QJsonObject info){
    bool flag;
    QSqlQuery query;
    query.prepare("UPDATE metadata SET titulo=:title,artista=:artist,album=:album,genero=:genre,pista=:pista"
                  ",disco=:disco,anno=:anno,calificacion=:score,letra=:lyrics WHERE titulo='"+nombre+"'");
    query.bindValue(":title",info.value("titulo").toString());
    query.bindValue(":artist",info.value("artista").toString());
    query.bindValue(":album",info.value("album").toString());
    query.bindValue(":genre",info.value("genero").toString());
    query.bindValue(":pista",info.value("numeroPista").toString());
    query.bindValue(":disco",info.value("numeroDisco").toString());
    query.bindValue(":anno",info.value("anno").toString());
    query.bindValue(":score",info.value("calificacion").toString());
    query.bindValue(":lyrics",info.value("letra").toString());
    flag = query.exec();
    return flag;
}

QJsonObject MySQLDB::getInfoCancion(QString nombre){
    QJsonObject metadata = QJsonObject();
    QSqlQuery query;
    query.prepare("SELECT * FROM metadata WHERE titulo=:title");
    query.bindValue(":title",nombre);
    query.exec();
    query.next();
    metadata.insert("titulo",query.value(0).toString());
    metadata.insert("artista",query.value(1).toString());
    metadata.insert("album",query.value(2).toString());
    metadata.insert("genero",query.value(3).toString());
    metadata.insert("numeroPista",query.value(4).toInt());
    metadata.insert("numeroDisco",query.value(5).toInt());
    metadata.insert("anno",query.value(6).toInt());
    metadata.insert("calificacion",query.value(7).toInt());
    metadata.insert("letra",query.value(8).toString());

    return metadata;
}

ListaSimple<QString> MySQLDB::obtenerCanciones(){
    ListaSimple<QString> res = ListaSimple<QString>();
    QSqlQuery query;
    query.prepare("SELECT titulo FROM metadata");
    query.exec();
    while(query.next()){
        res.push_back(query.value(0).toString());
    }
    return res;
}

QString MySQLDB::obtenerLetra(QString nombre){
    QSqlQuery query;
    query.prepare("SELECT letra FROM metadata WHERE titulo=:title");
    query.bindValue(":title",nombre);
    query.exec();
    query.next();
    return query.value(0).toString();
}
