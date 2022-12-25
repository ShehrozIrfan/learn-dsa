//DSA lab3
//Date:20-04-19
//create an array of 10 numbers and print it using both array and pointer notation.

#include<iostream>
using namespace std;
int main() {
	int arr[10] = { 10,20,30,40,50,60,70,80,90,100 };
	cout << "Printing values using Array Notation:" << endl;

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

	int *ptr;
	ptr = arr;
	cout << "Printing values using Pointer Notation:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << *ptr << endl;
		ptr++;
	}

	cout << "Printing address using Pointer Notation:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << ptr << endl;
		ptr++;
	}


	
	system("pause");
	return 0;
}