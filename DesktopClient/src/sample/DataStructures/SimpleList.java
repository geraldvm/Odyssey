package sample.DataStructures;

/**
 * Clase SimpleList
 * Es una lista enlazada simple de datos genéricos
 * @author Gerald Valverde Mc kenzie
 * @version 7.0
 * @param <T> : dato de tipo Generics
 */
public class SimpleList<T> {
    /**
     * Atributos
     * Node first: Referencia al primer nodo de la lista
     * Node last: Referencia al último nodo de la lista
     * int size: tamaño de la lista
     */
    private Node<T> first;
    private Node<T> last;
    private int size=0;

    /**
     * Constructor
     * Iniciliza los atributos
     */
    public SimpleList(){
        this.first=null;
        this.last=null;
        this.size=0;
    }

    /**
     * Método length
     * @return tamaño de la lista
     */
    public int length() {
        return this.size;
    }
    /**
     * Metodo booleano
     * @return si la lista esta vacia
     */
    public boolean isEmpty(){
        return this.first==null;
    }
    /**
     * Metodo encargado de agregar al final de la lista un dato
     * @param item dato a insertar de tipo T
     */
    public void addLast(T item){
        this.addLast_aux(item);
    }
    /**
     * Metodo encargado de buscar un nodo por su valor
     * @param value valor a buscar
     */
    public void search(T value)
    {
        this.search(value, this.first);
    }
    /**
     * Metodo encargar de borrar un dato al ingresar el valor
     * @param item valor que se desea eliminar
     */
    public void delete(T item){
        this.delete_aux(item);
    }
    /**
     * Metodo encargado de actualizar datos
     * @param oldValue valor viejo a cambiar
     * @param newValue nuevo valor
     */
    public void update(T oldValue, T newValue){
        this.update_aux(oldValue,newValue);
    }
    /**
     * Metodo encargado de buscar un nodo segun su posicion
     * @param pos : < this.length
     * @return nodo en la pos
     */
    public Node<T> find(int pos)
    {
        return find_aux(pos);
    }
    /**
     * Metodo encargado de agregar al inicio de la lista
     * @param item valor a insertar
     */
    public void addFirst(T item){
        this.addFirst_aux(item);
    }
    /**
     * Busca un nodo por indice
     * @param pos < this.length
     * @return item del nodo
     */
    public T findItem(int pos)
    {
        return this.findI_aux(pos);
    }



    //Metodos privados
    private void addLast_aux(T item)
    {
        Node<T> newLast = new Node<>();
        newLast.setItem(item);
        if (this.isEmpty())
        {
            this.last = newLast;
            this.first = newLast;
            ++this.size;
        }
        else
        {
            this.last.setNext(newLast);
            this.last = newLast;
            ++this.size;

        }
    }

    private void delete_aux(T item)
    {
        Node<T> temp;
        temp=this.first;
        if (temp.getItem()==item)
        {
            this.first=temp.getNext();
        }

        else
        {
            while (temp.getNext()!=null)
            {
                if (temp.getNext().getItem()==item)
                {
                    if(temp.getNext()==last)
                    {
                        temp.setNext(null);
                        last=temp;
                    }
                    else
                    {
                        temp.setNext(temp.getNext().getNext());
                    }

                }
                else if (temp.getNext()!=null)
                {
                    temp=temp.getNext();
                }
            }

        }

    }

    private void update_aux(T item, T newValue)
    {
        Node<T> temp = first;
        if (last.getItem()==item)
        {
            last.setItem(newValue);
        }
        while (temp.getNext()!=null)
        {
            if (temp.getItem()==item)
            {
                temp.setItem(newValue);
            }
            temp=temp.getNext();
        }

    }

    private void search(T value, Node<T> temp)
    {

        if(temp.getItem()==value)
        {

            this.search(temp.getItem()==value);
        }
        else if (temp.getNext()==null)
        {
            this.search(temp.getItem()==value);
        }
        else
        {
            this.search(value, temp.getNext());
        }
    }

    private boolean search(boolean x)
    {
        System.out.println(x);
        return x;
    }

    private Node<T> find_aux(int pos)
    {
        Node<T> temp = this.first;
        if(this.isEmpty())
        {
            return null;
        }
        else {
            if (pos <= this.length())
            {
                for (int i=0; i<pos; i++)
                {
                    temp= temp.getNext();
                }
                return temp;

            }
            return null;
        }
    }

    private T findI_aux(int pos)
    {
        Node<T> temp = this.first;
        if(this.isEmpty())
        {
            return null;
        }
        else {
            if (pos <= this.length())
            {
                for (int i=0; i<pos; i++)
                {
                    temp= temp.getNext();
                }
                return temp.getItem();

            }
            return null;
        }
    }

    private void addFirst_aux(T item){
        Node<T> newFirst = new Node<>();
        newFirst.setItem(item);
        //newFirst.setNext(null);

        if(this.isEmpty()){
            this.first=newFirst;
            this.last=newFirst;
            ++this.size;
        }
        else {
            newFirst.setNext(this.first);
            this.first=newFirst;
            ++this.size;
        }

    }

}