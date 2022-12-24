//DSA Task (18-05-19)
//display first 100 natural numbers using recursion.

#include<iostream>
using namespace std;

void display(int n) {
	if (n <= 100) {
		cout << n << endl;
		display(n+1);
	}
}

int main() {
	display(1);



	system("pause");
	return 0;
}