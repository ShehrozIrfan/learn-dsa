//To check whether an array is a min heap or not

#include<iostream>
using namespace std;

bool isMinHeap(int A[], int size);

int main() {
	int size;
	cout << "How many Values you wanna enter:";
	cin >> size;

	int A[size];

	cout << "Enter " << size << " values : " << endl;
	for (int i = 1; i <= size; i++)
		cin >> A[i];

	if (isMinHeap(A, size) == true)
		cout << "Array is a Min Heap" << endl;
	else
		cout << "Array is not a Min Heap" << endl;


	system("pause");
	return 0;
}
bool isMinHeap(int A[], int size) {
	//as we know that in min heap each parent node is lesser than or equal to its child nodes.
	//so we start checking from root and goes on checking until we reach the last node.
   
   int i=1;
   
   while(i<=size){  
   
   if( A[i] <= A[2*i] && A[i] <= A[(2*i) + 1] ){
   
    i++;

	return true;  	

	 }

   else{

   	return false;

    }
  }
}
