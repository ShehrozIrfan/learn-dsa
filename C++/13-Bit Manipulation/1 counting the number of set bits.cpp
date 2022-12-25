//Ceck ith bit is set or not

#include<bits/stdc++.h>
//#define<windows.h>
//prime fctorization  
//#include<ext.pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ff    	   		first
#define ss    			second
#define ll      		long long
#define pb    			push_back
#define					REP(i,n) for (int i=1;i<=n;i++)
#define mp    			make_pair
#define pii   			pair<int,int>
#define vi	  			vector<int>
#define vii 			vector<pii>
#define					endl  '\n'
#define mii   			map<int,int>
#define pqb   			priority_queue<int>
#define pqs				priority_queue<int,vi,greater<int> >
#define setbits(x)		__builtin_popcountll(x)
#define zrobits(x)		__builtin_ctzll(x)
#define mod             1000000007
#define INF				1000000000
#define ps(x,y)			fixed<<setprecision(y)<<x
#define mk(arr,n,type)	type *arr=new type[n];
#define w(x)			int x; cin>>x; while(x--)
const double PI=3.141592653589793238460;
typedef std::complex<double> Complex;


/*
 Question:
 Write a function that takes an unsigned integer and return the number of '1' bits it has.
*/
int32_t main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
       
      w(t)
      {
      	int n;
      	
      	cin>>n;
         
        // cout<<setbits(n)<<endl;
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

