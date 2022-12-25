/*
DSA Past Papar 2012
Q#4: Write C++ function bool isMaxHeap() (int A[], int size) to determine whether the array A is a Max heap or not . This function should return
true if the array A is a max heap and it should return false otherwise. You can assume that the indices of the array start at 1 (instead of 0)
*/
#include<iostream>
using namespace std;

bool isMaxHeap(int A[], int size);

int main() {
	int size;
	cout << "How many Values you wanna enter:";
	cin >> size;

	int A[size];

	cout << "Enter " << size << " values : " << endl;
	for (int i = 1; i <= size; i++)
		cin >> A[i];

	if (isMaxHeap(A, size) == true)
		cout << "Array is a Max Heap" << endl;
	else
		cout << "Array is not a Max Heap" << endl;


	system("pause");
	return 0;
}
bool isMaxHeap(int A[], int size) {
	//as we know that in max heap each parent node is greater than or equal to its child nodes.
	//so we check from root node and goes on until we reach the last node.

   int i=1;

   while(i<=size){
      
   if( A[i] >= A[2*i] && A[i] >= A[(2*i) + 1] ){

    i++;

	return true;  	

	 }
  
   else{
  
   	return false;
   }
 }
}
