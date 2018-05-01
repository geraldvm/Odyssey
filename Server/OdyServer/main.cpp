#include <QCoreApplication>
//#include "myserver.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug("HEllo World");
    //MyServer mServer;
   // qDebug()<<"HEllo World"<<endl;

    return a.exec();
}
