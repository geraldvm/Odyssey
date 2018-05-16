public class Node {
    private Object item;
    private Node next;



    public void setItem(Object item) {
        this.item = item;
    }

    public Object getItem() {
        return item;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public Node getNext() {
        return next;
    }
}