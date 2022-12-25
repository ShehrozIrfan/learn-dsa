//InOrder successor is the node that would come immediately after the given node in inOrder traversal of the BST.
//Time Complexity of this algorithm is O(h)=log base 2 n

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
	Node* insert(Node *root,int d);
	void inOrder(Node *root);

	Node* find(Node *root, int d);
	Node* findMin(Node *root);
	Node* findSuccessor(Node *root, int d);
};

//function to find the node whose successor we have to find
Node* BST::find(Node *root, int d) {
	if (root == NULL)
		return root;
	else if (root->data == d)
		return root;
	else if (root->data < d)
		return find(root->right, d);
	else
		return find(root->left, d);
}

//function to find minimum in a BST
Node* BST::findMin(Node *root) {
	if (root == NULL)
		return NULL;
	while (root->left != NULL)
		root = root->left;

	return root;
}

//function to find successor of a Node
Node* BST::findSuccessor(Node *root, int d) {
	//the node whose successor we have to find is stored in current
	Node *current = find(root, d);

	if (current == NULL)
		return NULL;
	//case 1: Node has right SubTree
	else if (current->right != NULL) {
		//if there is a right subtree then we know that the successor will be minimum value at the left of current->right
		return findMin(current->right);
	}
	//case 2: No right SubTree
	else {
		//to understand this see diagram illustration on register
		Node *successor = NULL;
		Node *ancestor = root;
		while (ancestor != current) {
			if (current->data < ancestor->data){
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else {
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}

Node* BST::insert(Node *root,int d) {
	if (root == NULL)
		root = new Node(d);
	else if (d <= root->data)
		root->left = insert(root->left, d);
	else
		root->right = insert(root->right, d);

	return root;
}

void BST::inOrder(Node *root) {
	if (root != NULL) {
		inOrder(root->left);
		cout << root->data << "  ";
		inOrder(root->right);
	}
}

int main() {
	/*Code To Test the logic
	  Creating an example tree
				5
			   / \
			  3   10
			 / \   \
			1   4   11
	*/

	BST t;
	Node *root = NULL;
	root = t.insert(root, 5); root = t.insert(root, 10);
	root = t.insert(root, 3); root = t.insert(root, 4);
	root = t.insert(root, 1); root = t.insert(root, 11);

	cout << "InOrder Traversal is: ";
	t.inOrder(root);
	Node *successor = t.findSuccessor(root, 3);

	if (successor == NULL)
		cout <<" \n" <<"No successor found" << endl;
	else
		cout <<"\n"<< "Successor is: " << successor->data << endl;


	system("pause");
	return 0;
}