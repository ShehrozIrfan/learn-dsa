#include<bits/stdc++.h>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
      int t;
	  cin>>t;
      while(t--)
      {
      	int n,i;
      	
      	cin>>n>>i;
      	
      	//F=00000001  left shift F by i times and perform AND operation with N, if the result is 0 the the ith bit is not set else the ith bit is set
      	int f=1;
      	f=f<<i;
      	
      	int result=n & f;
      	
      	if(result==0)
      	  cout<<"ith bit is not set\n";
      	else
      	  cout<<"ith bit is set\n";
      	
      	
	  }
	
	return 0;
}

