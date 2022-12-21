// Binary Search
// It works only on sorted Array
// Time Complexity : O(log base 2 n)

#include<iostream>
using namespace std;

void binSearch(int A[], int size, int key);
void sortArray(int A[], int size);

int main() {
	int size;
	cout << "Enter Size of Array:";
	cin >> size;

	int *A = new int[size];
	cout << "Enter values in Array:" << endl;
	for (int i = 0; i < size; i++)
		cin >> A[i];

	sortArray(A, size);
	cout << "Sorted Array is:" << endl;
	for (int i = 0; i < size; i++)
		cout << A[i]<<"  ";

	int key;
	cout << "\nEnter value to find:";
	cin >> key;

	binSearch(A, size, key);

    delete [] A;
    
	system("pause");
	return 0;
}
void sortArray(int A[], int size){
	int temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (A[j] > A[j + 1]) {
				temp = A[j];
				 A[j]= A[j + 1] ;

				 A[j + 1] = temp;
			}
		}
	}
}


void binSearch(int A[], int size, int key) {
	//here l=lower bound, u=upper bound , m=middle

	int l = 0;
	int u = size - 1;
	int m;
	while (l <= u) {
		m = (l + u) / 2;
		if (key == A[m]) {
			cout << "Search Successful \nValue found at index " << m << endl;
			return;
		}
		else if (key > A[m])
			l = m + 1;
		else
			u = m - 1;
	}

	cout << "Search Unsucsessful \nValue not found" << endl;
}
