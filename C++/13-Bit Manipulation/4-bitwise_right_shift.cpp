	#include<bits/stdc++.h>
	using namespace std;
		int main()
		{
			int t;
			cin>>t;     
			while(t--)
			{
				int n,i;
				cin>>n>>i;
				//Right shift n by i bits i.e n=n/(2^i)
				cout<<n<<">>"<<i<<" = "<<(n>>i)<<endl;
			}
			return 0;
		}
