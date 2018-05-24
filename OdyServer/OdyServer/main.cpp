#include "mainwindow.h"
#include <QApplication>
#include "DataStructures/SimpleList/simplelist.h"
#include "Server/server.h"
#include "Document/jsonmaker.h"
#include "Document/guardarjson.h"
#include "Document/leerjson.h"
#include "DataStructures/SimpleList/hashmap.h"
#include "DataStructures/SimpleList/arbolbb.cpp"
#include <QtSql>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase base = QSqlDatabase::addDatabase("QMYSQL");
    base.setHostName("localhost");
    base.setDatabaseName("metadata");
    base.setUserName("root");
    base.setPassword("ServerOdy2.0");

    if (base.open()) {
        std::cout << "Base de datos abierta"<<std::endl;
    } else std::cout << "Error al abrir base de datos" << std::endl;


    //MainWindow w;
    //w.show();string user, string nombre, string apellido, int edad, QJsonArray favoritos, int pass, QJsonArray amigosUsers
    /*
    arbolBB<QJsonObject> u = arbolBB<QJsonObject>();
    QJsonArray o = QJsonArray();
    o.append("ap");
    JsonMaker m = JsonMaker("user1","nombre","ap",12,o,123,o);
    u.insert(m.getJson());
    ListaSimple<QJsonObject> l = u.preorder();
    std::cout << l.get(0).value("usuario").toString().toStdString();
*/
    Server mserver;

    return a.exec();
}
