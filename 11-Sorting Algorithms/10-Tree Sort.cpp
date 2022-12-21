//Tree Sort
//Time Complexity: O(n^2) | Average case: O(nlogn)
//Space Complexity: O(n) Auxiliary
//Stable: Yes
//In-Place: Not

#include<iostream>
using namespace std;

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

class BST {
public:

	//the definitions of all these functions is outside the class.
	Node* insert(Node *root, int d);
	void storeSorted(Node *root, int A[], int &i);
	void treeSort(int A[], int n);
	void print(int A[],int size);
};

//insert function is used to insert a new node in a tree.
Node* BST::insert(Node *root, int d) {

	if (root == NULL) {
		Node *tempNode = new Node(d);
		return tempNode;
	}
	if (d <= root->data) {
		root->leftChild = insert(root->leftChild, d);
	}
	else if (d > root->data) {
		root->rightChild = insert(root->rightChild, d);
	}

	return root;
}

//Function to store inOrder traversal of BST in array.
void BST::storeSorted(Node *root, int A[], int &i) {

	if (root != NULL) {
		//here we use recursion
		storeSorted(root->leftChild, A, i);
		A[i++] = root->data;
		storeSorted(root->rightChild, A, i);
	}
}
//Function for tree sort
void BST::treeSort(int A[], int n) {
	Node *root = NULL;
	//first node will be inserted at root
	root = insert(root, A[0]);
	for (int i = 1; i < n; i++) {
		insert(root, A[i]);
	}

	int i = 0;
	storeSorted(root, A, i);
}
void BST::print(int A[],int size) {
	cout << "Sorted Array is: ";
	for (int i = 0; i < size; i++)
		cout << A[i] << "  ";
	cout << endl;
}

int main() {
	int size;
	cout << "How many values you wanna enter:";
	cin >> size;

	int *A = new int[size];

	for (int i = 0; i < size; i++)
		cin >> A[i];

	BST t;
	t.treeSort(A, size);

	t.print(A, size);

	delete[] A;

	system("pause");
	return 0;
}