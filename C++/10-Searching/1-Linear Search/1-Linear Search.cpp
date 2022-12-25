// Linear Search
// Average number of comparisons will be (n+1)/2
// the worst case efficiency of this algorithm is O(n)

#include<iostream>
using namespace std;

void seqSearch(int A[], int size, int key);
int main() {
	int size;
	cout << "Enter size of Array:";
	cin >> size;

	int *A = new int[size];

	cout << "Enter values in Array:" << endl;
	for (int i = 0; i < size; i++) {
		cin >> A[i];
	}
	int key;
	cout << "Enter Number to find:";
	cin >> key;

	seqSearch(A, size, key);

	delete[] A;

	system("pause");
	return 0;
}

void seqSearch(int A[], int size, int key) {
	bool flag = 1;
	for (int i = 0; i < size; i++) {
		if (A[i] == key) {
			flag = 0;
			cout << "search successfull" << endl;
		}
	}
	if (flag == 1)
		cout << "Search Unsuccessful" << endl;
}