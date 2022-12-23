/*
DSA lab 2
Date: 13-04-19
Task1:
write a program to input seven numbers in an array and display them.Also print in reverse order.
*/
#include<iostream>
using namespace std;
int main(){
	int arr[7];
	cout<<"Enter values:"<<endl;
	for(int i=0;i<7;i++){
		cout<<"Enter value "<<i+1<<" :";
		cin>>arr[i];
	}
	
	cout<<"Values in actual order:"<<endl;
	for(int i=0;i<7;i++){
		cout<<arr[i]<<endl;
	}
	cout<<"Values in reverse order:"<<endl;
	for(int i=6;i>=0;i--){
		cout<<arr[i]<<endl;
	}
	return 0;
}
