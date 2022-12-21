//Shell Sort.
//Time Complexity:The time complexity of code below is: O(n^2)
//Time complexity of Shell Sort depends on gap sequence.Its best case time complexity is O(n* logn) and worst case is O(n* log2n).
//Space Complexity: O(1) auxiliary
// Stable-> No
// inPlace-> Yes

#include<iostream>
using namespace std;

void ShellSort(int A[], int size);

int main() {
	int size;
	cout << "Enter size of Array:";
	cin >> size;

	int *A = new int[size];
	cout << "Enter " << size << " values in Array:" << endl;
	for (int i = 0; i < size; i++)
		cin >> A[i];

	ShellSort(A, size);

	cout << "Sorted Array is:";
	for (int i = 0; i < size; i++)
		cout << A[i] << "  ";
	cout << endl;

	delete[] A;

	system("pause");
	return 0;
}


void ShellSort(int A[], int size) {
	//in shell sort the gap/interval is size of array / 2
	int gap = size / 2;

	while (gap > 0) {

		int j = 0;
		
		for (int i = gap; i < size; i++) {
		    //here we place the value at A[i] in temp
			int temp = A[i];
			//here we use 'j' variable because we don't want to alter/change the value of 'i' that is in the above loop
			
			//here we are not swapping the values in that manner that we are doing in previous algorithms.
			//but in shell sort look how we are swapping here...

			for (j = i; j >= gap && A[j - gap] > temp; j = j - gap) {
			
				A[j] = A[j - gap];
			
			}
			
			A[j] = temp;
		
		}
		
		//at the end of above loops the value of gap is reduced by gap/2
		gap = gap / 2;
	
	}
}
