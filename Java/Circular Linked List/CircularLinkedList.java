class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class CircularLinkedList {
    private Node head;
    private Node tail;

    public CircularLinkedList() {
        head = null;
        tail = null;
    }

    public void addToEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            tail = newNode;
            newNode.next = head; // Point the tail back to the head to form a loop
        } else {
            tail.next = newNode;
            tail = newNode;
            newNode.next = head; // Update the new tail to point back to the head
        }
    }

    public void display() {
        if (head == null) {
            System.out.println("Circular Linked List is empty.");
            return;
        }

        Node current = head;
        do {
            System.out.print(current.data + " ");
            current = current.next;
        } while (current != head);
        System.out.println();
    }

    public static void main(String[] args) {
        CircularLinkedList cll = new CircularLinkedList();

        cll.addToEnd(1);
        cll.addToEnd(2);
        cll.addToEnd(3);
        cll.addToEnd(4);

        System.out.println("Circular Linked List:");
        cll.display();
    }
}

//The Node class represents a node in the circular linked list. 
// It contains an integer data field and a reference to the next node.

// The CircularLinkedList class manages the circular linked list. 
// It provides methods to add elements to the end of the list and to display the list.

// The addToEnd method adds a new node to the end of the circular linked list. 
// If the list is empty, it creates the first node and sets both the head and tail to it. 
// For subsequent additions, it updates the tail and the new node's next reference to maintain the circular structure.

// The display method traverses and prints the circular linked list starting from the head,
// looping until it reaches the head again.

// The main method demonstrates how to create a circular linked list, add elements, and display the list.