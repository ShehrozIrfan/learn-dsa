//Quick Sort (Partition-Exchange Sort)
//Time Complexity:   O(n^2) | best or average case: O(nlogn)
//Space Complexity:  O(logn)
//Stable: No
//In-Place: Yes
//Algorithmic Paradigm: Divide & Conquer
//To understand watch the video on link given below:
// https://www.youtube.com/watch?v=QN9hnmAgmOc

#include<iostream>
using namespace std;

void QuickSort(int A[], int lb, int ub);
int partition(int A[], int lb, int ub);
void swap(int *a, int *b);

int main() {
	int size;
	cout << "How many Values you wanna enter:";
	cin >> size;

	int *A = new int[size];

	cout << "Enter " << size << " values:" << endl;
	for (int i = 0; i < size; i++) {
		cin >> A[i];
	}
	
	QuickSort(A, 0, size - 1);

	cout << "Sorted Array is:";
	for (int i = 0; i < size; i++)
		cout << A[i] << "  ";
	cout << endl;

	delete[] A;

	system("pause");
	return 0;
}

//Function for quick sort.
void QuickSort(int A[], int lb, int ub) {
	if (lb < ub) {
		int loc;   //loc is a variable that will store the end value index.
		loc = partition(A, lb, ub);
		QuickSort(A, lb, loc - 1);     //Recursive call
		QuickSort(A, loc + 1, ub);     //Recursive call
	}
}

//Function to swap two array values
void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//The partition function is the back bone of quick sort.
int partition(int A[], int lb, int ub) {
	int pivot, start, end;
	pivot = A[lb];  //here we select first element of array as pivot. but it depends on you , you can select any element as pivot.
	start = lb;
	end = ub;
	while (start < end) {

		//placing all the values <= pivot at left
		while (A[start] <= pivot) {
			start++;
		}
		//placing all the values > pivot at right
		while (A[end] > pivot) {
			end--;
		}

		//when start is less than end then swap start & end.
		if (start < end) {
			swap(&A[start], &A[end]);
		}
	}
	//this will run only when start is not less than end. then in this case we will swap pivot and end.
	swap(&A[lb], &A[end]);
	
	//this function returns the end value index.
	return end;
}