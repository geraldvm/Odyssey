#ifndef NODOBB_H
#define NODOBB_H

#include <QtCore/QJsonObject>

class NodoBB
{
public:
    NodoBB();
    NodoBB(QJsonObject data);
    ~NodoBB();
    void setData(QJsonObject data);
    void setRight(NodoBB* next);
    void setLeft(NodoBB* left);
    QJsonObject getData();
    NodoBB* getLeft();
    NodoBB* getRight();

private:
    NodoBB* left;
    NodoBB* right;
    QJsonObject data;
};

#endif // NODOBB_H
