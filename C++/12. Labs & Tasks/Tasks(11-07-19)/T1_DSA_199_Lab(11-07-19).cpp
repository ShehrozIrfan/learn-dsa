//This is the implementation of circular queue
//Array Implementation of Circular Queue
//here EnQueue means inserting an element to queue at rear
//here deQueue means removing an element from queue from front

#include<iostream>
using namespace std;

//size of queue
#define SIZE 10

class MyQueue {
private:
	int que[SIZE];
	int front;
	int rear;

public:
	//constructor
	MyQueue() {
		front = -1;
		rear = -1;
	}

	int enQueue(int x);
	void deQueue();
	bool isEmpty();
	int frontOfQueue();
	void display();
	int searchKey(int key);
};

bool MyQueue::isEmpty() {
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

int MyQueue::enQueue(int x) {
	//when queue is empty
	if (front == -1 && rear == -1) {
		front = rear = 0;
	}
	//when queue is full
	else if ((rear + 1) % SIZE == front) {
		cout << "Error: Queue is full" << endl;
		return 0;
	}
	//when queue contains one or more than one element
	else {
		rear = (rear + 1) % SIZE;
	}
	que[rear] = x; //place value at rear index
}

void MyQueue::deQueue() {
	//when queue is empty
	if (front == -1 && rear == -1)
		cout << "Error: Queue is Empty" << endl;
	//when there is only one element in queue
	else if (front == rear)
		front = rear = -1;
	//when there are more than one element in queue
	else {
		front = (front + 1) % SIZE;
	}
}

int MyQueue::frontOfQueue() {
	//when queue is empty
	if (isEmpty())
		return 0;
	//when queue is not empty
	else
		return que[front];
}
void MyQueue::display() {
	//when queue is empty
	if (front == -1 && rear == -1) {
		cout << "Error: Empty Queue" << endl;
		cout << "Nothing to display" << endl;
	}
	else {
		//when queue contains one or more than one element
		cout << "Queue is:" << endl;
		for (int c = front; c <= rear; c++) {
			cout << que[c] << "   ";
		}
		cout << endl;
	}
}

//searching in queue.
int MyQueue::searchKey(int key) {
	//when queue is empty
	if (front == -1 && rear == -1) {
		cout << "Error: Empty Queue" << endl;
		cout << "Nothing to Search" << endl;
	}
	else {
		//when queue contains one or more than one element
		for (int c = front; c <= rear; c++) {
			if (que[c] == key) {
				cout << key << " Founded in Queue" << endl;
				return 0;
			}
		}
		cout << key << " not founded in Queue" << endl;
		
	}
}

int main() {

	MyQueue q;
	q.enQueue(5);
	q.enQueue(10);
	q.enQueue(3);
	q.display();
	q.searchKey(3);
	q.searchKey(0);
	q.searchKey(10);
	q.searchKey(5);
	q.searchKey(4);
	system("pause");
	return 0;
}