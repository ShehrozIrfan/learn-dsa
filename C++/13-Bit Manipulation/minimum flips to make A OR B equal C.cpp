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
Question: minimum number of flips required to make A OR B equal C
*/ 

int minFlips(int a,int b,int c)
{
	//check if ith bit is set or not
	
	int res=0,count=0;
	for(int i=0;i<=31;i++)
	{
		bool x=false, y=false, z=false;
		
		//check if ith bit is set or not
		if(a & (1<<i))
		  x=true;
		if(b & (1<<i))
		  y=true;
		if(c & (1<<i))
		  z=true;
		  
		if(z==false)
		{
			if(x==true && y==true)
			   count+=2;
			else if(x==true||y==true)
			   count++;
			   
		}
		else
		{
			if(x==false && y==false)
			   count++;
		}
		
	}
	return count;
	
	
}

int32_t main()
{
	//s_t_s();
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
      w(t)
      {
      	 int a,b,c;
      	 
      	 cin>>a>>b>>c;
      	 
      	 cout<<minFlips(a,b,c)<<endl;
      	 
	  }
	
	return 0;
}

