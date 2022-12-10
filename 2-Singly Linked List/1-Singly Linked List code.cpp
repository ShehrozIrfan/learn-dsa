//DSA Task (27-04-19)
/*
Tasks:                         Marks
void addToHead(int);            05
bool isEmpty();                 05
bool isInList(int);             05
int deleteFromHead();           05
int deleteFromTail();           10
bool deleteFromList(int);       10
*/
/*
Name:                        College R#               University R#
Shehroz Irfan                   199                       024016
*/

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

class LinkedList {
private:
	Node *head, *tail;
public:
	//Constructor
	LinkedList() {
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

	//Task 1:Add to head

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

	//Task 2: Check list is empty or not

	bool checkIsEmpty() {
		if (head == 0) {
			cout << "List is Empty" << endl;
			return 1;
		}

		else {
			cout << "List is not Empty" << endl;
			return 0;
		}
	}
    
	//Task 3: bool isInList()

	bool isInList(int n) {

		if (head == 0) {
			cout << "List is Empty" << endl;
			cout << "Nothing to find" << endl;
			return 0;
		}
		else if (n == tail->info) {
			cout <<n<< " founded in List." << endl;
			return 1;
		}
		else {
			Node *temp;
			for (temp = head; temp->next != 0; temp = temp->next) {
				if (n == temp->info) {
					cout <<n<<" founded in List." << endl;
					return 1;
				}
			}

		}
		cout <<n<<" not founded in List" << endl;
	}
    

	//Task 4: delete from head

	int deleteFromHead() {
		if (head == 0) {
			cout << "List is Empty Nothing to delete" << endl;
			return 0;
		}
		else if (head == tail != 0) {
			head = tail = NULL;
			cout << "Deleted" << endl;
		}
		else {
			int value = 0;
			Node *temp;
			temp = head;
			head = temp->next;
			value = temp->info;
			delete temp;
			return value;
		}
		return 0;
	}

	//Task 5: delete from tail

	int deleteFromTail() {
		if (head == 0) {
			cout << "List is Empty.Nothing to Delete" << endl;
			return 0;
		}
		else if (head == tail != 0) {
			head = tail = NULL;
			cout << "Deleted" << endl;
		}
		else {
			int value = 0;
			Node *temp;
			for (temp = head; temp->next != tail; temp = temp->next);
			value = tail->info;
			delete tail;
			tail = temp;
			tail->next = 0;

		}
	}

	//Task 6: delete from list

	void deleteFromList() {
		//find length of list
		Node *ptr;
		int len = 0;
		for (ptr = head; ptr->next != 0; ptr = ptr->next) {
			len++;
		}
		len = len + 1;
		int n;
		cout << "Enter the node to be deleted(1 to "<<len<<"):";
		cin >> n;
		if (n>=1 && n<=len) {
			if (n == 1) {
				deleteFromHead();
			}
			else if (n == len) {
				deleteFromTail();
			}
			else {
				Node *temp;
				temp = head;
				for (int i = 0; i < n - 2; i++) {
					temp = temp->next;
				}
				Node *temp1;
				temp1 = temp->next;
				temp->next = temp1->next;
				delete temp1;
			}
		}
		else {
			cout << "Invalid Entry" << endl;
			cout << "Node not found" << endl;
		}
	}
	//display list

	void displayList() {
		if (head == 0) {
			cout << "Empty List" << endl;
		}
		else if (head == tail != 0) {
			cout << "List is:" << endl;
			cout << head->info << endl;
		}
		else {
			Node *temp;
			cout << "List is:" << endl;
			for (temp = head; temp->next != 0; temp = temp->next) {
				cout << temp->info << " ";
			}
		cout << tail->info << endl;
		
		}
	}
	~LinkedList(){
		Node *temp;
		temp=head;
		while(head!=NULL){
			head=head->next;
			temp->next=NULL;
			delete temp;
			cout<<"Node deleted"<<endl;
			temp=head;
		}
		delete temp;
		head=NULL;
	}
};

int main() {

	LinkedList list;
	list.addToHead(30);
	list.displayList();
	list.addToHead(20);
	list.displayList();
	list.addToTail(40);
	list.displayList();
	list.addToHead(10);
	list.displayList();
    list.addToTail(50);
	list.displayList();
//	list.checkIsEmpty();
//	list.isInList(40);
//	list.isInList(100);
//	list.deleteFromHead();
//	list.displayList();
//	list.deleteFromTail();
//	list.displayList();
//	list.deleteFromTail();
//	list.displayList();
//	list.deleteFromList();
//	list.displayList();
list.~LinkedList();
list.displayList();
	system("pause");
	return 0;
}
