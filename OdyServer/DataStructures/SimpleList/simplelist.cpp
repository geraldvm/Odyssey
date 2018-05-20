#include "simplelist.h"
#include <string>

// Constructor por defecto
template<typename T>
SimpleList<T>::SimpleList()
{
    size = 0;
    head = NULL;
}

template<typename T>
void SimpleList<T>::addFirst(T data) {
    Node<T> *newNode = new Node<T> (data);
    if (isEmpty()) {
        head = newNode;
    } else {
        newNode->setNext(head);
        head = newNode;
    }
    size++;
}

template<typename T>
int SimpleList<T>::getLength()
{
    return this->size;
}

template<typename T>
void SimpleList<T>::print() {
    Node<T> *temp = head;
    if (!head) {
        printf( "La Lista está vacía " );
    } else {
        while (temp) {
            std::cout<<temp->getData()<<"-->";
            if (!temp->getNext()){
                printf("NULL");
            }
            temp = temp->getNext();
        }
    }
}
template<typename T>
QString SimpleList<T>::getString() {
    QString result;
    Node<T> *temp = head;
    if (isEmpty()) {
        std::cout<<"La Lista está vacía "<<std::endl;
    } else {
        while (temp) {
            //result+=std::to_string(temp->getData());
            int i=0;
            while (i<=7) {
                result+=QString::number(temp->getData());
                result+="-->";
                //std::cout<<temp->getData()<<"-->";
                if (!temp->getNext()){
                    result+="NULL";
                    //printf(result);
                    //std::cout<<result;
                    return result;
                }
                temp = temp->getNext();
                i++;
            }result+="\n";
            i=0;
        }
    }
}



template<typename T>
SimpleList<T>::~SimpleList() {
    delete head;
}

template<typename T>
void SimpleList<T>::addLast(T data) {
    Node<T> *new_node = new Node<T> (data);
    Node<T> *temp = head;

    if (isEmpty()) {
        addFirst(data);
    } else {
        while (temp->getNext() != NULL) {
            temp = temp->getNext();
        }
        temp->setNext(new_node);
    }
    size++;
}

template<typename T>
void SimpleList<T>::addPos(T data, int pos) {
    Node<T>* temp = head;
    Node<T>* newNode = new Node<T> (data);
    //Revisar caso que la lista este vacia o si es la primera posicion
    if(isEmpty()&&pos==0){
        addFirst(data);
    } else if(pos==0){
        addFirst(data);
    }
    else if (pos > size) {
        printf( "Fuera de rango ");
    }
    else {
        for (int i = 0; i <= pos; i++) {
            if (i==pos-1) {
                newNode->setNext(temp->getNext());
                temp->setNext(newNode);

                size++;
            }
            temp=temp->getNext();
        }
    }

}

template<typename T>
bool SimpleList<T>::isEmpty() {
    if(size==0){
        return true;
    } else{
        return false;
    }

}

template<typename T>
void SimpleList<T>::deleteFirst() {

    if(!isEmpty()){
        head = head->getNext();
    }size--;

}

template<typename T>
void SimpleList<T>::deleteLast() {
    if(size==1){
        deleteFirst();
    }
    else if(!isEmpty()) {
        Node<T> *temp = head;
        int i = 1;
//    cout<<size<<endl;
        while (i < size - 1) {
            temp = temp->getNext();
            i++;
        }
        temp->setNext(NULL);
        size--;
    }

}

template<typename T>
void SimpleList<T>::deletePos(int pos) {
    Node<T> *temp = head;
    if (pos > size-1) {
        std::cout << "Fuera de rango " << std::endl;
    } else if (pos == 0) {
        head = temp->getNext();
        size--;
    } else {
        for (int i = 1; i <= pos; i++) {
            if (i == pos) {
                temp->setNext(temp->getNext()->getNext());
                size--;
            }
            temp = temp->getNext();
        }
    }
}

template<typename T>
void SimpleList<T>::editPos(T data,int pos) {
    Node<T> *temp = head;
    if (pos > size-1) {
        std::cout << "Fuera de rango " << std::endl;
    } else {
        for (int i = 0; i <= pos; i++) {
            if (i == pos) {
                temp->setData(data);
            }
            temp = temp->getNext();
        }
    }
}

template<typename T>
T SimpleList<T>::findPos(int pos) {
    Node<T> *temp = head;
    if (pos > size-1) {
        std::cout << "Fuera de rango " << std::endl;
        return -1;
    } else {
        for (int i = 0; i <= pos; i++) {
            if (i == pos) {
                return temp->getData();
            }
            temp = temp->getNext();
        }
    }
}

template<typename T>
T SimpleList<T>::get(int i) {
    return findPos(i);
}

template<typename T>
QString SimpleList<T>::getPos(int pos)
{
    return  QString::fromStdString(findPos(pos));

}
