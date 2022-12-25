//SUBLIME TEXT
#include<bits/stdc++.h>
//#define<windows.h>

//#include<ext.pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define ff    	   		first
#define ss    			second
#define int     		long long
#define pb    			push_back
#define					REP(i,n) for (int i=1;i<=n;i++)
#define mp    			make_pair
#define pii   			pair<int,int>
#define vi	  			vector<int>
#define vii 			vector<ii>
#define					endl  '\n'
#define mii   			map<int,int>
#define pqb   			priority_queue<int>
#define pqs				priority_queue<int,vi,greater<int> >
#define setbits(x)		__builtin_popcountll(x)
#define zrobits(x)		__builtin_ctzll(x)
#define mod             1000000007
#define inf				1e18
#define ps(x,y)			fixed<<setprecision(y)<<x
#define mk(arr,n,type)	type *arr=new type[n];
#define w(x)			int x; cin>>x; while(x--)
#define	FIO				ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI=3.141592653589793238460;
typedef std::complex<double> Complex;



/*Question:

Suzie came over to Monk's place today with a box of Monk's favorite cookies! But Monk has to play a game with her in order to win the cookies.
Suzie takes out N balls from her bag, each ball having an integer on it. All the integers are 32-bit. She places all these balls in a box and closes it. The game starts by Monk choosing an integer from 0 to 31, representing a bit position. It is called as Monk's chosen bit. Post this, Suzie draws 1 balls from the box randomly and notes the integers on them. The rule is simple, Monk wins if Monk's chosen bit is set in the binary representation of the drawn ball. Help Monk choose a bit that maximizes his probability of winning the game! If there are multiple bit positions having the same probability, choose the smallest one.

Input:
The first line consists of an integer T. T testcases follow. The first line of each testcase consists of an integer N.
In next N lines, each line will contain 1 integer denoting the integers on the ball.

Output:
For each testcase, print the answer in a single line.

Constraints:



SAMPLE INPUT 
1
4
2
4
2
8
SAMPLE OUTPUT 
1
Explanation
He chooses the bit at position 1.
*/

int32_t main()
{
	//s_t_s();
	w(t)
	{
		int n;
		cin>>n;
		int arr[n];
		REP(i,n) cin>>arr[i];
		
		int cnt;
		int res=0;
		
		for(int i=1;i<=n;i++)
		{
			cnt=(i) * (n-i+1);
			
			if(cnt%2)  res^=arr[i];
		}
		
		cout<<res<<endl;
	}
	return 0;
}
