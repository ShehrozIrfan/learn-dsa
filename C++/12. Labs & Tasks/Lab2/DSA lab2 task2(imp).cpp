/*
Task: DSA lab
Date: 13-04-2019

Name             College Roll Number    University Roll Number
Shehroz Irfan           199                     024016
Nazim Ali               165                     024066
Shahbaz Ahmad           176                     024056
Hussnain                135                     024075
*/
//Question:
//Create an array of size(taken from user) then delete a number(taken from user) and then display the array.

#include<iostream>
using namespace std;
int main(){
	int size,delNum,counter=0;  
	
	// Input size of array
	cout<<"\n\t"<<"Enter the size of Array:";
	cin>>size;
	// array of size 'size' entered by the user.
	int arr[size];  
	// Input values in array.
	for(int count=0; count < size ; count++){
		cout<<"\t"<<"Enter value "<<count+1<<":";
		cin>>arr[count];
	}
	
	cout<<"\n\t"<<"Enter the number that you wanna Delete:";
	cin>>delNum;
	
	//Searching the occurance of deleted number in array
	for(int count=0; count < size; count++){
		if(arr[count]==delNum){
			counter++;
		}
	}
	
	if(counter==0){
		cout<<"\n\n\t"<<"Number not found in array."<<endl;
	}
	else if (counter==size){
		cout<<"\n\n\t"<<"All the values in array are deleted.";
	}
	else{
	
	//copy the array 'arr' into new array 'newArr' excluding the deleted number.
    int outIndex=0;
    int newArr[size-counter];
    for(int count=0; count < size; count++){
    	if(arr[count]!=delNum){
    		newArr[outIndex]=arr[count];
    		outIndex++;
		}
	}
	
	//displaying the new Array after deleting the number.
	cout<<"\n\n\t"<<"The new array after deleting Number "<<delNum<<" is:"<<endl;
	for(int count =0; count < (size-counter); count ++){
		cout<<"\t";
		cout<<newArr[count]<<endl;
	}
}
	return 0;
}
