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

class CLinkedList {
private:
	//in circular linked list we have a pointer to last node
	Node *last;
public:
	//Constructor
	CLinkedList() {
		last = NULL;
	}

	bool checkIsEmpty();
	void addToBegining(int i);
	void addToEnd(int i);
	void displayList();
	int isInList(int n);
	int deleteFromBegining();
	int deleteFromLast();
	void deleteFromList(int n);
	void sortList();
	void mergeList(CLinkedList l2);
	~CLinkedList();

};


bool CLinkedList::checkIsEmpty() {
	if (last == NULL) {
		cout << "List is Empty!" << endl;
		return 1;
	}
	else {
		cout << "List is not Empty" << endl;
		return 0;
	}
}

void CLinkedList::addToBegining(int i) {
	//when there is no node
	if (last == NULL) {
		last = new Node(i);
		last->next = last;
	}
	//when there are one or more than one node
	else {
	Node *temp;
	temp = new Node(i);
	temp->next = last->next;
	last->next = temp;
    }
}

void CLinkedList::addToEnd(int i) {
	//when there is no node
	if (last == NULL) {
		last = new Node(i);
		last->next = last;
	}
	else {
		//when there is one or more than one node
		Node *temp;
		temp = last->next;
		last->next = new Node(i);
		last = last->next;
		last->next = temp;

	}
}

int CLinkedList::isInList(int n) {
	if (checkIsEmpty()) {
		cout << "Number not found" << endl;
	}
	else {
		Node *temp;
		//points to first node
		temp = last->next;
		while (temp != last) {
			if (temp->info == n) {
				cout << "Number found in list" << endl;
				return 0;
			}
			temp = temp->next;
		}
		//for last node because the upper while loop doesn't check the last node so we have to check
		//it separately
		if (temp->info == n) {
			cout << "Number found in list" << endl;
			return 0;
		}
		//if number not found in upper while loop or in upper if then this statement is executed
		cout << "Number not found in list" << endl;
	}
}

int CLinkedList::deleteFromBegining() {
	//when list is empty
	if (checkIsEmpty()) {
		cout << "Empty List" << endl;
		cout << "Nothing to delete" << endl;
	}
	//when there is only one node
	else if (last->next == last) {
		delete last;
		last = NULL;
		cout << "First node Deleted" << endl;
	}
	//when there are more than one nodes
	else {
		int value = 0;
		Node *temp;
		temp = last->next;
		value = temp->info;
		last->next = temp->next;
		delete temp;
		cout << "First node Deleted" << endl;
		return value;
	}
}

int CLinkedList::deleteFromLast() {
	//when there is no node
	if (checkIsEmpty()) {
		cout << "Empty List" << endl;
		cout << "Nothing to delete" << endl;
	}
	//when there is only one node
	else if (last->next == last) {
		delete last;
		last = NULL;
		cout << "Last node Deleted" << endl;
	}
	//when there are more than one nodes
	else {
		int value = 0;
		Node *temp;
		temp = last->next;
		while (temp->next != last) {
			temp = temp->next;
		}
		Node *temp1;
		temp1 = temp->next;
		value = temp->info;
		temp->next = last->next;
		delete temp1;
		last = temp;
		cout << "Last Node Deleted" << endl;
		return value;
	}
}

void CLinkedList::displayList() {
	//when list is empty
	if (last == NULL) {
		cout << "Empty List" << endl;
		cout << "Nothing to display" << endl;
	}
	//when there is only one node
	else if (last->next == last) {
		cout << "List is:" << last->info << endl;
	}
	//when there are more than one nodes
	else {
		Node *temp;
		temp = last->next;
		cout << "List is:" << endl;
		while (temp != last) {
			cout << temp->info << " ";
			temp = temp->next;
		}
		//to display the last node
		cout << temp->info << endl;
	}
}

void CLinkedList::deleteFromList(int n) {
	//if list is empty
	if (checkIsEmpty()) {
		cout << "Nothing to delete" << endl;
	}
	//if deleted value is at last node
	else if (n == last->info) {
		deleteFromLast();
	}
	//if deleted value is at first node
	else if (n == last ->next ->info) {
		deleteFromBegining();
	}
	//if the deleted value is between first node and last node
	else {
		Node *temp;
		temp = last->next;
		Node *temp1;
		temp1 = temp->next;
		while (temp1->info != n) {
			temp1 = temp1->next;
			temp = temp->next;
		}
		temp->next = temp1->next;
		delete temp1;
		cout << "Deleted" << endl;
	}
}

void CLinkedList::sortList() {
	//when list is empty
	if (last == NULL) {
		cout << "Empty list Nothing to sort" << endl;
	}
	
	//when one or more than one nodes in list
	else {
		Node *temp;
		temp = last->next;
		Node *i, *j;
		int tempa;
		cout << "Sorted List is:" << endl;
		for (i = temp; i->next != temp; i = i->next) {
			for (j = i->next; j != temp; j = j->next) {
				if (i->info > j->info) {
					tempa = i->info;
					i->info = j->info;
					j->info = tempa;
				}
			}
		}
	}
	
}

void CLinkedList::mergeList(CLinkedList l2) {
	//if first list is empty
	if (last == NULL) {
		cout << "Merged:" << endl;
		l2.displayList();
	}
	//if second list is empty
	else if (l2.last == NULL) {
		cout << "Merged:" << endl;
		displayList();
	}
	//when both the lists are not empty
	else {
		Node *temp;
		temp = last->next;
		last->next = l2.last->next;
		l2.last->next = temp;
		last = l2.last;
		cout << "Lists are merged" << endl;
	}
}

CLinkedList::~CLinkedList() {
	Node *temp;
	temp = last->next;
	while (temp != last) {
		temp = temp->next;
		delete last->next;
		last->next = temp;
		cout << "Node deleted" << endl;
	}
	last = NULL;
	cout << "Node deleted" << endl;
}

int main() {
	CLinkedList list;
	list.addToBegining(10);
	list.addToEnd(55);
	list.addToBegining(66);
	list.addToEnd(80);
	list.displayList();
    list.~CLinkedList();
    list.displayList();
	system("pause");
	return 0;
}
