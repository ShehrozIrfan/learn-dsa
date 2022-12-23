//DSA lab3
//Date:19-04-19
// write a program that sorts an array of integers.

#include<iostream>
using namespace std;

void sortArray(int arr[]);
void printArray(int arr[]);
int main(){
	int arr[10];
	cout<<"Enter values:"<<endl;
	for(int i=0;i<10;i++){
		cin>>arr[i];
		
	}
    cout<<"Array before sorting:"<<endl;
    for(int i=0;i<10;i++){
    	cout<<arr[i]<<endl;
	}
	
	sortArray(arr);
	printArray(arr);
	
	return 0;
}
void sortArray(int arr[]){
	int temp;
	for(int i=0;i<10;i++){
		for(int j=0;j<9;j++){
			if(arr[j]>arr[j+1]){
			
			
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
	}
}
void printArray(int arr[]){
	cout<<"Array after sorting:"<<endl;
	for(int i=0;i<10;i++){
		cout<<arr[i]<<endl;
	}
}
