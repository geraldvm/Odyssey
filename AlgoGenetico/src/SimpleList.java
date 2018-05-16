public class SimpleList
{
    private Node first;
    private Node last;
    public int size = -1;

    public void addFirst(Object item) {
        Node newFirst = new Node();
        newFirst.setItem(item);
        if (first == null)
        {
            first = newFirst;
        }
        else
        {
            newFirst.setNext(first);
            first = newFirst;
        }
    }

    public Object show(int i)
    {
        Node temp = first;
        int indice = 0;
        while (indice != i)
        {
            temp = temp.getNext();
            indice++;
        }
        return temp.getItem();
    }

    public void addLast(Object item)
    {
        size ++;
        Node newLast = new Node();
        newLast.setItem(item);

        if (first==null)
        {
            last = newLast;
            first = newLast;
        }

        else if (last==null)
        {
            last = newLast;
        }
        else
        {
            last.setNext(newLast);
            last = newLast;

        }
    }

    public void erase(Object item)
    {
        Node temp;
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

    public void update(Object item, Object newValue)
    {
        Node temp = first;
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

    public boolean search(Object value)
    {
        return search(value, this.first);

    }

    private boolean search(Object value, Node temp)
    {
       try {
           if(temp.getItem()==value)
           {
               return true;
           }
           else if (temp.getNext()==null)
           {
               return false;
           }
           else
           {
               search(value, temp.getNext());
           }
           return false;
       } catch (NullPointerException e) {
           return false;
       }

    }
}