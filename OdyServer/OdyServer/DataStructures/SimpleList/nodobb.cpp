#include "nodobb.h"

NodoBB::NodoBB()
{
    this->left = nullptr;
    this->right = nullptr;
}

NodoBB::NodoBB(QJsonObject data)
{
    this->data = data;
    this->right = nullptr;
    this->left = nullptr;
}

void NodoBB::setData(QJsonObject data) {
    this->data=data;
}

void NodoBB::setRight(NodoBB* next) {
    this->right=next;
}

void NodoBB::setLeft(NodoBB* left) {
    this->left=left;
}

QJsonObject NodoBB::getData() {
    return this->data;
}

NodoBB *NodoBB::getLeft() {
    return this->left;
}

NodoBB *NodoBB::getRight() {
    return this->right;
}
