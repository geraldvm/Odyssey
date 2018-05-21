#include "abb.h"
template<typename T>
ABB<T>::ABB()
{
    root=nullptr;
    size=0;

}
template<typename T>
void ABB<T>::insert(T data) {
    size++;
    if(root == nullptr){
        this->root = new Nodo<T>(data);
    }else{
        this->insert(root,data);
    }
}
template<typename T>
void ABB<T>::insert(Nodo<T>* node,T data) {
    if(data < node->getData()){
        if(node->getLeft()==NULL){
            node->setLeft(new Nodo<T>(data));
        }
        else {
            insert(node->getLeft(), data);
        }
    }
    else if(data > node->getData()){
        if (node->getRight()==NULL){
            node->setRight(new Nodo<T>(data));
        }else {
            insert(node->getRight(), data);
        }
    }
}
template<typename T>
void ABB<T>::preorder(){
    if(this->root!=nullptr){
        std::cout<< "--------***PREORDER***-------- \n";
        preorder(this->root);
    }else{
        std::cout<< "   Err: This tree it's empty"<<std::endl;
    }
}
template<typename T>
void ABB<T>::preorder(Nodo<T>* node){
    if(node != NULL){
    std::cout<<"               "<<node->getData()<<std::endl;
    this->preorder(node->getLeft());
    this->preorder(node->getRight());
    }
}
template<typename T>
void ABB<T>::inorder(){
    if(this->root!=nullptr){
        std::cout<< "---------***INORDER***--------- \n";
        inorder(this->root);
    }else {
        std::cout<< "   Err: This tree it's empty"<<std::endl;
    }
}
template<typename T>
void ABB<T>::inorder(Nodo<T>* node){
    if(node != NULL){
        this->inorder(node->getLeft());
        std::cout<<"               "<<node->getData()<<std::endl;
        this->inorder(node->getRight());
    }
}
template<typename T>
void ABB<T>::postorder(){
    if(this->root!=nullptr){
        std::cout<< "--------***POSTORDER***-------- \n";
        this->postorder(this->root);
    }else{
        std::cout<< "   Err: This tree it's empty"<<std::endl;
    }

}
template<typename T>
void ABB<T>::postorder(Nodo<T>* node){
    if(node == NULL){
        return;
    }
    this->postorder(node->getLeft());
    this->postorder(node->getRight());
    std::cout<<"               "<<node->getData()<<std::endl;
}
template<typename T>
T ABB<T>::findMin(){
    return this->findMin_aux();
}
T ABB<T>::findMin_aux(){
    Nodo<T>* temp=root;
    while (temp->getLeft()!=NULL) {
        temp = temp->getLeft();
    }
    return temp->getData();

}
template<typename T>
T ABB<T>::findMax(){
    return this->findMax_aux();
}
template<typename T>
T ABB<T>::findMax_aux(){
    Nodo<T>* temp=root;
    while (temp->getRight()!=NULL) {
        temp = temp->getRight();
    }
    return temp->getData();
}
template<typename T>
Nodo<T>* ABB<T>::minValueNode(Nodo<T>* node){
    Nodo<T>* current = node;

    while (current->getLeft() != NULL){
        current = current->getLeft();
    }
    return current;
}
template<typename T>
Nodo<T>* ABB<T>::deleteNode(T data){
    return this->deleteNode(this->root,data);
}
template<typename T>
QString ABB<T>::printMin()
{
    return this->printMin_aux();
}
template<typename T>
QString ABB<T>::printMax()
{
    return this->printMax_aux();
}
template<typename T>
QString ABB<T>::printMin_aux()
{
    Nodo<T>* temp=this->root;
    while (temp->getLeft()!=NULL) {
        temp = temp->getLeft();
    }
    QString result="Min Vaue: ";
    result+= QString::number(temp->getData());
    return result;
}
template<typename T>
QString ABB<T>::printMax_aux()
{
    Nodo<T>* temp=root;
    while (temp->getRight()!=NULL) {
        temp = temp->getRight();
    }
    QString result="Max Vaue: ";
    result+= QString::number(temp->getData());
    return result;
}
template<typename T>
Nodo<T>* ABB<T>::deleteNode(Nodo<T> *root, T data){
    // base case
    if (root == NULL){
        return root;
    }

    if (data < root->getData()){
        root->setLeft(deleteNode(root->getLeft(), data));
    }
    else if (data > root->getData()){
        root->setRight(deleteNode(root->getRight(), data));
    }
    else{
        if (root->getLeft()==NULL){
            Nodo<T> *temp = root->getRight();
            free(root);
            return temp;
        }
        else if (root->getRight() == NULL){
            Nodo<T> *temp = root->getLeft();
            free(root);
            return temp;
        }
        Nodo<T>* temp = minValueNode(root->getRight());
        root->setData(temp->getData());
        root->setRight(deleteNode(root->getRight(), temp->getData()));
    }
    return root;
}





