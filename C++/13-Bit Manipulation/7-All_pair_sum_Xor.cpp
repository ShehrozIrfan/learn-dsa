	#include<bits/stdc++.h>
	using namespace std;
	#define w(x)			int x; cin>>x; while(x--)
	/*Question: Given an array of n integers, find the sum of xor of all pairs of numbers in the array.
	Examples :
	Input : arr[] = {7, 3, 5}
	Output : 12
	7 ^ 3 = 4
	3 ^ 5 = 6
	7 ^ 5 = 2
	Sum = 4 + 6 + 2 
		= 12
	Input : arr[] = {5, 9, 7, 6}
	Output : 47
	5 ^ 9 = 12
	9 ^ 7 = 14
	7 ^ 6 = 1
	5 ^ 7 = 2
	5 ^ 6 = 3
	9 ^ 6 = 15
	Sum = 12 + 14 + 1 + 2 + 3 + 15
		= 47
	*/
	int main()
	{
		w(t)
		{
		int n;
		cin>>n;
		int res=0;
		for(int i=0;i<n;i++)
		{
			int m;
			cin>>m;
			res^=2*m;
		}
		cout<<res<<endl;
		}
		return 0;
	}