#include<iostream>
using namespace std;

class Node {
public:
	int info;
	Node *next;
	Node *prev;

	//Constructor
	Node(int i, Node *n = NULL, Node *p = NULL) {
		info = i;
		next = n;
		prev = p;
	}
};

class DLinkedList {
private:
	Node *head, *tail;
public:
	//constructor
	DLinkedList() {
		head = tail = NULL;
	}

	bool checkIsEmpty();
	void displayList();
	void addToHead(int i);
	void addToTail(int i);
	bool isInList();
	int deleteFromHead();
	int deleteFromTail();
	void deleteFromList();
	void sortList();
	void deleteValueFromList(int n);
	void mergeList(DLinkedList l2);
	~DLinkedList();
};

//check list is empty or not
bool DLinkedList::checkIsEmpty() {
	if (head == 0) {
		cout << "List is Empty" << endl;
		return 1;
	}
	else {
		cout << "List is not Empty" << endl;
		return 0;
	}
}

//add to head
void DLinkedList::addToHead(int i) {
	//when there is no node
	if (head == 0) {
		head = tail = new Node(i);
	}
	//when there is one or more than one node
	else {
		head->prev = new Node(i);
		head->prev->next = head;
		head = head->prev;
	}
}

//displaylist
void DLinkedList::displayList() {
	if (head == 0) {
		cout << "Empty List" << endl;
		cout << "Nothing to display" << endl;
	}
	else if (head == tail != 0) {
		cout << "List is:" << endl;
		cout << head->info << endl;
	}
	else {
		Node *temp;
		temp = head;
		cout << "List is:" << endl;
		while (temp != NULL) {
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

//add to tail
void DLinkedList::addToTail(int i) {
	//when there is no node
	if (head == 0) {
		head = tail = new Node(i);
	}
	//when there is one or more than one node
	else {
		tail->next = new Node(i);
		tail->next->prev = tail;
		tail = tail->next;
	}
}

bool DLinkedList::isInList() {
	int n;
	cout << "Enter value to find:";
	cin >> n;

	Node *temp;
	temp = head;
	while (temp != NULL) {
		if (temp->info == n) {
			cout << "Number founded in List" << endl;
			return 1;
		}
		temp = temp->next;
	}
	cout << "Number not found in List" << endl;
	return 0;
}

//delete from head
int DLinkedList::deleteFromHead() {
	if (head == 0) {
		cout << "List is empty." << endl;
		cout << "Nothing to delete." << endl;
		return 0;
	}
	else if (head == tail != 0) {
		head = tail = 0;
		cout << "deleted" << endl;
		return 0;
	}
	else {
		int value = 0;
		Node *temp;
		temp = head;
		head = temp->next;
		value = temp->info;
		delete temp;
		head->prev = NULL;
		return value;
	}
	return 0;
}

//delete from tail
int DLinkedList::deleteFromTail() {
	if (head == 0) {
		cout << "List is empty." << endl;
		cout << "Nothing to delete." << endl;
		return 0;
	}
	else if (head == tail != 0) {
		head = tail = 0;
		cout << "deleted" << endl;
		return 0;
	}
	else {
		int value = 0;
		Node *temp;
		temp = tail;
		value = temp->info;
		tail = temp->prev;
		delete temp;
		tail->next = NULL;
		return value;

	}
	return 0;
}

//delete from list
void DLinkedList::deleteFromList() {
	//find length of list
	int len = 0;
	int n;
	Node *temp;
	temp = head;
	while (temp != NULL) {
		len++;
		temp = temp->next;
	}
	cout << "Enter the Node to be deleted(from 1 to " << len << " ):";
	cin >> n;
	if (n >= 1 && n <= len) {
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
			temp1->next->prev = temp;
			delete temp1;
		}
	}
	else {
		cout << "Invalid Entry" << endl;
		cout << "Node not found in list" << endl;
	}
}

//sort list
void DLinkedList::sortList() {
	if (head == 0) {
		cout << "Empty List" << endl;
		cout << "Nothing to sort" << endl;
	}
	else {

		Node *p, *j;
		int temp;
		for (p = head; p->next != NULL; p = p->next) {
			for (j = p->next; j != NULL; j = j->next) {
				if (p->info > j->info) {
					temp = p->info;
					p->info = j->info;
					j->info = temp;
				}
			}
		}
		cout << "List is Sorted" << endl;
	}
}

// delete a value from list

void  DLinkedList::deleteValueFromList(int n) {
	int len = 0;
	Node *ptr;
	ptr = head;
	while (ptr != NULL) {
		if (ptr->info == n) {
			len++;
		}
		ptr = ptr->next;
	}
	//if value not found in list
	if (len == 0) {
		cout << "Value not found in List" << endl;
	}
	else {

		// if the finding value is at head
		if (head->info == n) {
			//if the value is repeating
			if (len > 1) {
				sortList();
				while (len != 0) {
					deleteFromHead();
					len--;
				}
				cout << "Deleted" << endl;
			}
			else {
				//if the value is not repeating
				deleteFromHead();
				cout << "Deleted" << endl;
			}
		}
		//if the finding value is at tail
		else if (tail->info == n) {
			//if the value is repeating
			if (len > 1) {
				sortList();
				while (len != 0) {
					deleteFromTail();
					len--;
				}
				cout << "Deleted" << endl;
			}
			else {
				//if the value is not repeating
				deleteFromTail();
				cout << "Deleted" << endl;
			}
		}


		else {
			//if the finding value is not head and not at tail
			if (len > 1) {
				sortList();
				//if the value is repeating
				while (len != 0) {
					Node *temp = head;
					Node *temp1 = head->next;
					while (temp1->info != n) {
						temp1 = temp1->next;
						temp = temp->next;
					}
					temp->next = temp1->next;
					temp1->next->prev = temp;
					delete temp1;
					len--;
				}
				cout << "Deleted" << endl;
			}
			else {
				//if the finding value is not repeating
				Node *temp = head;
				Node *temp1 = head->next;
				while (temp1->info != n) {
					temp1 = temp1->next;
					temp = temp->next;
				}
				temp->next = temp1->next;
				temp1->next->prev = temp;
				delete temp1;
				cout << "Deleted" << endl;
			}
		}
	}
}

void DLinkedList::mergeList(DLinkedList l2) {
	if (this->head == 0) {
		l2.displayList();
		cout << "List Merged" << endl;
	}
	else if (l2.head == 0) {
		displayList();
		cout << "List Merged" << endl;
	}
	else {
		Node *temp;
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = l2.head;
		l2.head->prev = temp;
		tail = l2.tail;
		cout << "List Merged" << endl;
	}
}

DLinkedList::~DLinkedList() {
	Node *temp;
	temp = head;
	while (head->next!=NULL) {
		head = head->next;
		temp->next = NULL;
		
		delete temp;
	    head->prev=NULL;
		temp = head;
		cout << "Node Deleted" << endl;
	}
	delete temp;
	head = NULL;
	cout<<"Node Deleted"<<endl;
	
}
int main() {

	DLinkedList list;
	list.addToHead(10);
	list.addToHead(30);
	list.addToTail(60);
	list.addToTail(60);
	list.addToTail(100);
	list.addToHead(50);
//	list.checkIsEmpty();
	list.displayList();
//	list.isInList();
	//list.deleteFromHead();
	//list.displayList();
	//list.deleteFromHead();
	//list.displayList();
	//list.deleteFromHead();
	//list.deleteFromTail();
	//list.displayList();
	//list.displayList();
	//list.deleteFromList();
	//list.displayList();
//	list.sortList();
//	list.displayList();
	//list.deleteValueFromList(10);
	//list.displayList();
	//list.deleteValueFromList(100);
	//list.displayList();
	//list.deleteValueFromList(60);
	//list.displayList();
	list.~DLinkedList();
	list.displayList();
//	DLinkedList l2;
//	l2.addToHead(10);
//	l2.addToTail(90);
//	l2.addToTail(87);
//	l2.addToTail(12);
//	list.mergeList(l2);
//	list.sortList();
//	list.displayList();

	system("pause");
	return 0;
}
