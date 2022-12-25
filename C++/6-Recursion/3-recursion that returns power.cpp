//Write a recursive function that returns the power a^n.
#include<iostream>
using namespace std;

int findPower(int b,int p) {
	if (p == 0)
		return 1;
	else
		return (b * findPower(b, p - 1));
}

int main() {
	int base, power;
	cout << "Enter base:";
	cin >> base;
	cout << "Enter power:";
	cin >> power;
	cout << base << "^" << power << " is : " << findPower(base, power) << endl;

	system("pause");
	return 0;
}