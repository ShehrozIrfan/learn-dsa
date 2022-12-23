/*
DSA lab 1
Date: 12-04-19
Task 2:
Program to find smallest and largest number in array.
*/
#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"Enter size of array:";
	cin>>size;
	int arr[size];
	cout<<"Enter values in array:"<<endl;
	for(int i=0;i<size;i++){
		cout<<"Enter value "<<i+1<<" :";
		cin>>arr[i];
	}
	
	int max,min;
	max=min=arr[0];
	
	for(int i=0;i<size;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}
	cout<<"Maximum="<<max<<endl;
	cout<<"Minimum="<<min<<endl;
	return 0;
}
