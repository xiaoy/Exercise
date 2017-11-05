import java.util.*;
import edu.princeton.cs.algs4.StdOut;

public class Deque<Item> implements Iterable<Item> {
    class Node {
        public Item item;
        public Node next;
    }

    private Node m_firstNode = null;
    private Node m_lasNode = null;
    private int m_size = 0;

    class DequeIterator implements Iterator<Item>
    {
        private Node m_curNode = m_firstNode;
        public boolean hasNext(){
            return m_curNode != null;
        }

        public Item next(){
            Item curItem = m_curNode.item;
            m_curNode = m_curNode.next;
            return curItem;
        }
    }

    public Deque(){

    }

    public boolean isEmpty(){
        return m_size == 0;
    }

    public int size(){
        return m_size;
    }

    private void checkAddArgumentException(Item item){
        if(item == null){
            throw new IllegalArgumentException();
        }
    }

    public void addFirst(Item item){
        checkAddArgumentException(item);
        if(m_firstNode == null){
            m_firstNode = new Node();
            m_firstNode.item = item;
            m_lasNode = m_firstNode;
        }
        else{
            Node newFirstNode = new Node();
            newFirstNode.item = item;
            newFirstNode.next = m_firstNode;
            m_firstNode = newFirstNode;
        }
        m_size += 1;
    }

    public void addLast(Item item){
        checkAddArgumentException(item);
        if(m_lasNode == null){
            m_lasNode = new Node();
            m_lasNode.item = item;
            m_firstNode = m_lasNode;
        }
        else{
            Node newLastNode = new Node();
            newLastNode.item = item;
            m_lasNode.next = newLastNode;
            m_lasNode = newLastNode;
        }
        m_size += 1;
    }

    private void checkLinkNodeException(){
        if(m_size == 0){
            throw new NoSuchElementException();
        }
    }
    public Item removeFirst(){
        checkLinkNodeException();
        Item removeItem = m_firstNode.item;
        m_size -= 1;
        if(m_size == 0){
            m_firstNode = null;
            m_lasNode = null;
        }
        else{
            m_firstNode = m_firstNode.next;
        }

        return removeItem;
    }

    public Item removeLast(){
        checkLinkNodeException();
        Item remvoItem = m_lasNode.item;
        Node lastPreNode = m_firstNode;
        m_size -= 1;
        if(m_size == 0){
            m_firstNode = null;
            m_lasNode = null;
        }
        else{
            while(lastPreNode.next.next != null){
                lastPreNode = lastPreNode.next; 
            }
            lastPreNode.next = null;
        }
        return remvoItem;
    }

    public Iterator<Item> iterator(){
        return new DequeIterator();
    }

    public static void main(String[] args) {
        Deque<String> d = new Deque<>();
        d.addFirst("h");
        d.addFirst("e");
        d.addFirst("l");
        d.addLast("a");
        d.addLast("b");
        d.addLast("c");
        for (String ch : d) {
            StdOut.print(ch);
        }
        StdOut.println(d.size());

        d.removeFirst();
        for (String ch : d) {
            StdOut.print(ch);
        }
        StdOut.println(d.size());

        d.removeLast();
        for (String ch : d) {
            StdOut.print(ch);
        }
        StdOut.println(d.size());
    }
}