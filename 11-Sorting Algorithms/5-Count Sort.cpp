//Count Sort.
//Count sort is not included in our course DSA(IT-207) but we are doing this because Shell Sort(included in our course) can not be implemented without
//count sort.
//Time Complexity: O(n+k)
//If you don't understand what is happening then see a video whose link is:
// https://youtu.be/pEJiGC-ObQE

#include<iostream>
using namespace std;

int max(int A[], int size);
void countSort(int A[], int size, int k);

int main() {
	int size;
	cout << "Enter size of Array:";
	cin >> size;
     
	int *A = new int[size];
	
	cout << "Input " << size << " Values in Array:" << endl;
	for (int i = 0; i < size; i++) {
		cin >> A[i];
	
	}
	
	int k;
	k = max(A, size);
	
	countSort(A, size, k);
	
	cout << "Sorted Array is:";
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;

	delete[] A;

	system("pause");
	return 0;
}

//function that finds maximum in an array.
int max(int A[], int size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

//Code for count sort.
void countSort(int A[], int size, int k) {
	//here 'k' is the maximum value in an array
	//here we created a new array of size k+1 and initialized it with 0.
	int *count = new int[k+1];
	//initializing the whole array with 0
	for (int i = 0; i < k+1; i++) {
		count[i] = 0;
	}

	//to check how many times a value is repeated.We will increment every time the value is repeated.
	for (int i = 0; i < size; i++) {
		++count[A[i]];
	}

	//so to store each value at its range we are updating the count array. and we start from i=1.
	for (int i = 1; i <= k; i++) {
		count[i] = count[i] + count[i - 1];
	}

	//now we create another array B of actual size.
	int *B = new int[size];

    //this will place every value at its range and at right place. and the array is sorted.
	for (int i = size - 1; i >= 0; i--) {
		B[--count[A[i]]] = A[i];
	}

	//now copy the array B into array A
	for (int i = 0; i < size; i++) {
		A[i] = B[i];
	}

	delete[] count;
	delete[] B;
}