//Check whether a tree is BST or not.
//Time Complexity is O(N)
#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;

	Node(int d, Node *l = NULL, Node *r = NULL) {
		data = d;
		left = l;
		right = r;
	}
};

class BST {
public:
	//BST Utility Function.
	bool isBSTUtil(Node *root, int minValue, int maxValue) {
		if (root == NULL)
			return true;
		if (root->data<minValue || root->data>maxValue )
			return false;
		return  isBSTUtil(root->left, minValue, root->data) && isBSTUtil(root->right, root->data, maxValue);
	}
	//function that returns true if tree is BST or false otherwise.
	bool isBinarySearchTree(Node *root) {
		return isBSTUtil(root, INT_MIN, INT_MAX);
	}
};

int main() {

	BST t;

	Node *root = NULL;
	
	root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(3);
	root->right->right = new Node(0);
	
	if (t.isBinarySearchTree(root))
		cout << "Is BST"<<"\n";
	else
		cout << "Not a BST"<<"\n";
	
	system("pause");
	return 0;
}