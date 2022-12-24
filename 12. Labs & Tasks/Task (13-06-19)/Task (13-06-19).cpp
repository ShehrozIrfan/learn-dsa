//sum of first 100 natural numbers using recursion.

#include<iostream>
using namespace std;


int sum(int n){
	if(n!=0){
		return n+sum(n-1);
	}
}


int main(){
	
	int n=100;
		
	cout<<"Sum of first 100 Natural Numbers is: "<<sum(n)<<endl;

	return 0;
}
