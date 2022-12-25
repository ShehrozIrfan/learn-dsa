//Double Ended Queue(also called deque) is a generalized version of Queue that allows
//insertion and deletion at both ends.

//We will implement this using doubly linked list.

//Operations on Deque:
//insertFront() : Adds an item at the front of Deque.
//insertRear() : Adds an item at the rear of Deque.
//deleteFront() : Deletes an item from front of Deque.
//deleteRear() : Deletes an item from rear of Deque.
//getFront() : Gets the front item from queue.
//getRear() : Gets the last item from queue.
//isEmpty() : Checks whether Deque is empty or not.
//size() : Gets number of elements in Deque.
//erase() : Deletes all the elements from Deque.

//Time Complexity : Time complexity of operations like 
//insertFront(), insertRear(), deleteFront(), deleteRear()is O(1).
//Time Complexity of erase() is O(n).

#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node *prev;
	//Constructor
	Node(int d = 0, Node *n = NULL, Node *p = NULL) {
		data = d;
		next = n;
		prev = p;
	}
};

class Deque {
private:
	//in queue we have front and rear instead of head and tail
	Node *front, *rear;
	//counts the size of deque
	int size;
public:
	//Constructor
	Deque() {
		front = rear = NULL;
		size = 0;
	}

	bool isEmpty();
	void insertFront(int i);
	void insertRear(int i);
	void deleteFront();
	void deleteRear();
	int getFront();
	int getRear();
	int Size();
	void erase();
	void display();
};
//function to check whether deque is empty or not
bool Deque::isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}
//function to insert at front of deque
void Deque::insertFront(int i){
	if (front == NULL) {
		front = rear = new Node(i);
	}
	else {
		Node *temp = new Node(i);
		temp->next = front;
		front->prev = temp;
		front = temp;
	}
	size++;

}
//function to insert at rear of deque
void Deque::insertRear(int i) {
	if (front == NULL) {
		front = rear = new Node(i);
	}
	else {
		Node *temp = new Node(i);
		rear->next = temp;
		temp->prev = rear;
		rear = temp;
	}
	size++;
}
//function to delete from front of deque
void Deque::deleteFront() {
	if (isEmpty()) {
		cout << "Underflow!!" << endl;
		return;
	}
		
	else if (front == rear) {
		front = rear = NULL;
	}
	else {
		Node *temp = front;
		front = front->next;
		front->prev = NULL;
		temp->next = NULL;
		delete temp;
	}
	size--;
}
//function to delete from rear of deque
void Deque::deleteRear() {
	if (front == NULL) {
		cout << "Underflow!!" << endl;
		return;
	}
	else if (front == rear) {
		front = rear = NULL;
	}
	else {
		Node *temp = rear;
		rear = rear->prev;
		rear->next = NULL;
		temp->prev = NULL;
		delete temp;
	}
	size--;
}
//functionn to get current front of deque
int Deque::getFront() {
	if (isEmpty())
		return -1;
	return front->data;
}
//function to get current rear of deque
int Deque::getRear() {
	if (isEmpty())
		return -1;
	return rear->data;
}
//function to get size of deque
int Deque::Size() {
	return size;
}
//function to delete all values from deque
void Deque::erase() {
	rear = NULL;
	while (front != NULL) {
		Node *temp = front;
		front = front->next
;
		//front->prev = NULL;
		delete temp;
	}
}
//function to display values in deque
void Deque::display() {
	if (isEmpty())
		cout << "Empty Queue" << endl;
	else if (front == rear) {
		cout << "Double Ended Queue is: ";
		cout << front->data << endl;
	}
	else {
		cout << "Double Ended Queue is: ";
		Node *temp = front;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}


int main() {
	Deque d;
	if (d.isEmpty() == true)
		cout << "Double Ended Queue is Empty" << endl;
	else
		cout << "Double Ended Queue is not Empty" << endl;
	cout << "Size is: " << d.Size() << endl;
	d.insertFront(4);
	d.display();
	cout << "Front is: " << d.getFront() << endl;
	d.insertRear(5);
	d.display();
	cout << "Rear is: " << d.getRear() << endl;
	cout << "Size is: " << d.Size() << endl;
	d.deleteFront();
	d.display();
	d.deleteRear();
	d.display();
	d.insertFront(10);
	d.insertFront(5);
	d.insertRear(7);
	d.insertRear(77);
	d.display();
	cout << "Front is: " << d.getFront() << endl;
	cout << "Rear is: " << d.getRear() << endl;
	cout << "Size is: " << d.Size() << endl;
	d.erase();
	d.display();
	system("pause");
	return 0;
}