#include "mainwindow.h"
#include <QApplication>
#include "Server/server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
    MySQLDB base = MySQLDB();
    JsonMaker j = JsonMaker("ltitle","lartist","lalbum","lgenre",1,2,2018,5,"llyrics");
    std::cout << base.getInfoCancion("ltitle").value("artista").toString().toStdString() <<std::endl;
*/
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
