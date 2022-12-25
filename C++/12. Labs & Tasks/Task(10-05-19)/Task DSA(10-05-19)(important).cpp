/*
Problem:
let we have a stack:
                    *       *
					*********
					*   12  *
					*********      
					*   5   *
					*********
					*   2   *
					*********

					and we wanted to get to out of it. and removing 2 from the above stack the stack will be like this:

					*       *
					*********
					*   12  *
					*********
					*   5   *
					*********

					so to do this we make two stacks one for storing values and in second stack we push the values of first stack.

*/

#include<iostream>
using namespace std;

//maximum size of array
#define SIZE 100 

class MyStack {
private:
	int top;
	int st[SIZE];
public:
	//constructor
	MyStack() {
		top = -1;
	}

	//check stack is empty or not
	bool isEmpty() {
		if (top == -1)
			return true;
		else
			return false;
	}

	//inserting an element on the top of stack
	void push(int x) {
		if (top == SIZE - 1) {
			cout << "Error: Queue Overflow" << endl;
		}
		else {
			top = top + 1;
			st[top] = x;
		}
	}

	//removing an element from the top of stack
	int pop() {
		if (top == -1) {
			cout << "Error: No element to pop" << endl;
		}
		return st[top--];
	}

	//returns the current top of stack
	int topOfStack() {
		return st[top];
	}

	//checks whether the stack is full or not
	bool isFull()
	{
		return top == SIZE - 1;
	}

	//display stack
	void display() {
		for (int c = 0; c <= top; c++) {
			cout << st[c] << " ";
		}
		cout << endl;
	}
};

class Queue {
private:
	//we made two stacks 
	MyStack s1, s2;
public:

	//inserting a value in queue
	void enQueue(int val)
	{
		if (s1.isFull()) {
			cout << "Queue is Full. Can't be insrted" << endl;
		}
		else {
			//we use the push method of MyStack class.
			s1.push(val);
		}
	}

	//removing a value from one stack and placing it in other stack and then we get out our desired value and again push the values in first stack
	int deQueue() {
		if (s1.isEmpty()) {
			cout << "Queue is Empty. Can`t be Dequed" << endl;
		}
		else {
			//while s1 is not empty pop the values from s1 and push in s2.
			while (!s1.isEmpty()) {
				s2.push(s1.pop());
			}

			//we get our desired value that is not on the top of s2.
			int val = s2.pop();

			//pushing the values back to s1
			//while s2 is not empty pop values from s2 and push in s1
			while (!s2.isEmpty()) {
				s1.push(s2.pop());
			}

			//returns are desired value
			return val;

		}
	}

	//to check s1 is empty or not
	bool isEmpty() {
		return s1.isEmpty();
	}

	//display queue
	void displayQueue() {
		cout << "Displaying Queue values:" << endl;
		s1.display();
	}
};
int main() {

	Queue myQueue;
	myQueue.enQueue(2);
	myQueue.enQueue(5);
	myQueue.enQueue(12);
	myQueue.displayQueue();

	myQueue.deQueue();
	myQueue.displayQueue();

	system("pause");
	return 0;
}
