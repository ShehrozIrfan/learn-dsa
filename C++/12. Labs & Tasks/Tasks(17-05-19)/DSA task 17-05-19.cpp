//Task 17-05-19
//Finding factorial of a number 
// 1-> using loop
// 2-> using recursion

//using loop
//#include<iostream>
//using namespace std;
//int main(){
//	int no;
//	cout<<"Enter Number:";
//	cin>>no;
//	int fact=1;
//	for(int i=no;i>0;i--){
//		fact=fact*i;
//	}
//	cout<<fact;
//	return 0;
//}


//using recursion
#include<iostream>
using namespace std;

int fact(int n){
	//base condition
	if(n<=1)
	return 1;
	else
	return n*fact(n-1);
}

int main(){
	
	int n;
	cout<<"enter no:";
	cin>>n;
	fact(n);
	cout<<"Factorial:"<<fact(n)<<endl;
	return 0;
}


//finding sum of first 100 numbers using recursion.
//#include<iostream>
//using namespace std;
//
//int count(int n){
//	if(n==1)
//	return 1;
//	else
//	return n+count(n-1);
//}
//
//int main(){
//cout<<"Sum="<<count(100);
//
//	
//	return 0;
//}
