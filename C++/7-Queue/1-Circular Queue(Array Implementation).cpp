//Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last 
//position is connected back to the first position to make a circle. It is also called ‘Ring Buffer’.

//This is the implementation of circular queue
//Array Implementation of Queue
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
	int rearOfQueue();
	void display();
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
		return -1;
	//when queue is not empty
	else
	return que[front];
}
int MyQueue::rearOfQueue(){
	if(isEmpty())
	return -1;
	else
	return que[rear];
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

int main() {

	MyQueue q;
    if(q.isEmpty()==true)
    cout<<"Circular Queue is Empty"<<endl;
    else
    cout<<"Circualr Queue is not Empty"<<endl;
    
    q.enQueue(5);
    q.enQueue(3);
    q.display();
    cout<<"Front of Queue is: "<< q.frontOfQueue()<<endl;
	cout<<"Rear of Queue is:"<< q.rearOfQueue()<<endl;
	q.deQueue();
	q.display();
	q.enQueue(9);
	q.enQueue(19);
	q.enQueue(119);
	q.enQueue(90);
	q.enQueue(95);
	q.enQueue(93);
	q.display();
	system("pause");
	return 0;
}
