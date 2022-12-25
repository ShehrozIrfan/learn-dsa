//Binary Search Tree (Linked List Implementation)

#include<iostream>
using namespace std;

//when a node is created it will have three things:
// 1. data(when a new node is created it has its value as data)
// 2. left child(when a new node is created it is NULL)
// 3. right child(when a new node is created it is NULL)
class Node {
public:
	//data will have the value that the node has
	int data;
	//left child stores the address of left child
	Node *leftChild;
	//right child stores the address of right child
	Node *rightChild;

	//Paremeterized constructor which initialize all the data members of class Node to 0 and  NULL.
	Node(int d = 0, Node *left = NULL, Node *right = NULL) {
		data = d;
		leftChild = left;
		rightChild = right;
	}
};

//This is a Global Pointer. we declare it gloabal because when we do pre , post or in order traversal we have to pass root as a argument from main when
// we call these functions. that's why we declare it global.
Node *root=NULL;

class BST {
public:
	
	//the definitions of all these functions is outside the class.
	int insert(int d);
	void preOrderTraversal(Node *root);
	void inOrderTraversal(Node *root);
	void postOrderTraversal(Node *root);
};

//insert function is used to insert a new node in a tree.
int BST::insert(int d) {
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

//in pre order traversal first root node is printed then left subtree and then right subtree is printed and it is true for all the nodes.
void BST::preOrderTraversal(Node *root) {

	if (root != NULL) {
		cout << root->data<<"  ";
		//here we use recursion
		preOrderTraversal(root->leftChild);
		preOrderTraversal(root->rightChild);
	}
	
}

//in "in order" traversal first left subtree is printed then the root node is printed and then right subtree is printed and is true for all the nodes.
void BST::inOrderTraversal(Node *root) {

	if (root != NULL) {
		//here we use recursion
		inOrderTraversal(root->leftChild);
		cout << root->data << "  ";
		inOrderTraversal(root->rightChild);
	}
	
}

//in post order traversal first left subtree is printed and then right subtree is printed and then root node is printed and is true for all the nodes.
void BST::postOrderTraversal(Node *root) {

	if (root != NULL) {
		//here we use recursion
		postOrderTraversal(root->leftChild);
		postOrderTraversal(root->rightChild);
		cout << root->data << "  ";
	}
	
}

int main() {
	BST t;
	t.insert(5);
	t.insert(4);
	t.insert(7);
	t.insert(6);
	t.insert(0);
	
	cout << "Pre Order Traversal is :" << "  ";
	t.preOrderTraversal(root);
	cout << "\n\n";

	cout << "In Order Traversal is :" << "  ";
	t.inOrderTraversal(root);
	cout << "\n\n";

	cout << "Post Order Traversal is :" << "  ";
	t.postOrderTraversal(root);
	cout << "\n\n";
	
	system("pause");
	return 0;
}