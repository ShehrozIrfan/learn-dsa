/*
DSA Past Papar 2014,2013
Q#3: Write a function exchange (int a, int b) that exchanges two nodes in list, that is implemented using linked list. You have to add this function
exchange() as a member function of list class. The nodes are identified by number and are passed as parameters.
e.g; to exchange node 5 & 8 , you would call exchange ( 5, 8). if the exchange is successful the function should return true. if it encounters an 
error, such as invalid node number then it should return false.


                              ====== SOLUTION ======
							  
							  To solve this we have to handle 4 scanerios:

							  1- Both of the nodes may be adjacent
							  2- Either of the one node is at head
							  3- Either of the one node is at tail
							  4- Both the nodes are  between head & tail

To Understand watch the video on link:  https://www.youtube.com/watch?v=bSORX7TcFvs

*/

#include<iostream>
using namespace std;

class Node {
public:
	//This linked list will store character data.
	char data;
	Node *next;
	//Constructor
	Node(int d, Node *n = NULL) {
		data = d;
		next = n;
	}
};

class SLinkedList {
private:
	Node *head, *tail;
public:
	SLinkedList() {
		head = tail = NULL;
	}
	void addToHead(int i);
	void display();
	bool exchange(int x, int y);
};
//Function to add a node at head in singly linked list
void SLinkedList::addToHead(int i) {
	if (head == NULL)
		head = tail = new Node(i);
	else {
		Node *temp = new Node(i);
		temp->next = head;
		head = temp;
	}
}
//Function to display the complete linked list.
void SLinkedList::display() {
	Node *temp = head;
	while (temp != NULL) {
		cout << temp->data << "  ";
		temp = temp->next;
	}
	cout << endl;
}

//Function that exchanges two nodes without exchanging data.
bool SLinkedList::exchange(int x, int y) {
	//Step 1: we will first count the number of nodes in list.
	int maxNodes = 0;
	Node *ptr = head;
	while (ptr != NULL) {
		maxNodes++;
		ptr = ptr->next;
	}
	//so if the exchanged nodes are in the range of link list we return true else .
	if (x > 0 && x <= maxNodes && y > 0 && y <= maxNodes) {
		//Step 2: finding the position of x and y
		//here p is a pointer which we use to traverse the list
		//prev is a pointer that will points to the previous of 'p'
		Node *p, *prev;
		p = head;
		prev = NULL;
		//pX will points to position of x and prevX points to previous of pX
		//pY will points to position of y and prevY points to previous of pY
		Node *pX = NULL, *prevX = NULL;
		Node *pY = NULL, *prevY = NULL;
		//here we are finding positions of x and y
		int i = 1;
		while (i != maxNodes + 1) {
			if (i == x) {
				pX = p;
				prevX = prev;
			}
			if (i == y) {
				pY = p;
				prevY = prev;
			}
			prev = p;
			p = p->next;
			i++;
		}
		
		//temp will points to the next of pY because we don't want to lose that link.
		Node *temp = pY->next;
		//Case 1 : If both of the nodes are adjacent
		if (pX->next == pY ) {
			pX->next = temp;
			pY->next = pX;
	
			if (pX != head)
			prevX->next = pY;
			if (prevX == NULL) {
				head = pY;
			}
			return true;
		}
		if (pY->next == pX) {
			pY->next = pX->next;
			pX->next = pY;
			if (pY != head)
			prevY->next = pX;
			if (prevY == NULL) {
				head = pX;
			}
			return true;
		}

		//Case 2: If either of the node is at head.
		pY->next = pX->next;
		pX->next = temp;
		if (prevX == NULL) {
			head = pY;
			prevY->next = pX;
		}
		if (prevY == NULL) {
			pX = head;
			prevX->next = prevY;
		}


		//Case 3 & 4: Both the nodes are between head and tail OR either one of the nodes is at tail.
		if (prevX != NULL && prevY != NULL) {
			prevX->next = pY;
			prevY->next = pX;
		}
		return true;
	}
	else {
		cout << "Invalid Node Number!!" << endl;
		return false;
	}
}

int main() {

	SLinkedList s;
	s.addToHead('f');
	s.addToHead('e');
	s.addToHead('d');
	s.addToHead('c');
	s.addToHead('b');
	s.addToHead('a');
	s.display();
	cout << "\n\tFor Exchanging two Nodes!!" << "\n\n";
	int x,  y;
	cout << "Enter first node to exchange:";
	cin >> x;
	cout << "Enter second node to exchange:";
	cin >> y;
	if (s.exchange(x, y) == true)
	s.display();
	
	system("pause");
	return 0;
}