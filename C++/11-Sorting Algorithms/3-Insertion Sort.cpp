//Insertion Sort.
//Time Complexity: O(n^2)
//Space Complexity: O(1) auxiliary
// Stable-> Yes
// inPlace-> Yes

#include<iostream>
using namespace std;

//declarations of functions that will be used in program 
void input(int arr[], int size);
void display(int arr[], int size);
void insertionSort(int arr[], int size);
void swap(int *a, int *b);

int main() {
	//input size of array
	int size;
	cout << "Enter size of array:";
	cin >> size;

	//allocation of memory on heap
	int *arr = new int[size];

	//input values
	input(arr, size);

	//insertion sort
	insertionSort(arr, size);

	//display values
	display(arr, size);

	//de-allocation of memory
	delete[] arr;


	system("pause");
	return 0;
}

//function for insertion sort
void insertionSort(int arr[], int size) {
	int inner, outer;

	//here we start outer=1 because in insertion sort 0 index in considered to be sorted .
	for (outer = 1; outer < size; outer++) {
		inner = outer;
		while (inner > 0 && arr[inner - 1] > arr[inner]) {
			swap(&arr[inner - 1], &arr[inner]);

			inner--;
		}
	}
	cout << "\n\n";
}

//function to take input values in array
void input(int arr[], int size) {
	cout << "Enter " << size << " values in Array:" << endl;
	for (int i = 0; i < size; i++)
		cin >> arr[i];
}

//function to display array
void display(int arr[], int size) {
	cout << "Array after Insertion Sort:  ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << "  ";

	cout << "\n\n";
}

//function to swap two values
void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


