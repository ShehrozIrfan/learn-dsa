		#include<bits/stdc++.h>
		using namespace std;
		/*Question: given an integer.check if it's power of two or not*/
		int main()
		{
			int t;
			cin>>t;
			while(t--)
			{
				int n;
				cin>>n;
				if(n<=0)  
				  cout<<false;
				else if((n & (n-1))==0) 
				  cout<<true;
				else              
				  cout<<false;
			
			}
			return 0;
		}
