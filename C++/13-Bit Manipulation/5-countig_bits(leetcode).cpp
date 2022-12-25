	#include<bits/stdc++.h>
		using namespace std;
		#define pb    			push_back
		#define vi	  			vector<int>
		#define setbits(x)		__builtin_popcountll(x)
		#define w(x)			int x; cin>>x; while(x--)
		vi vect;
		int main()
		{ 
			w(t)
			{
				int n;
				cin>>n;
				for(int i=0;i<=n;i++)
				{
					vect.pb(setbits(i));
				}
				for(auto i:vect)
				{
					cout<<i<<" ";
				}
				vect.clear();
			}
			return 0;
		}
