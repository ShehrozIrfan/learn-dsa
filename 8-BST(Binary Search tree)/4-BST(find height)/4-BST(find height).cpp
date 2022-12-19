//This is code of finding Height of a binary tree.
// Height of Binary tree = max of height of left subtree and right subtree +1
// e.g; if height of left subtree= 2
// and   height of right subtree= 1
// then height of tree = 2+1 (because of 2 and 1 max is 2 so 2+1=3)
// e.g; if height of left subtree= 4
// and   height of right subtree= 5
// then height of tree = 5+1 (because of 4 and 5 max is 5 so 5+1=6)

#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *leftChild;
	Node *rightChild;
	//constructor
	Node(int d = 0, Node *left = NULL, Node *right = NULL) {
		data = d;
		leftChild = left;
		rightChild = right;
	}
};

Node *root = NULL;

class BST {
public:
	int findHeight(Node *root);
	int max(int x, int y);
	int insert(int d);
};

//this is function to find maximum of two integers
int BST::max(int x,int y) {
	return (x > y) ? x : y;
}

//function to find height of a tree
int BST::findHeight(Node *root) {
	//if tree is empty then we return -1 some people return 0 also.
	if (root == NULL)
		return -1;
	else {
		//leftHeight find the height of left subtree
		int leftHeight = findHeight(root->leftChild);
		//rightHeight find the height of right subtree
		int rightHeight = findHeight(root->rightChild);
		//function call which first finds the maximum of height of left subtree and right subtree and after finding maximum value it add 1 to it and
		//returns
		return max(leftHeight, rightHeight) + 1;
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
	/*
	the following tree will be constructed with height=4
	                         15
					      /      \
						12        17
					  /    \    /    \
   					10     13   16    18
					/        \         \
				   8         14         20
				                          \
										   22
	if there is only one node in tree then height=0
	e.g;                     
	                            15      ->height=0
							  /    \      
						    null   null
	*/
	t.insert(15);
	t.insert(12);
	t.insert(17);
	t.insert(10);
	t.insert(13);
	t.insert(16);
	t.insert(18);
	t.insert(8);
	t.insert(14);
	t.insert(20);
	t.insert(22);
	cout << "\n\n\t" << "Height of the tree is:"<<  t.findHeight(root)<<"\n\n\t";
	system("pause");
	return 0;
}