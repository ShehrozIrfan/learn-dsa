//Linked List implementation of stack
//here push means inserting a node at head
//here pop means deleting a node form head
#include<iostream>
using namespace std;

class Node {
public:
	int info;
	Node *next;
	//constructor
	Node(int i, Node *p = 0) {
		info = i;
		next = p;
	}
};

class MyStack {
private:
	Node *top;
public:
	//constructor
	MyStack() {
		top = 0;
	}

	bool isEmpty();
	void push(int i);
	void pop();
	void display();
	int topOfStack();
};

//check stack is empty or not
bool MyStack::isEmpty() {
	if (top == 0)
		return true;
	else
		return false;
}

//push element in a stack
void MyStack::push(int i) {
	//if stack is empty
	if (top == 0) {
		top = new Node(i);
	}
	//if stack is not empty
	else {
		Node *temp;
		temp = new Node(i);
		temp->next = top;
		top = temp;
	}
}

//pop element from a stack
void MyStack::pop() {
	//if stack is empty
	if (top == 0) {
		cout << "Error: empty Stack nothing to delete" << endl;
	}
	//if stack contains only one element
	else if(top->next==0) {
		delete top;
		top = NULL;
	}
	//if stack contains more than one element
	else {
		Node *temp;
		temp = top;
		top = top->next;
		delete temp;
	}
}

//display stack
void MyStack::display() {
	//when stack is empty
	if (top == 0) {
		cout << "Empty Stack" << endl;
	}
	//when stack contains only one element
	else if (top->next== 0) {
		cout << "Stack is:";
		cout << top->info << endl;
	}
	//when stack contains more than one element
	else {
		Node *temp;
		temp = top;
		cout << "Stack is:";
		while (temp!= 0) {
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

//returns the current top of stack
int MyStack::topOfStack(){

	return top->info;
}


int main() {
	MyStack s;
	if (s.isEmpty())
		cout << "Stack is empty" << endl;
	else
		cout << "Stack is not empty" << endl;
	s.push(10);
	s.push(30);
	s.push(20);
	s.push(40);
	s.display();
	s.pop();
	s.display();
	cout << "Current top of stack is:";
	cout<<s.topOfStack()<<endl;
	system("pause");
	return 0;
}