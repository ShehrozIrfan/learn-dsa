//Array implementation of stack

#include<iostream>
using namespace std;

//maximum size of array
#define SIZE 100 

class MyStack{
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
			cout << "Error: Stack Overflow" << endl;
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
	//display stack
	void display() {
		cout << "StacK: ";
		for (int c = 0; c <= top; c++) {
			cout << st[c] << " ";
		}
		cout << endl;
	}
};


int main() {

	MyStack s;
	if (s.isEmpty())
		cout << "Stack is empty" << endl;
	else
		cout << "Stack is not empty" << endl;
	s.push(2);
	s.display();
	s.push(8);
	s.display();
	s.push(1);
	s.display();
	s.push(66);
	s.display();
	s.push(77);
	s.display();
	s.push(22);
	s.display();
	s.push(55);
	s.display();
	s.pop();
	s.display();
	cout << "Top of stack is:";
	cout << s.topOfStack()<<endl;

	system("pause");
	return 0;

}
