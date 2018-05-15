package sample.DataStructures;
/**
 * Clase Node
 * Unidad básica de las listas
 * @author Gerald Valverde Mc kenzie
 * @version 7.0
 * @param <T>
 */
public class Node<T> {
    protected T item;
    protected Node<T> next;//private

    /**
     * Constructor
     * Se inicializa los atributos en null
     */

    public Node(){
        this.next= null;
        this.item=null;
    }

    /**
     * Constructor
     * se inicializa el valor del nodo
     * @param item
     */
    public Node(T item){
        this.item=item;
        this.next=null;
    }

    /**
     * Setter
     * Cambia el valor del item
     * @param item
     */
    public void setItem(T item) {
        this.item = item;
    }

    /**
     * Getter
     * Devuelve el valor del item
     * @return item
     */
    public T getItem() {
        return this.item;
    }

    /**
     * Setter
     * Asigna el valor del la referencia al siguiente nodo
     * @param next
     */
    public void setNext(Node<T> next) {
        this.next = next;
    }

    /**
     * Getter
     * Devuelve el valorde la referencia al siguiente nodo
     * @return next
     */
    public Node<T> getNext() {
        return this.next;
    }
}