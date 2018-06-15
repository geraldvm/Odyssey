#include "mainwindow.h"
#include <QApplication>
#include "Server/server.h"
#include "Document/converter.h"
#include "raidcontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
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
