//write a recursion function that will return sum of first n positive integers.
#include<iostream>
using namespace std;

int sum(int n) {
	if (n == 1)
		return 1;
	else
		return n + sum(n - 1);
}

int main() {
	int num;
	cout << "Enter a positive number:";
	cin >> num;
	if (num > 0)
		cout << "Sum of first " << num << " numbers is : " << sum(num) << endl;
	else
		cout << "Invalid input!!" << endl;
	system("pause");
	return 0;
}