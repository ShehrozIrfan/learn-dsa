//Reversing a singly linked list.
/*
A singly linked list can be reversed by using two methods:
1.Iterative Method
2.Recursive Method
*/
/*
********************************************************************
*                                                                  *
*                                                                  *
*         Important and Favorite Interview Question                *
*                                                                  *  
*                                                                  *
********************************************************************
*/
//We will reverse it by using Iterative Method

#include<iostream>
using namespace std;

class Node {
public:
	int info;
	Node *next;

	//Constructor
	Node(int i, Node *p = 0) {
		info = i;
		next = p;
	}
};

class SLinkedList {
private:
	Node *head, *tail;
public:
	//Constructor
	SLinkedList() {
		head = tail = 0;
	}

	//add to tail
	void addToTail(int i) {
		if (tail == 0) {
			head = tail = new Node(i);
		}
		else {
			tail->next = new Node(i);
			tail = tail->next;
		}
	}

	//Add to head

	void addToHead(int i) {
		if (head == 0) {
			head = tail = new Node(i);
		}
		else {
			Node *temp;
			temp = new Node(i);
			temp->next = head;
			head = temp;
		}
	}

	//Reversing a singly linked list

	void reverseList() {
		//No Node
		if (head == 0) {
			cout << "Empty list" << endl;
			cout << "No node to reverse" << endl;
		}
		//One Node or more than one Node
		else {
			Node *current;
			Node *prev;
			Node *next; //local pointer don't confuse it with next pointer that is declared as public in Node class.

			current = head;
			prev = NULL;
			next = NULL;

			//traverse the list
			while (current != NULL) {
				//store next
				next = current->next;

				//Reverse current's node pointer
				current->next = prev;

				//move pointers one position ahead
				prev = current;
				current = next;
			}

			head = prev;
		}
	}

	//display list

	void print() {
		Node *temp;
		temp = head;
		while (temp!= NULL) {
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl << endl;
	}

};

int main() {

	SLinkedList list;

	//when there is no node

	cout << "When there is no node in List:" << endl;
	list.reverseList();
	list.print();

	//when there is only one node

	cout << "When there is only one node in List:" << endl;
	list.addToHead(5);
	cout << "List in Actual Order:" << endl;
	list.print();
	cout << "List in Reverse Order:" << endl;
	list.reverseList();
	list.print();

	//when there are more than one nodes in list.

	cout << "When there are more than one nodes in List:" << endl;
	list.addToTail(10);
	list.addToTail(15);
	list.addToTail(20);
	list.addToTail(25);
	list.addToHead(10);
	list.addToHead(20);
	list.addToHead(30);
	list.addToTail(40);
	cout << "\n\n"<<"List in Actual Order:" << endl;
	list.print();
	cout << "\n\n" << "List in Reverse Order:" << endl;
	list.reverseList();
	list.print();
	system("pause");
	return 0;
}
