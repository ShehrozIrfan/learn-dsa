//Doubly Linked List in Java
 
class Node {

    int data;
    Node prev;
    Node next;

    Node(int value) 
    {
        prev = null; 
        data = value; 
        next = null; 
    }
}
 
class DoublyLinkedList 
{
    //creating empty doubly linked list
    static Node head = null; 

    //inserting element at the head
    static void insert_at_head(int value)
    {
        Node n = new Node(value);
        n.next = head;
 
        if (head != null) 
        {
            head.prev = n;
        }
        head = n;
    }
 
    //inserting element at the tail
    static void insert_at_tail(int value)
    {
        if (head == null) 
        {
            insert_at_head(value);
            return;
        }
        Node n = new Node(value);
        Node temp = head;
        while (temp.next != null) 
        {
            temp = temp.next;
        }
        temp.next = n;
        n.prev = temp;
    }
 
    //displaying the doubly linked list
    static void display(Node head)
    {
        Node temp = head;
        while (temp != null) 
        {
            System.out.print(temp.data + " --> ");
            temp = temp.next;
        }
        System.out.println("NULL");
    }
    
    public static void main(String[] args)
    {
        insert_at_tail(1);
        insert_at_tail(2);
        insert_at_tail(3);
        insert_at_tail(4);
        insert_at_tail(5);
        System.out.print("After insertion at tail: ");
        display(head);
        System.out.print("After insertion at head: ");
        insert_at_head(0);
        display(head);
    }
}