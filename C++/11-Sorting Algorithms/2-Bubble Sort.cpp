//Bubble Sort.
//Time Complexity: O(n^2)
//Space Complexity: O(1) auxiliary
// Stable-> Yes
// inPlace-> Yes


#include<iostream>
using namespace std;

//declarations of functions that will be used in program 
void bubbleSort(int arr[], int size);
void swap(int *a,int *b);
void input(int arr[],int size);
void display(int arr[],int size);


int main() {
	//input size of array
	int size;
	cout << "Enter Size of Array:";
	cin >> size;
	
	//allocation of memory on heap
	int *arr = new int[size];
	
	//input values
	input(arr, size);
	
	//bubble sort
	bubbleSort(arr, size);
	
	//display values
	display(arr, size);
	
	//de-allocation memory
	delete[] arr;

	system("pause");
	return 0;

}

//function for bubble sort
void bubbleSort(int arr[], int size) {
	for (int outer = 0; outer < size; outer++) {
		for (int inner = 0; inner < size - 1; inner++) {
			if (arr[inner] > arr[inner + 1]) {
				swap(&arr[inner], &arr[inner + 1]);
			}
		}
	}
	cout << "\n\n";
}

//function that takes input in an array
void input(int arr[],int size) {
	cout << "Enter "<<size<<" values :" << endl;
	for (int i = 0; i < size; i++)
		cin >> arr[i];
}


//function to display array after bubble sort
void display(int arr[],int size) {
	cout << "Array after bubble sort:  ";
	for (int i = 0; i < size; i++) 
		cout << arr[i] << "  ";

	cout << "\n\n";
}

//function to swap to values
void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
