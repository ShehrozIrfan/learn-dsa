//DSA lab
//03-05-19

#include<iostream>
using namespace std;

class Node {
public:
	int info;
	Node *next, *prev;
	
    //Constructor
	Node(int i, Node *p = 0) {
		info = i;
		next = p;
		prev = p;
	}

};

class DLinkedList {
private:
	Node *head;
	Node *tail;

public:
	//Constructor
	DLinkedList() {
		head = tail = 0;
	}
    //Task 1: add to head, add to tail , display list
    //add to head
	void addToHead(int i) {
		if (head == 0) {
			head = tail = new Node(i);
		}
		else {
			head->prev = new Node(i);
			head->prev->next = head;
			head = head->prev;
		}
	}
	
	//add to tail
	void addToTail(int i){
		if(head==0){
			head=tail=new Node(i);
		}
		else{
			tail->next=new Node(i);
			tail->next->prev=tail;
			tail=tail->next;
		}
	}
	
	//display list
	void displayList() {
		if (head == 0) {
			cout << "Empty List" << endl;
			cout << "Nothing to display" << endl;
		}
		else if (head == tail != 0) {
			cout<<"List is:"<<endl;
			cout << head->info << endl;
		}
		else {
			Node *temp;
			temp = head;
			cout<<"List is:"<<endl;
			while (temp != NULL) {
				cout << temp->info << " ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
	
	//task 2: delete from head
	//delete from head
	void deleteFromHead(){
		if(head==0){
			cout<<"Nothing to delete"<<endl;
		}
		else if(head==tail!=0){
			head=tail=0;
			cout<<" Head Deleted"<<endl;
		}
		else{
		
		Node *temp;
		temp=head;
		head=head->next;
		delete temp;
		head->prev=NULL;
		cout<<" Head Deleted"<<endl;
	}
}
    //task 3: delete from tail
    //delete from tail
    void deleteFromTail(){
    		if(head==0){
			cout<<"Nothing to delete"<<endl;
		}
		else if(head==tail!=0){
			head=tail=0;
			cout<<"Tail Deleted"<<endl;
		}
		else{
			Node *temp;
			temp=tail;
			tail=tail->prev;
			delete temp;
			tail->next=NULL;
			cout<<" Tail Deleted"<<endl;
		}
	}
};

int main() {

   DLinkedList list;
   list.displayList();
   list.addToHead(10);
   list.displayList();
   list.addToHead(5);
   list.displayList();
   list.addToTail(30);
   list.displayList();
   list.deleteFromHead();
   list.deleteFromTail();
   list.displayList();
   list.displayList();
   list.deleteFromTail();
   list.displayList();
   
	return 0;
}
