/*

To delete a node from BST there are three scenarios:
1- root has no child
2- root has one child
3- root has two children

*/
#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;

	Node(int d,Node *l=NULL, Node *r=NULL) {
		data = d;
		left = l;
		right = r;
	}
};
class BST {
public:
	Node* FindMin(Node *root);
	Node* Delete(Node *root, int data);
	void inOrderTraversal(Node *root);
	Node* insert(Node *root, int d);
};

//function to find node value
Node* BST::FindMin(Node *root) {
	while (root->left != NULL) {
		root = root->left;
		return root;
	}
}

//function to search a node to be deleted and then delete it.
Node* BST::Delete(Node *root, int data) {
	if (root == NULL)
		return root;
	else if (data < root->data)
		root->left = Delete(root->left, data);
	else if (data > root->data)
		root->right = Delete(root->right, data);
	//now we have found the node to be deleted let's delete it...
	else {
		//Case 1: No Child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One Child
		else if (root->left == NULL) {
			Node *temp;
			temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			Node *temp;
			temp = root;
			root = root->left;
			delete temp;
		}
		//Case 3: Two Children
		else {
			Node *temp;
			//find minimum in right sub-tree
			temp = FindMin(root->right);
			//copy the minimum value at the place of node to be deleted
			root->data = temp->data;
			//delete duplicate value
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

//function for inOrder Traversal
void  BST::inOrderTraversal(Node *root){
	if (root != NULL) {
		inOrderTraversal(root->left);
		cout << root->data<<"  ";
		inOrderTraversal(root->right);
	}
}

//function to insert a new node in BST
Node* BST::insert(Node *root, int d) {
	if (root == NULL)
		root = new Node(d);
	else if(d<=root->data)
		root->left = insert(root->left, d);
	else
		root->right = insert(root->right, d);
	return root;
}

int main() {

	/*Code To Test the logic
	  Creating an example tree
		        5
			   / \
			  3   10
			 / \   \
			1   4   11
			
			to check this code properly use 11, 3, 10 , 5 to be deleted values.
	*/
	Node *root = NULL;

	BST t;

	root = t.insert(root, 5); root = t.insert(root, 10);
	root = t.insert(root, 3); root = t.insert(root, 4);
	root = t.insert(root, 1); root = t.insert(root, 11);

	t.Delete(root, 3);
	cout << "InOrder Traversal is:  ";
	t.inOrderTraversal(root);


	system("pause");
	return 0;
}