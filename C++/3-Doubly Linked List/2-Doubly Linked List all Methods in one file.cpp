//Doubly Linked List Methods(All the methods are not in this code but some common methods are).
//This doubly Linked list is designed to work with only INTEGER values means a Node can store only INTEGER data in this list.
//If you Enter any Character and Floating point digit then you will see a run time error.
//Errors and Bugs are Possible.
//If found any(Error/Bugs) then let me know and try to debug.
//The Below code is executed successfully on Microsoft Visual Studio 2017 with Nodes having INTEGER VALUES.
//There are better and efficient ways of doing below code but it depends on how better and efficient you think! 
//If you find any better and efficient way than this then surely, you must go for that efficient and better way.
//Happy Coding!!!
//Enjoy the code!!!

#include<iostream>
using namespace std;

class Node {
public:
	//in doubly linked list we have next pointer to store the
	//address of next node and prev pointer to store the
	//address of prev node.
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

	bool isEmpty();
	void addToHead(int i);
	void addToTail(int i);
	void displayList();
	void deleteFromHead();
	void deleteFromTail();
	bool isInList(int key);
	void deleteSingleValueFromList(int key);
	void sortList();
	bool isSorted();
	int countDuplicate(int key);
	bool exchange(int a, int b);
	void middleLinkedList();
	void reverseList();
	void removeDuplicate();
	~DLinkedList();
};

//check list is empty or not
bool DLinkedList::isEmpty() {
	if (head == 0) 
		return true;
	else 
		return false;
}

//add to head
void DLinkedList::addToHead(int i) {
	//when there is no node
	if (head == NULL) 
		head = tail = new Node(i);
	//when there is one or more than one node
	else {
		head->prev = new Node(i);
		head->prev->next = head;
		head = head->prev;
	}
}

//add to tail
void DLinkedList::addToTail(int i) {
	//when there is no node
	if (head == NULL) 
		head = tail = new Node(i);
	//when there is one or more than one node
	else {
		tail->next = new Node(i);
		tail->next->prev = tail;
		tail = tail->next;
	}
}

//displaylist
void DLinkedList::displayList() {
	if (head == NULL) {
		cout << "Invalid: List is Empty" << endl;
	}
	else {
		Node *temp = head;
		cout << "List is: ";
		while (temp != NULL) {
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

//delete from head
void DLinkedList::deleteFromHead() {
	if (head == NULL) 
		cout << "Invalid: Empty List. Can't Delete" << endl;
	else if (head == tail) 
		head = tail = NULL;
	else {
		Node *temp = head;
		head = head->next;
		delete temp;
		head->prev = NULL;
	}
}

//delete from tail
void DLinkedList::deleteFromTail() {
	if (head == NULL) 
		cout << "Invalid: Empty List. Can't delete" << endl;
	else if (head == tail != 0) 
		head = tail = NULL;
	else {
		Node *temp = tail;
		tail = temp->prev;
		delete temp;
		tail->next = NULL;
	}
}

//to check whether a given value is in list or not.
bool DLinkedList::isInList(int key) {
	if (head == NULL)
		cout << "Invalid: Empty List. Can't find" << endl;
	else {
		Node *temp = head;
		while (temp != NULL) {
			if (temp->info == key) {
			     return true;
			}
			temp = temp->next;
		}
		return false;
	}
}

//Destructor
DLinkedList::~DLinkedList() {
	if(isEmpty())
	    cout << "Invalid: Empty List. Can't Destroy" << endl;
	else {
		cout << "Destructor is called !!!!" << endl;
		Node *temp = head;
		while (head->next != NULL) {
			head = head->next;
			temp->next = NULL;
			delete temp;
			head->prev = NULL;
			temp = head;
		}
		delete temp;
		head = NULL;
	}
}

//deletes the single occurance of given value
void DLinkedList::deleteSingleValueFromList(int key) {
	if (isEmpty())
		cout << "Invalid : Empty List . Can't Delete!!" << endl;
	else if (head->info == key)
		deleteFromHead();
	else if (tail->info == key)
		deleteFromTail();
	else {
		Node *temp;
		Node *temp1;
		temp = head;
		temp1 = head->next;
		while (temp1->info != key) {
			temp1 = temp1->next;
			temp = temp->next;
		}
		temp->next = temp1->next;
		temp1->next->prev = temp;
		temp1->next = NULL;
		temp1->prev = NULL;
		delete temp1;
	}
}

//sort list
void DLinkedList::sortList() {
	if (head == NULL)
		cout << "Invalid!! Empty List. Can't Sort!!" << endl;
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
	}
}

//check whether a linked list is sorted or not(Ascending Order)
bool DLinkedList::isSorted() {
	Node *i, *j;
	int flag = 0;
	for (i = head; i->next != NULL; i = i->next) {
		for (j = i->next; j != NULL; j = j->next) {
			if (i->info > j->info) {
				flag++;
			}
		}
	}
	if (flag == 0)
		return true;
	else
		return false;
}

//Function to count duplicate nodes of given value
int DLinkedList::countDuplicate(int key) {
	int count = 0;
	if (isEmpty())
		cout << "Invalid!! Empty List. Can't count duplicate!" << endl;
	else if (head == tail)
		cout << "There is only one Node! Can't count duplicate!" << endl;
	else {
		Node *temp;
		temp = head;
		while (temp != NULL) {
			if (temp->info == key)
				count++;
			temp = temp->next;
		}
		if (count == 0)
			cout << key << " not found in list!!!" << endl;
		else if (count == 1)
			cout << "There is no duplicate of Node having value: " << key << endl;
		else
			cout << "There are " << count - 1 << " duplicate of Node having value: " << key << endl;
	}
	return count;
}

//Function to swap two nodes in Linked list
bool DLinkedList::exchange(int a, int b) {
	if (head == tail) {
		cout << "Invalid!! Only one Node. Can't Exchange!" << endl;
		return false;
	}
	else {
		Node *temp = head;
		Node *temp1 = head;
		while (temp->info != a) {
			temp = temp->next;
		}
		while (temp1->info != b) {
			temp1 = temp1->next;
		}
		int temporary;
		temporary = temp->info;
		temp->info = temp1->info;
		temp1->info = temporary;
		cout << "Nodes Exchanged!!" << endl;
	}
	return true;
}

//Function that finds middle of a Linked List
//It gives exact middle if the total number of nodes are odd. If total no. of nodes are even then it doesn't give exact middle.
void DLinkedList::middleLinkedList() {
	if (isEmpty())
		cout << "Invalid!! Empty List. Can't find Middle!!" << endl;
	else if (head == tail)
		cout << "Invalid!! Only one Node. Can't find Middle!!" << endl;
	else {
		int count = 0;
		Node *temp = head;
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}
		if (count == 2)
			cout << "Invalid!! Only Two Nodes. Can't find Middle!!" << endl;
		else {
			int middle = count / 2;
			middle = middle + 1;
			temp = head;
			while (middle > 1) {
				temp = temp->next;
				middle--;
			}
			cout << "Middle is: " << temp->info << endl;
		}
	}
}

//Function to reverse doubly linked list.
void DLinkedList::reverseList() {
	if (isEmpty())
		cout << "Invalid!! Empty List. Can't Reverse!!" << endl;
	else if (head == tail)
		cout << "Invalid!! Only one Node. Can't Reverese!!" << endl;
	else {
		Node *current = head, *temp = NULL;
		//swap the previous and next pointers of each node to reverse the list
		while (current != NULL) {
			temp = current->next;
			current->next = current->prev;
			current->prev = temp;
			current = current->prev;
		}
		//swap the head & tail pointers
		temp = head;
		head = tail;
		tail = temp;
		cout << "List is Reversed!!" << endl;
	}
}

//Function that removes duplicates from a Linked List
//e.g; if list is:                23   24   23   45   39   45   78   45   90
//then after removing duplicates: 23   24   45   39   78   90
//so you saw that it removes duplicates
void DLinkedList::removeDuplicate() {
	if (isEmpty()) {
		cout << "Invalid: Empty List. Can't Remove Duplicate!!" << endl;
		return;
	}
	else if (head == tail) {
		cout << "Invalid: Only one Node. Can't Remove Duplicate!!" << endl;
		return;
	}
	else {
		Node *current, *index, *temp;
		//Initially, current will point to head node
		for (current = head; current != NULL; current = current->next) {
			//index will point to node next to current
			for (index = current->next; index != NULL; index = index->next) {
				if (current->info == index->info) {
					//store the duplicate node in temp
					temp = index;
					index->prev->next = index->next;
					if (index->next != NULL)
						index->next->prev = index->prev;
				//delete duplicate node 
					temp = NULL;
				}
			}
		}
	}

}


//The purpose of this function is to display below data on console.
void display() {
	cout << "\n\t";
	cout << "The data you want to store in Linked List must be in INTEGER form!" << "\n\n";
	cout << "\t\tSelect Your Option:" << endl;
	cout << "\t\t===================\n" << endl;
	cout << "1. Check List is Empty Or Not" << endl;
	cout << "2. Add a Node at Head" << endl;
	cout << "3. Add a Node at Tail" << endl;
	cout << "4. Display List" << endl;
	cout << "5. Delete a Node From Head" << endl;
	cout << "6. Delete a Node From Tail" << endl;
	cout << "7. To Check Given value is in List or Not" << endl;
	cout << "8. Destroy the Complete List" << endl;
	cout << "9. Delete a value from list(single occurance of given value)" << endl;
	cout << "10.Whether a Linked List is sorted(Ascending Order) or not" << endl;
	cout << "11.Sort a Linked List(Ascending Order)" << endl;
	cout << "12.Count the node having duplicate values" << endl;
	cout << "13.Exchange two nodes in List" << endl;
	cout << "14.Find Middle of Linked List" << endl;
	cout << "15.Reverse Linked List" << endl;
	cout << "16.Remove Duplicates from a Linked List" << endl;

}


int main() {
	//object of doubly Linked list class.
	DLinkedList s;
	bool exit = true;
	int option;
	int num;

	do {
		system("CLS");
		display();
		cout << "\n";
		cin >> option;
		if (option >= 1 && option <= 16) {
			switch (option) {
			case 1: {
				if (s.isEmpty())
					cout << "List is Empty" << "\n";
				else
					cout << "List is not Empty" << "\n";
				break;
			}
			case 2: {
				cout << "Enter value to be inserted:";
				cin >> num;
				s.addToHead(num);
				cout << "Node Inserted!!" << endl;
				s.displayList();
				break;
			}
			case 3: {
				cout << "Enter value to be inserted:";
				cin >> num;
				s.addToTail(num);
				cout << "Node Inserted!!" << endl;
				s.displayList();
				break;
			}
			case 4: {
				s.displayList();
				break;			}
			case 5: {
				if (s.isEmpty()) {
					s.deleteFromHead();
				}
				else {
					s.deleteFromHead();
					cout << "Head Node deleted!" << endl;
				}
				break;
			}
			case 6: {
				if (s.isEmpty()) {
					s.deleteFromTail();
				}
				else {
					s.deleteFromTail();
					cout << "Tail Node deleted!" << endl;
				}
				break;
			}
			case 7: {
				cout << "Enter the value to find:";
				cin >> num;
				if (s.isInList(num) == true) {
					cout << "Value Founded" << endl;
				}
				else {
					cout << "Value not founded" << endl;
				}
				break;
			}
			case 8: {
				if (s.isEmpty()) {
					s.~DLinkedList();
				}
				else
				{
					s.~DLinkedList();
					cout << "Complete list Destroyed!!" << endl;
				}
				break;
			}
			case 9: {
				cout << "Enter the value to be deleted:";
				cin >> num;
				if (s.isInList(num) == true) {
					s.deleteSingleValueFromList(num);
					cout << "Value Deleted!" << endl;
				}
				else {
					cout << "Invalid: Value is not in List!" << endl;
				}
				break;
			}
			case 10: {
				if (s.isEmpty())
					cout << "Invalid: Empty List . Can't Sort!!" << endl;
				else {
					if (s.isSorted() == true)
						cout << "List is Sorted" << endl;
					else
						cout << "List is not Sorted" << endl;
				}
				break;
			}
			case 11: {
				if (s.isEmpty())
					cout << "Invalid! Empty List. Can't Sort" << endl;
				else {
					s.sortList();
					cout << "List is Sorted!!" << endl;
					s.displayList();
				}
				break;
			}
			case 12: {
				int key;
				cout << "Enter value whose duplicate you wanna find???";
				cin >> key;
				s.countDuplicate(key);
				break;
			}
			case 13: {
				if (s.isEmpty())
					cout << "Invalid!! Empty List. Can't Exchange!" << endl;
				else {
					int a, b;
					cout << "Enter first Node:";
					cin >> a;
					cout << "Enter second Node:";
					cin >> b;
					s.exchange(a, b);
				}
				break;
			}
			case 14: {
				s.middleLinkedList();
				break;
			}
			case 15: {
				s.reverseList();
				break;
			}
					 
			case 16: {
				s.removeDuplicate();
				break;
			}
			default: {
				break;
			}

			}
		}
		else {
			cout << "Invalid Option Selected!!!" << endl;
		}
		char choice;
	here:
		cout << "Do you want to continue?  (y / n):";
		cin >> choice;
		if (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y') {
			cout << "Invalid choice!" << endl;
			cout << "Please Select 'y' for yes and 'n' for no" << endl;
			goto here;
		}
		else if (choice == 'n' || choice == 'N')
			exit = false;
	} while (exit);


	
	system("pause");
	return 0;
}
