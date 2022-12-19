// Level Order Traversal (BFS)
// Time- Complexity= O(n)
// Space-Complexity=O(1)-best
//                 =O(n)-worst/average

#include<iostream>

//instead of writing our own queue implementation we can use Queue in standard template library #include<queue>
#include<queue>

using namespace std;

//node class to create a new node
class Node{
	public:
		char data;
		Node *leftChild ;
		Node *rightChild;
		
		Node(char d,Node *l=NULL, Node *r=NULL){
			data=d;
			leftChild=l;
			rightChild=r;
		}
};


Node *root=NULL;


class BST{
	public:
		char insert(char d);
		int levelOrder(Node *root);
};

//function to insert a node in BST
char BST::insert(char d){
	//tempNode is a pointer which always has address of new node that is created.
	Node *tempNode = new Node(d);
	Node *parent = NULL;
	Node *current = NULL;

	if (root == NULL) {
		root = tempNode;
	}
	else {
		current = root;
		parent = NULL;

		while (1) {
			parent = current;
			//in BST value of all the nodes in left subtree is lesser or equal
			if (tempNode->data <= parent->data) {
				current = current->leftChild;
				if (current == NULL) {
					parent->leftChild = tempNode;
					return 0;
				}
			}
			//in BST value of all the nodes in right subtree is greater.
			else {
				current = current->rightChild;
				if (current == NULL) {
					parent->rightChild = tempNode;
					return 0;
				}
			}
		}
	}
}


//function for level order traversal
int BST::levelOrder(Node *root){
	if(root==NULL)
	return 0;
	
	//now to create a queue we use the following syntax
	queue<Node*>Q;
	
	//first we push root in queue
	Q.push(root);
	
	//while there is at least one discovered node
	while(!Q.empty()){
		Node *current=Q.front();
		Q.pop(); // removing the element at front
		cout<<current->data<<"  ";
	
		if(current->leftChild!=NULL)
		Q.push(current->leftChild);
	
		if(current->rightChild!=NULL)
		Q.push(current->rightChild);
	}
}
int main(){
	/*
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
    
    BST t;
    t.insert('M');
    t.insert('B');
    t.insert('Q');
    t.insert('A');
    t.insert('C');
    t.insert('Z');
    
    cout<<"Level Order Traversal(BFS) is:"<<"\n\n";
    t.levelOrder(root);
    cout<<"\n\n";
    
	return 0;
}
