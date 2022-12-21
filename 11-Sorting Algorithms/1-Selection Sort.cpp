//Selection Sort.
//Time Complexity: O(n^2)
//Space Complexity: O(1) auxiliary
// Stable-> no
// inPlace-> Yes

#include<iostream>
using namespace std;

void SelectionSort(int A[], int size);
int Min(int A[], int size, int start);

int main() {
	int size;
	cout << "Enter size of Array:";
	cin >> size;

	int *A = new int[size];

	cout << "Enter values in array:" << endl;
	for (int i = 0; i < size; i++)
		cin >> A[i];

	cout << "Original values in Array :";
	for (int i = 0; i < size; i++)
		cout << A[i] << "  ";
	cout << "\n\n";
	SelectionSort(A, size);

	cout << "Sorted Array is:";
	for (int i = 0; i < size; i++)
		cout << A[i] << "  ";
	cout << endl;
	delete[] A;

	system("pause");
	return 0;
}

//function of selection sort
void SelectionSort(int A[], int size) {
	//here loc is the variable having index of minimum value
	int loc, temp;

	for (int i = 0; i <= size - 2; i++) {
		//firstly, it finds the index of minimum value and the swap it with the value at A[i]
		loc = Min(A, size, i);
		//swapping
		temp = A[i];
		A[i] = A[loc];
		A[loc] = temp;
	}
}

//function that finds the index of minimum value in an array.
int Min(int A[], int size, int start) {
	//here start is the starting index.
	int min,loc;

	min = A[start];
	loc = start;

	for (int i = start+1; i <= size - 1; i++) {
		if (min > A[i]) {
			min = A[i];
			loc = i;
		}
	}
	//we return the index of minimum value.
	return (loc);
}