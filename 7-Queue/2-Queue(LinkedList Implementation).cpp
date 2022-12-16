//Linked List implementation of Queue
//Here we enQueue at tail(rear) means we insert a new node at tail(rear)
//Here we deQueue from head(front) means we delete a node from head(front)

#include<iostream>
using namespace std;

class Node {
public:
	int info;
	Node *next;
	//constructor
	Node(int i, Node *p = NULL) {
		info = i;
		next = p;
	}
};

class MyQueue {
private:
	Node *front, *rear;
public:
	//constructor
	MyQueue() {
		front = rear = NULL;
	}

	bool isEmpty();
	void enQueue(int i);
	int deQueue();
	int frontOfQueue();
	int rearOfQueue();
	void displayQueue();
};

//check queue is empty or not
bool MyQueue::isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}

//inserting a node at rear of queue
void MyQueue::enQueue(int i) {
	//when the queue is empty
	if (isEmpty())
		front = rear = new Node(i);
	//when queue is not empty
	else {
		Node *temp;
		temp = new Node(i);
		rear->next = temp;
		rear = temp;
	}
}

//deleting a node from fornt of queue
int MyQueue::deQueue() {
	//when queue is empty
	if (isEmpty()) {
		cout << "Error: Empty Queue. Can't delete" << endl;
		return 0;
	}
	//when queue contains only one node
	else if (front == rear)
		front = rear = NULL;
	//when queue contains more than one nodes
	else {
		Node *temp;
		temp = front;
		front = temp->next;
		delete temp;
	}
}

//it returns current front of queue
int MyQueue::frontOfQueue() {
	if (isEmpty())
		return 0;
	else
		return front->info;
}

//it returns rear of queue
int MyQueue::rearOfQueue() {
	if(isEmpty())
	return 0;
	else
	return rear->info;
}

//display queue
void MyQueue::displayQueue() {
	//when queue is empty
	if (isEmpty())
		cout << "Empty Queue.Nothing to display" << endl;
	//when queue contains only one node
	else if (front == rear) {
		cout << "Queue is:";
		cout << front->info << endl;
	}
	//when queue contains more than one nodes
	else {
		Node *temp = front;
		cout << "Queue is:";
		while (temp != NULL) {
			cout << temp->info << "   ";
			temp = temp->next;
		}
		cout << endl;
		delete temp;
	}
	cout<<endl;
}
int main() {

	MyQueue q;
	q.deQueue();
	q.enQueue(7);
	cout << q.frontOfQueue()<<endl;
	q.enQueue(44);
	cout << q.frontOfQueue()<<endl;
	q.enQueue(88);
	cout << q.frontOfQueue()<<endl;
	q.deQueue();
	q.displayQueue();
	cout << q.frontOfQueue()<<endl;
	cout<<  q.rearOfQueue()<<endl;
	q.enQueue(8);
	q.displayQueue();
	q.deQueue();
	q.displayQueue();
	q.deQueue();
	q.displayQueue();
	q.deQueue();
	q.displayQueue();
	q.deQueue();
	q.deQueue();
	q.displayQueue();
	cout<<q.frontOfQueue()<<endl;
	cout<<q.rearOfQueue()<<endl;
	system("pause");
	return 0;
}
