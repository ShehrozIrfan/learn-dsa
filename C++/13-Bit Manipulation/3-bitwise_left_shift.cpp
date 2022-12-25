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
				//Left shift n by i bits i.e mutiplying n by 2^i
				cout<<n<<"<<"<<i<<" = "<<(n<<i)<<endl;
			}
			return 0;
		}
