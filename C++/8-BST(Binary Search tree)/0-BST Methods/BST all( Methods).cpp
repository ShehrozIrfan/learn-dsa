//BST Operations
//Binary Search Tree Methods(All the methods are not in this code but some common methods are).
//This BST is designed to work with only INTEGER values means a Node can store only INTEGER data in this tree.
//If you Enter any Character and Floating point digit then you will see a run time error.
//Errors and Bugs are Possible.
//If found any(Error/Bugs) then let me know and try to debug.
//The Below code is executed successfully on Microsoft Visual Studio 2017 with Nodes having INTEGER VALUES.
//There are better and efficient ways of doing below code but it depends on how better and efficient you think! 
//If you find any better and efficient way than this then surely, you must go for that efficient and better way.
//Happy Coding!!!
//Enjoy the code!!!

#include<iostream>
#include<queue>  //STL(standard template library)
using namespace std;

class Node {
public:
	int data;
	Node *leftChild;
	Node *rightChild;
	//Constructor
	Node(char d , Node *l = NULL, Node *r = NULL) {
		data = d;
		leftChild = l;
		rightChild = r;
	}
};

Node *root = NULL;

class BST {
public:
	void insert(int d);
	void preOrder(Node *root);
	void inOrder(Node *root);
	void postOrder(Node *root);
	bool search(Node *root, int d);
	Node* findMin(Node *root);
	Node* findMax(Node *root);
	int findHeight(Node *root);
	int max(int x, int y);
	int levelOrder(Node *root);
	bool isBSTUtil(Node *root, int min, int max);
	bool isBST(Node *root);
	int leafCount(Node *root);
};
//Function to insert a node in BST
void BST::insert(int d) {
	Node *temp = new Node(d);
	Node *current = NULL, *parent = NULL;
	if (root == NULL)
		root = temp;
	else {
		current = root;
		while (1) {
			parent = current;
			//if value is less than root value then we insert at left of root
			if (d <= parent->data) {
				current = current->leftChild;
				if (current == NULL) {
					parent->leftChild = temp;
					return;
				}
			}
			//if value is greater than root value then we insert at right of root
			else {
				current = current->rightChild;
				if (current == NULL) {
					parent->rightChild = temp;
					return;
				}
			}
		}
	}
}
//DFS (Depth First Search) includes: 
//pre order traversal
//in order traversal
//post order traversal
//Function for preOrder traversal of tree
void BST::preOrder(Node *root) {
	if (root != NULL) {
		cout << root->data << "  ";
		preOrder(root->leftChild);
		preOrder(root->rightChild);
	}
}
//function for in Order traversal of tree
void BST::inOrder(Node *root) {
	if (root != NULL) {
		inOrder(root->leftChild);
		cout << root->data << "  ";
		inOrder(root->rightChild);
	}
}
//function for post order traversal of tree
void BST::postOrder(Node *root) {
	if (root != NULL) {
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		cout << root->data << "  ";
	}
}
//function to search any value in BST
bool BST::search(Node *root, int d) {
	if (root == NULL)
		return false;
	else if (root->data == d)
		return true;
	else if (d <= root->data)
		return search(root->leftChild, d);
	else
		return search(root->rightChild, d);
}
//function to find minimum value in BST
Node* BST::findMin(Node *root) {
	if (root == NULL) {
		cout << "Invalid: Tree is Empty" << endl;
		return root;
	}
	else {
		while (root->leftChild != NULL) {
			root = root->leftChild;
		}
		return root;
	}
}
//function to find maximum value in BST
Node* BST::findMax(Node *root) {
	if (root == NULL) {
		cout << "Invalid: Tree is Empty" << endl;
	}
	else {
		while (root->rightChild != NULL) {
			root = root->rightChild;
		}
		return root;
	}
}
//Function to find maximum of two values. we are writing this method because we need this in findHeight method.
int BST::max(int x, int y) {
	return (x > y) ? x : y;
}
//Height of a tree is the number of edges in longest path from the node to a leaf node.
//Height of a tree with no node(if allowed) is -1.
//Height of a tree with 1 node is zero.
//so the height of a tree will be maximum of left and right subtree + 1.
int BST::findHeight(Node *root) {
	if (root == NULL)
		return -1;
	else {
		int leftHeight = findHeight(root->leftChild);
		int rightHeight = findHeight(root->rightChild);
		
		return max(leftHeight, rightHeight) + 1;
	}
}
//Level Order Traversal is also called is BFS. To do this we will use Queue. The algorithm is as follow:
//1-Enqueue root node 
//2-visit it, display it, dequeue it and enqueue all of its children
//3-Repeat step 1 & 2 until queue is not empty
int BST::levelOrder(Node *root) {
	if (root == NULL) {
		cout << "Invalid: Empty tree!" << endl;
		return -1;
	}
	else {
        //as we have used STL so to create queue we use following syntax:
		queue<Node *>Q;
		//first we will push root in queue
		Q.push(root);
		while (!Q.empty()) {
			//storing the front element in current
			Node *current = Q.front();
			//removing the front element.
			Q.pop();
			//displaying value
			cout << current->data << "  ";
			//if left child is not empty then push it in queue
			if (current->leftChild != NULL)
				Q.push(current->leftChild);
			//if right child is not empty then push it in queue
			if (current->rightChild != NULL)
				Q.push(current->rightChild);
		}
	}
}
//BST Utililty function. we are writing this method because we need this in finding whether tree is BST or Not.
bool BST::isBSTUtil(Node *root, int min, int max) {
	if (root == NULL)
		return true;
	if (root->data<min || root->data>max)
		return false;

	return isBSTUtil(root->leftChild, min, root->data) && isBSTUtil(root->rightChild, root->data, max);
}
//Function that returns true if tree is bst and false otherwise.
bool BST::isBST(Node *root) {
	//INT_MAX is a macro that specifies that an integer variable cannot store any value beyond this limit.
	//INT_MIN specifies that an integer variable cannot store any value below this limit.
    //Values of INT_MAX and INT_MIN may vary from compiler to compiler.Following are
	//typical values in a compiler where integer are stored using 32 bits.
	//Value of INT_MAX is + 2147483647.
	//Value of INT_MIN is - 2147483648.

	return isBSTUtil(root, INT_MIN, INT_MAX);
}
//function to count leaf nodes in BST
int BST::leafCount(Node *root) {
	if (root == NULL)
		return 0;
	else if (root->leftChild == NULL && root->rightChild == NULL)
		return 1;
	else
		return leafCount(root->leftChild) + leafCount(root->rightChild);
}
void display() {
	cout << "\n\t";
	cout << "The data you want to store in BST must be in integer form!" << "\n\n";
	cout << "\t\tSelect Your Option:" << endl;
	cout << "\t\t===================\n" << endl;
	cout << "1. Insertion is BST" << endl;
	cout << "2. Pre Order Traversal of Tree" << endl;
	cout << "3. In Order Traversal of Tree" << endl;
	cout << "4. Post Order Traversal of Tree" << endl;
	cout << "5. Search a value in BST" << endl;
	cout << "6. Find Minimum value in BST" << endl;
	cout << "7. Find Maximum value in BST" << endl;
	cout << "8. Find Height of BST" << endl;
	cout << "9. Level Order Traversal(BFS) of BST" << endl;
	cout << "10. Check whether a tree is BST or Not" << endl;
	cout << "11. Counts the leaf Nodes in BST" << endl;
}
int main() {
	BST t;
	bool exit = true;
	int option;
	int num;
	do {
		system("CLS");
		display();
		cout << "\n";
		cin >> option;
		if (option >= 1 && option <= 12) {
			switch (option) {
			case 1: {
				cout << "Enter value to insert:";
				cin >> num;
				t.insert(num);
				cout << "Value Inserted!!" << endl;
				break;
			}
			case 2: {
				cout << "Pre Order Traversal is: ";
				t.preOrder(root);
				cout << endl;
				break;
			}
			case 3: {
				cout << "In Order Traversal is: ";
				t.inOrder(root);
				cout << endl;
				break;
			}
			case 4: {
				cout << "Post Order Traversal is: ";
				t.postOrder(root);
				cout << endl;
				break;
			}
			case 5: {
				cout << "Enter value to find:";
				cin >> num;
				if (t.search(root, num) == true)
					cout << "Value Founded in BST!" << endl;
				else
					cout << "Value not Founded in BST!" << endl;
				break;
			}
			case 6: {
				cout << "Minimum value in BST : ";
				Node *temp = t.findMin(root);
				if (root == NULL)
					break;
				else
				cout << temp->data << endl;
				break;
			}
			case 7: {
				cout << "Maximum value in BST : ";
				Node *temp = t.findMax(root);
				if (root == NULL)
					break;
				else
					cout << temp->data << endl;
				break;
			}
			case 8: {
				cout << "Height of BST is: " << t.findHeight(root) << endl;
				break;
			}
			case 9: {
				cout << "Level Order Traversal(BFS) is: ";
				t.levelOrder(root);
				cout << endl;
				break;
			}
			case 10: {
				if (t.isBST(root) == true)
					cout << "Tree is BST!" << endl;
				else
					cout << "Tree is not BST!" << endl;
				break;
			}
			case 11: {
				cout << "Leaf Nodes in BST : ";
				cout << t.leafCount(root) << endl;
				break;
			}
			default:
				break;
			}
		}
		else {
			cout << "Invalid Option Selected!!!" << endl;
		}
		char choice;
	here:
		cout << "Do you want to continue?  (y / n):";
		cin >> choice;
		if (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y') {
			cout << "Invalid choice!" << endl;
			cout << "Please Select 'y' for yes and 'n' for no" << endl;
			goto here;
		}
		else if (choice == 'n' || choice == 'N')
			exit = false;
	} while (exit);

	system("pause");
	return 0;
}