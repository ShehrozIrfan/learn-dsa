//Sparse Matrix Implementation.
//This code includes:
//1-Convert a given matrix into a Sparse Matrix
//2-Check whether a given matrix is Sparse or not

#include<iostream>
using namespace std;

void createSparseMatrix(int** A, int r, int c);
bool isSparseMatrix(int **A, int r, int c);
void input(int **A, int r, int c);
void output(int **A, int r, int c);
void display();

//int **A -> this is how we can pass a 2-d array
void createSparseMatrix(int** A, int r, int c) {
	//first we will count the non-zero elements
	int size = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (A[i][j] != 0)
				size++;
	//the no. of columns in sparse matrix must be equal to no.
	//of non-zero elements in matrix A.
	//creating a new 2-D matrix dynamically
	int **sparseMatrix = new int*[3];
	for (int i = 0; i < 3; i++)
		sparseMatrix[i] = new int[size];

	//creating of a new matrix
	int k = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (A[i][j] != 0) {
				sparseMatrix[0][k] = i;
				sparseMatrix[1][k] = j;
				sparseMatrix[2][k] = A[i][j];
				k++;
			}
		}
	}
	//printing the sparse matrix
	cout << "Sparse matrix is:" << "\n\n";
	for (int i = 0; i < 3; i++) {
		if (i == 0)
			cout << "Row:    ";
		else if (i == 1)
			cout << "Column: ";
		else
			cout << "Value:  ";
		for (int j = 0; j < size; j++) {
			cout << sparseMatrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "\n\n";
	//deallocating 2-d array
	for (int i = 0; i < 3; i++) {
		delete[] sparseMatrix[i];
	}
	delete[] sparseMatrix;
}

bool isSparseMatrix(int **A, int r, int c) {
	int count = 0;
	//count number of zeros in the matrix
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (A[i][j] == 0)
				count++;

	//if number of zeros are greater than half of elements of
	//matrix then its a sparse matrix
	if (count > (r*c) / 2)
		return true;
	else
		return false;
}

//the implementation in main is made lengthy just to made console window user friendly.
//you can do the main implementation in simple way.
int main() {
	bool exit = true;
	int option;
	do {
		system("CLS");
		display();
		cin >> option;
		if (option >= 1 && option <= 2) {
			switch (option) {
			case 1: {
				cout << "\n";
				cout << "Enter Matrix!" << endl;
				int r, c;
				cout << "Enter rows: ";
				cin >> r;
				cout << "Enter columns: ";
				cin >> c;
				//Allocation of 2-D Array dynamically
				int **A = new int *[r];
				for (int i = 0; i < r; ++i)
					A[i] = new int[c];
				//input values in Matrix
				input(A, r, c);
				//diplaying the input Matrix
				output(A, r, c);
				//function call
				createSparseMatrix(A, r, c);

				//Deallocation of 2-d array created dynamically
				for (int i = 0; i < r; ++i)
					delete[] A[i];
				delete[] A;

				break;
			}
			case 2: {
				cout << "\n";
				cout << "Input Matrix!" << endl;
				int r, c;
				cout << "Enter rows: ";
				cin >> r;
				cout << "Enter columns: ";
				cin >> c;
				//Allocation of 2-D Array dynamically
				int **A = new int *[r];
				for (int i = 0; i < r; ++i)
					A[i] = new int[c];
				//input values in Matrix
				input(A, r, c);
				//diplaying the input Matrix
				output(A, r, c);
				//function call
				if (isSparseMatrix(A, r, c) == true)
					cout << "Matrix is a Sparse Matrix" << endl;
				else
					cout << "Matrix is not a Sparse Matrix" << endl;
				
				//Deallocation of 2-d array created dynamically
				for (int i = 0; i < r; ++i)
					delete[] A[i];
				delete[] A;

				break;
			}
			default:
				break;
			}
		}
		else {
			cout << "Invalid Option Selected !!" << endl;
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
	} while (exit == true);
	
	
	
	system("pause");
	return 0;
}
void display() {
	cout << "     S P A R S E     M A T R I X     I M P L E M E N T A T I O N !!!" << "\n";
	cout << "===================================================================>" << "\n";
	cout << "Select your option:" << "\n";
	cout << "1. Convert a Matrix into a Sparse Matrix" << "\n";
	cout << "2. Check whether a Matrix is Sparse Matrix or not" << "\n";
}
//Function to take input in Matrix
void input(int **A, int r, int c) {
	//input values in array
	cout << "Enter " << r * c << " values in Matrix:" << endl;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> A[i][j];
}
//Function to display Matrix
void output(int **A, int r, int c) {
	//displaying input values
	cout << "You entered the following Matrix:" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << A[i][j] << "  ";
		}
		cout << endl;
	}
}