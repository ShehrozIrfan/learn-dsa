  #include<bits/stdc++.h>
  using namespace std;
  /*Question: check if an integer is power of two or not*/
  bool isPowerOf2(int n){
    if(n==0)
      return false;
    if((n&(n-1))==0)
      return true;
    return false;
  }
  int main()
  {
      int T;
      cin>>T;
      while(T--)
      {
          int n;
          cin>>n;
          cout<<isPowerOf2(n)<<endl;
      }
    return 0;
  }
