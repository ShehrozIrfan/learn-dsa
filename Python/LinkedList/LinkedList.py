# Linked List implementation in Python. I have implemented the following functions:
# 1. deleteNode(key) - deletes the node with the given key
# 2. deleteNodeAtPosition(position) - deletes the node at the given position
# 3. printList() - prints the linked list


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__ (self):
        self.head = None

    def deleteNode(self, key):
        temp = self.head
        if(temp is not None):
            if(temp.data == key):
                self.head = temp.next
                temp = None
                return

        while(temp is not None):
            if(temp.data == key):
                break
            prev = temp
            temp = temp.next

        if(temp == None):
            return

        prev.next = temp.next
        temp = None

    def deleteNodeAtPosition(self, position):
        temp = self.head
        if(temp == None):
            return

        if(position == 0):
            self.head = temp.next
            temp = None
            return

        for i in range(position-1):
            temp = temp.next
            if(temp == None):
                break

        if(temp == None):
            return
        if(temp.next == None):
            return

        next = temp.next.next
        temp.next = None
        temp.next = next


    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next

if __name__ == '__main__':
    llist = LinkedList()
    llist.head = Node(10)
    second = Node(20)
    third = Node(30)
    fourth = Node(40)
    fifth = Node(50)
    sixth = Node(60)

    llist.head.next = second
    second.next = third
    print("Original List")
    llist.printList()
    print("List after deleting node with key 20")
    llist.deleteNode(20)

    llist.printList()
    print("List after deleting node at position 1")
    llist.deleteNodeAtPosition(1)

    llist.printList()

