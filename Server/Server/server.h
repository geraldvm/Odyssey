#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QObject>
#include <iostream>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();

signals:

public slots:
    void readyRead();

private:
    QUdpSocket *socket;
    QHostAddress clientAddress;
    qint16 clientPort;
};

#endif // SERVER_H
