//singly linked list in java

public class SinglyLinkedList {
    private Node head; // head of the list
 
    // Node inner class to define nodes in the list
    private class Node {
        int data;
        Node next;
 
        // Constructor to create a new node
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
 
    // Method to insert a new node at the beginning of the list
    public void push(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }
 
    // Method to delete the first node in the list
    public void deleteFirst() {
        if (head == null) {
            return;
        }
        head = head.next;
    }
 
    // Method to print the contents of the list
    public void printList() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
 
    public static void main(String[] args) {
        SinglyLinkedList list = new SinglyLinkedList();
 
        // Insert some nodes at the beginning of the list
        list.push(5);
        list.push(10);
        list.push(15);
 
        // Print the contents of the list
        System.out.println("Original list: ");
        list.printList();
 
        // Delete the first node in the list
        list.deleteFirst();
 
        // Print the contents of the list again
        System.out.println("List after deleting first node: ");
        list.printList();
    }
}