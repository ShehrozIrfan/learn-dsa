		#include<bits/stdc++.h>
		using namespace std;
		/*
		Question:
		Write a function that takes an unsigned integer and return the number of '1' bits it has.
		*/
		int main()
		{
			int t;
			cin>>t;
			while(t--)
			{
				int n;
				cin>>n;
				int count=0;
				while(n>0)
				{
					count++;
					n=n&(n-1);
				}
				cout<<"Number of Set bits: "<<count<<endl;
			}
			
			return 0;
		}