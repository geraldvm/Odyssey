#include "arbolbb.h"

template<class T>
void arbolBB<T>::insert(T data) {
    size++;
    if(root == nullptr){
        this->root = new NodoBB(data);
    }else{
        this->insertAux(root,data);
    }
}

template<class T>
void arbolBB<T>::insertAux(NodoBB *node, T data) {
    if(((QJsonObject)data).value("usuario").toString() < node->getData().value("usuario").toString()){
        if(node->getLeft() ==NULL){
            node->setLeft(new NodoBB(data));
        }
        else {
            insertAux(node->getLeft(), data);
        }
    }
    else if(((QJsonObject)data).value("usuario").toString() > node->getData().value("usuario").toString()){
        if (node->getRight()==NULL){
            node->setRight(new NodoBB(data));
        }else {
            insertAux(node->getRight(), data);
        }
    }
}

template<class T>
ListaSimple<QJsonObject> arbolBB<T>::preorder(){
    ListaSimple<QJsonObject> *usuarios = new ListaSimple<QJsonObject>();
    if(this->root!=nullptr){
        preorderAux(this->root,usuarios);
    }else{
        QJsonObject obj = QJsonObject();
        obj.insert("usuario","NOUSUARIOS");
        usuarios->push_back(obj);
    }
    return *usuarios;

}

template<typename T>
void arbolBB<T>::preorderAux(NodoBB* node, ListaSimple<QJsonObject> *usuarios){
    if(node != NULL){
    usuarios->push_back(node->getData());
    this->preorderAux(node->getLeft(),usuarios);
    this->preorderAux(node->getRight(),usuarios);
    }
}
template<class T>
NodoBB* arbolBB<T>::deleteNode(QJsonObject data){
    return this->deleteNode(this->root,data);
}

template<class T>
NodoBB* arbolBB<T>::deleteNode(NodoBB *root, T data){
    if (root == NULL){
        return root;
    }

    if (((QJsonObject)data).value("usuario").toString() < root->getData().value("usuario").toString()){
        root->setLeft(deleteNode(root->getLeft(), data));
    }
    else if (((QJsonObject)data).value("usuario").toString() > root->getData().value("usuario").toString()){
        root->setRight(deleteNode(root->getRight(), data));
    }
    else{
        if (root->getLeft()==NULL){
            NodoBB *temp = root->getRight();
            free(root);
            return temp;
        }
        else if (root->getRight() == NULL){
            NodoBB *temp = root->getLeft();
            free(root);
            return temp;
        }
        NodoBB* temp = minValueNode(root->getRight());
        root->setData(temp->getData());
        root->setRight(deleteNode(root->getRight(), temp->getData()));
    }
    return root;
}
template<class T>
NodoBB* arbolBB<T>::minValueNode(NodoBB* node){
    NodoBB* current = node;
    while (current->getLeft() != NULL){
        current = current->getLeft();
    }
    return current;
}

template<class T>
bool arbolBB<T>::search(QString userName) {
    NodoBB* aux = root;
    while(aux != nullptr) {
        if (userName == aux->getData().value("usuario").toString()) {return true;}
        if (userName < aux->getData().value("usuario").toString()) {
            aux = aux->getLeft();
        } else {
            aux->getRight();
        }
    }
    return false;
}
