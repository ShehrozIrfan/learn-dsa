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
Node *root = NULL;

class BST {
public:

	//the definitions of all these functions is outside the class.
	int insert(int d);
	bool search(Node *root, int d);
};

//searchin in BST
bool BST::search(Node *root, int d) {
	//when tree is empty
	if (root == NULL)
		return false;
	//when the searched number is at root
	else if (root->data == d)
		return true;
	//when searched number is less than root->data then we go(search) to left side of tree
	else if (d <= root->data) {
		return search(root->leftChild, d);
	}
	//if searched number is greater than root->data then we go(search) to right side of tree
	else {
		return search(root->rightChild, d);
	}
}


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

int main() {
	BST t;
	t.insert(4);
	t.insert(6);
	t.insert(0);
	int num;
	cout << "Enter number to be searched:";
	cin >> num;
	if (t.search(root, num))
		cout <<num<< " Founded in BST" << endl;
	else
		cout <<num<< " Not founded in BST" << endl;


	
	system("pause");
		return 0;

}