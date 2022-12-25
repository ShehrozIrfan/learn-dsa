//recursive function that returns the maximum among the n elements of an integer array.

#include<iostream>
using namespace std;

//function that returns maximum of two numbers.
int max(int x, int y) {
	return (x > y) ? x : y;
}
//function to find maximum in an array using recursion
int maxRec(int A[], int n) {
	if (n == 1)
		return A[0];
	else
		return max(A[n - 1], maxRec(A, n - 1));
}
int main() {
	int size;
	cout << "How many values you wanna enter:";
	cin >> size;
	int *A = new int[size];
	cout << "Enter " << size << " values in array: " << endl;
	for (int i = 0; i < size; i++)
		cin >> A[i];

	cout << "Maximum value in Array is: " << maxRec(A, size) << endl;

	delete[] A;

	system("pause");
	return 0;
}