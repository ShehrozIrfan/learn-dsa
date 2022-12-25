	#include<bits/stdc++.h>
	using namespace std;
	#define w(x)			int x; cin>>x; while(x--);
	/*
	Question:
	Given an array arr[] of N integers, the task is to find the sum of all the pairs possible from the given array. Note that, 
	(arr[i], arr[i]) is also considered as a valid pair.
	(arr[i], arr[j]) and (arr[j], arr[i]) are considered as two different pairs.
	Examples: 
	Input: arr[] = {1, 2} 
	Output: 12 
	All valid pairs are (1, 1), (1, 2), (2, 1) and (2, 2). 
	1 + 1 + 1 + 2 + 2 + 1 + 2 + 2 = 12
	Input: arr[] = {1, 2, 3, 1, 4} 
	Output: 110 
	*/
	int main()
	{
		int n,m,res; 
		w(t)
		{
			cin>>n;
			vector<int>vect;
			for(int i=1;i<=n;i++)
			{
				cin>>vect[i];
			}
			for(int i=0;i<31;i++)
			{
				int cntZ=0, cnt1=0;
				
				for(int j=1;j<=n;j++)
				{
					if(vect[j] & (1<< i))
					cnt1++;
					else
					cntZ++;
				}
				int p=cntZ*cnt1;
				
				res+=(1<<i)*p;
			}
			cout<<res<<endl;
		}
		return 0;
	}
