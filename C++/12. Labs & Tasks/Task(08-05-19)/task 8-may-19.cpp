#include<iostream>
using namespace std;

#define SIZE 10       //Constant size

/*class MyStack {
private:
	int top; //holds currently top of stack
	int st[SIZE];
public:
	MyStack() {
		top = -1;
	}

	//as we know that the array starts from 0 index and goes on and if index=-1 means array is empty
	//because array didn't have index in negative.
	bool isEmpty() {
		if (top == -1)
			return true;
		else
			return false;
	}

	void push(int x) {
		//if top =9 means 0-9 which means we have entered all the 10 values and no more values 
		//entered in stack so it will be overflow
		if (top == SIZE - 1) {
			cout << "Stack Overflow" << endl;
		}
		else {
			top = top + 1;
			st[top] = x;
		}
	}

	int pop() {
		if (top == -1)
			cout << "Empty Stack" << endl;
		else
			return st[top--];
	}

	void display() {
		cout << "Values in Stack are:" << endl;
		for (int c = 0; c <= top; c++) {
			cout << st[c] << "  ";
		}
		cout << endl;
	}
};

int main() {

	MyStack s;
	s.isEmpty();
	s.push(90);
	s.push(20);
	s.push(11);
	s.push(7);
	s.push(0);
	s.push(00);
	s.push(88);
	s.push(44);
	s.push(33);
	s.push(22);
	s.push(11);
	s.pop();
	s.display();
	system("pause");
	return 0;
}
*/

class MyStack {
private:
	int top; //holds currently top of stack
	char st[SIZE];
public:
	MyStack() {
		top = -1;
	}

	//as we know that the array starts from 0 index and goes on and if index=-1 means array is empty
	//because array didn't have index in negative.
	bool isEmpty() {
		if (top == -1)
			return true;
		else
			return false;
	}

	void push(char x) {
		//if top =9 means 0-9 which means we have entered all the 10 values and no more values 
		//entered in stack so it will be overflow
		if (top == SIZE - 1) {
			cout << "Stack Overflow" << endl;
		}
		else {
			top = top + 1;
			st[top] = x;
		}
	}

	char pop() {
		if (top == -1)
			cout << "Empty Stack" << endl;
		else
			return st[top--];
	}

	void display() {
		cout << "Values in Stack are:" << endl;
		for (int c = 0; c <= top; c++) {
			cout << st[c] << "  ";
		}
		cout << endl;
	}
};
int main() {
	MyStack s;
	s.push('A');
	s.push('E');
	s.push('I');
	s.push('O');
	s.push('U');
	s.display();
	s.pop();
	s.display();

	system("pause");
	return 0;
}


