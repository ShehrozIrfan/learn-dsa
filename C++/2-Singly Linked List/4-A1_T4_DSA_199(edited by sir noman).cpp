#include<iostream>
using namespace std;

class Node{
	public:
		int info;
		Node *next;
		Node(int i,Node *p=0){
			info=i;
			next=p;
		}
};

class LinkedList{
	private:
		Node *head,*tail;
		public:
			LinkedList(){
				head=tail=0;
			}
			void addToHead(int i){
            if(head==0){
            	head=tail=new Node(i);
			}
            else{
			
				Node *temp;
				temp=new Node(i);
				temp->next=head;
				head=temp;
			}
		}
		void addToTail(int i){
			if(head==0){
				head=tail=new Node(i);
			}
			else{
				tail->next=new Node(i);
				tail=tail->next;
			}
		}
		
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

		void displayList(){
			if(head==0){
				cout<<"Empty List"<<endl;
				cout<<"Nothing to display"<<endl;
			}
			else if (head==tail!=0){
				cout<<"List is:"<<endl;
				cout<<head->info<<endl;
			}
			else{
				Node *temp;
				temp=head;
				cout<<"List is:"<<endl;
			    while(temp!=NULL){
			    	cout<<temp->info<<" ";
			    	temp=temp->next;
				}
				cout<<endl;
			}
		}
		 
		 // Sort List
		void sortList(){
			Node *i,*j;
			int temp;
			
			for(i=head;i->next!=NULL;i=i->next){
				for(j=i->next;j!=NULL;j=j->next){
					if(i->info > j->info){
						temp=i->info;
						i->info=j->info;
						j->info=temp;
					}
				}
			}
			cout<<"List is Sorted"<<endl;
		}	
	     // Merge List
		void mergeList(LinkedList l2){
				if(this->head==NULL){
					l2.displayList();
				}
				else if(l2.head==NULL){
					displayList();
				}
				else{
				
				Node *temp;
				temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				
				temp->next=l2.head;
				tail=l2.tail;
		}
	}
	
	// delete from list
	bool deleteFromList(int n){
		//finding occurance of n
		Node *ptr;
		int len=0;
		ptr=head;
		while(ptr!=NULL){
			if(ptr->info==n){
				len++;
			}
			ptr=ptr->next;
		}
		if(len==0){
			cout<<"Node not found in List"<<endl;
		}
		else{
		
		if(n==head->info){
			deleteFromHead();
			return 1;
		}
		else if(n==tail->info){
			deleteFromTail();
			return 1;
		}
		else{
		Node *temp;
		Node *temp1;
		temp=head;
		temp1=head->next;
		while(temp1->info!=n){
			temp1=temp1->next;
			temp=temp->next;
		}
		temp->next=temp1->next;
		delete temp1;
		}
		return 1;
	}
}
		// delete second last
		void deleteSecondLast(){
			if(head==0){
				cout<<"Empty List"<<endl;
				cout<<"Nothing to delete"<<endl;
			}
			else if(head==tail!=0){
				delete head;
				head=tail=0;
				cout<<"Deleted"<<endl;
			}
			else if(head->next==tail){
				Node *temp;
				temp=head;
				head=temp->next;
				delete temp;
				cout<<"Deleted"<<endl;
			}
			else{
				Node *temp;
				Node *temp1;
				temp=head;
				temp1=head;
				while(temp1->next!=tail){
					temp1=temp1->next;
				}
				while(temp->next!=temp1){
					temp=temp->next;
				}
				temp->next=tail;
				delete temp1;
				cout<<"Deleted"<<endl;
				
				
			}
		}
		
		//Insert After head
		void insertAfterHead(int i){
			if(head==0){
				cout<<"Empty list"<<endl;
				cout<<"Can't add after head"<<endl;
			}
			else if(head==tail!=0){
				head->next=new Node(i);
				tail=head->next;
			}
			else{
			    Node *temp=NULL;
			    temp=head->next;
			    head->next=new Node(i);
			    head->next->next=temp;
			}
		}
};

void display(){
	cout<<"Select an option\n===============\n\n";
	cout<<"1. Add to Head\n";
	cout<<"2. Add to Tail\n";
	cout<<"3. Insert After Head\n";
	cout<<"4. Display List\n";
	cout<<"5. Delete an element from list\n";
	cout<<"6. Sort List\n";
	cout<<"7. Delete Second Last\n";
	cout<<"8. Merge List\n";
}

int main(){
	
	bool stop = true;
	char opt;
	int num;
	LinkedList list;

	LinkedList l2;
	l2.addToHead(90);
	l2.addToTail(95);
	l2.addToTail(77);
	l2.addToHead(0);
	l2.addToHead(44);
	l2.displayList();
	
	do
	{
		system("cls");
		display();
		cout<<"\n";
		cin>>opt;
		switch(opt)
		{
			case '1':
				cout<<"Enter Value: ";
				cin>>num;
				list.addToHead(num);
				break;
			case '2':
				cout<<"Enter Value: ";
				cin>>num;
				list.addToTail(num);
				break;
			case '3':
				cout<<"Enter Value: ";
				cin>>num;
				list.insertAfterHead(num);
				break;
			case '4':
				list.displayList();
				break;
			case '5':
				cout<<"Enter Value: ";
				cin>>num;
				list.deleteFromList(num);
				break;
			case '6':
				list.sortList();
				break;
			case '7':
				list.deleteSecondLast();
				break;
			case '8':
				list.mergeList(l2);
				break;
			default:
				break;
		}
		
		cout<<"Do you want to continue? (y/n)??  ";
		cin>>opt;
			if(opt=='n')
				stop = false;
	}while(stop);

	return 0;
}
