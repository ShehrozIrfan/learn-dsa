#include<bits/stdc++.h>
using namespace std;
#define w(x)			int x; cin>>x; while(x--)
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
int main()
{  
      w(t)
      {
      	 int a,b,c;
      	 cin>>a>>b>>c;
      	 cout<<minFlips(a,b,c)<<endl;
	  }
	return 0;
}
