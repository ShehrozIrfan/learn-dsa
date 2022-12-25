#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		{
			cin>>arr[i];
		}
		int x=arr[0];
		for(int i=1;i<N;i++)
		{
			x=x | arr[i];
		}
		cout<<x<<endl;
	}
	return 0;
}
