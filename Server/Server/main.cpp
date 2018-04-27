#include "server.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server* mserver =new Server(0);
    //Server w;
    //w.show();

    return a.exec();
}
