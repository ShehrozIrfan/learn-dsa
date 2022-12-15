//Write a recursive function that returns the sum of the squares of the first n positive integers.

#include<iostream>
using namespace std;

int sumOfSquares(int n) {
	if (n == 1)
		return 1;
	else
		return (n*n) + sumOfSquares(n - 1);
}

int main() {
	int num;
	cout << "Enter a positive number: ";
	cin >> num;
	if (num > 0)
		cout << "Sum of the squares of the first " << num << " integers is: " << sumOfSquares(num) << endl;
	else
		cout << "Invalid Input!!" << endl;

	system("pause");
	return 0;
}