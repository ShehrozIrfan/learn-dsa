//Singly Linked List in Java

public class SinglyLinkedList {
    class Node 
    {
        int data;
        Node next;

        public Node(int data)
        {
            this.data = data;
            this.next = null;
        }
    }

    //head and tail of the singly linked list
    public Node head = null;
    public Node tail = null;

    public void addNode(int data)
    {
        //creating a new node in the list
        Node newNode = new Node(data);

        //checking if list is empty
        if (head == null)
        {
            //when list is empty both head and tail points to new node
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail.next = newNode;
            tail = newNode;
        }
    }

    //displaying the list
    void display()
    {
        //pointing to head
        Node current = head;
        if (head == null)
        {
            System.out.println("List is Empty");
            return;
        }
        while (current != null) 
        {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String args[])
    {
        SinglyLinkedList sll = new SinglyLinkedList();
        sll.addNode(1);
        sll.addNode(2);
        sll.addNode(3);
        sll.addNode(4);
        sll.addNode(5);
        System.out.println("Nodes of Singly Linked List: ");
        sll.display();
    }
}