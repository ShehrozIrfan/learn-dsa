//Radix Sort.
//In this we will use count sort as well.
//Time Complexity: O(d*(n+k))
// where d is number of digits in maximum number. 'n' is the size of actual array. 'b' is the base.
//to understand vist:
// https://www.youtube.com/watch?v=Il45xNUHGp0&t=651s

#include<iostream>
using namespace std;

int maximum(int A[], int size);
void countSort(int A[], int size, int pass);
void radixSort(int A[], int size);

int main() {
	int size;
	cout << "Enter size of Array:";
	cin >> size;

	int *A = new int[size];

	cout << "Input " << size << " Values in Array:" << endl;
	for (int i = 0; i < size; i++) {
		cin >> A[i];

	}

	radixSort(A, size);

	cout << "Sorted Array is:";
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;

	delete[] A;



	system("pause");
	return 0;
}
//function that finds maximum in an array.
int maximum(int A[], int size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

void radixSort(int A[], int size) {
	int max = maximum(A, size);

	for (int pass = 1; max / pass > 0; pass = pass * 10) {
		countSort(A, size, pass);
	}

}

//Code for count sort.
void countSort(int A[], int size, int pass) {
	//as we are dealing with decimal no. system so base is 10 therefore we created an array of size 10
	int count[10] = { 0 };
	

	//to check how many times a value is repeated.We will increment every time the value is repeated.
	for (int i = 0; i < size; i++) {
		++count[(A[i] / pass) % 10];
	}

	//so to store each value at its range we are updating the count array. and we start from i=1.
	for (int i = 1; i < 10; i++) {
		count[i] = count[i] + count[i - 1];
	}

	//now we create another array B of actual size.
	int *B = new int[size];

	//this will place every value at its range and at right place. and the array is sorted.
	for (int i = size - 1; i >= 0; i--) {
		B[count[(A[i] / pass) % 10] - 1] = A[i];
		count[(A[i] / pass) % 10]--;
	}

	//now copy the array B into array A
	for (int i = 0; i < size; i++) {
		A[i] = B[i];
	}

	delete[] B;
}
