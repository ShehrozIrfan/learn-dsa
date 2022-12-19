//This is a recursive method of finding min and max in BST

#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *leftChild;
	Node *rightChild;
	//Constructor
	Node(int d = 0, Node *left = NULL, Node *right = NULL) {
		data = d;
		leftChild = left;
		rightChild = right;
	}
};

Node *root = NULL;

class BST {
public:
	int findMin(Node *root);
	int findMax(Node *root);
	int insert(int d);
};

//so to find the minimum value we go as left as possible.
int BST::findMin(Node *root) {
	//when tree is empty
	if (root == NULL) {
		cout << "\n" << "Error: Tree is Empty" << endl;
		return -1;
	}
	//when tree is not empty
	else {
		//base condition for recursion
		if (root->leftChild == NULL) {
			return root->data;
		}
		//search in left subtree
		findMin(root->leftChild);
	}
}

//to find maximum value we go as right as possible.
int BST::findMax(Node *root) {
	//when tree is empty
	if (root == NULL) {
		cout << "\n" << "Error: Tree is Empty" << endl;
		return -1;
	}
	//when tree is not empty
	else {
		//base condition for recursion
		if (root->rightChild == NULL) {
			return root->data;
		}
		//search in right subtree
		findMax(root->rightChild);
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
	t.insert(5);
	t.insert(3);
	t.insert(9);
	t.insert(2);
	t.insert(0);
	t.insert(10);
	t.insert(8);
	t.insert(7);
	t.insert(1);
	cout << "Maximum Node is:" << t.findMax(root) << endl;
	cout << "Minimum Node is:" << t.findMin(root) << endl;



	system("pause");
	return 0;
}