//Merge Sort
//Time Complexity: O(nlogn) in all best , average and worst case.
//Space Complexity: O(n) auxiliary
//Algorithmic Paradigm: Divide & Conquer
//Stable: yes
//In Place: No
//If you wanna understand how to do this then go to link given below:
// https://www.youtube.com/watch?v=jlHkDBEumP0&t=298s

#include<iostream>
using namespace std;

void MergeSort(int A[], int lb, int ub);
void merge(int A[], int lb, int mid, int ub);

int main() {
	int size;
	cout << "How many Values you wanna enter:";
	cin >> size;

	int *A = new int[size];

	cout << "Enter " << size << " values :" << endl;
	for (int i = 0; i < size; i++)
		cin >> A[i];

	MergeSort(A, 0, size-1); //here we pass size-1 remember. i have spent 2 hours on finding this run time error.Now the time is 12:45 am night.
	                         //and i have just found this bug. That i have to pass size-1 before i was passing only size.

	cout << "Sorted Array is: ";
	for (int i = 0; i < size; i++)
		cout << A[i] << "  ";
	cout << endl;

	delete[] A;


	system("pause");
	return 0;
}


void  MergeSort(int A[], int lb, int ub) {
	int mid;
	if (lb < ub) {
		mid = (lb+ub) / 2;
		MergeSort(A, lb, mid);
		MergeSort(A, mid + 1, ub);
		merge(A, lb, mid, ub);
	}
}

//function which merge the sub-arrays in sorted manner.
//This merge function is the back bone of Merge Sort
void merge(int A[], int lb, int mid, int ub) {
	int i = lb, j = mid+1, k = 0;
	int *B = new int[ub];

	//comparing the values and placing them in Array B in sorted order.
	while (i <= mid && j <= ub) {
		if (A[i] <= A[j]) {
			B[k] = A[i];
			i++;
		}
		else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	//Here we are checking if any values left in any one array after the exhausting of other array.
	//if left array is exhausted then place all the values left in right array as it is in Array B. 
	
		while (j <= ub) {
			B[k] = A[j];
			j++;
			k++;
		}
	
	//if right array is exhausted then place all the values left in left sub array as it is in Array B.

		while (i <= mid) {
			B[k] = A[i];
			i++;
			k++;
		}
	//copy the values from Array B into Array A(actual array)
	for ( i= lb ;  i <= ub; i++) {
		A[i] = B[i-lb];
	}	
}