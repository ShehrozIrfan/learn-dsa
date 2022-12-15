//Write a recursive function to calculate the factorial of a number a!

#include<iostream>
using namespace std;

int factorial(int n) {
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}
int main() {
    int n;
	cout << "Enter a number: ";
	cin >> n;
	if (n > 0)
		cout << "Factorial of " << n << " is: " << factorial(n) << endl;
	else
		cout << "Invalid Input!!" << endl;
	system("pause");
	return 0;
}