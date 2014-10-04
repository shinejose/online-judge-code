#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<memory.h>
#include<algorithm>
#include<functional>
using namespace std;
#define fill(x,y) (memset(x,y,sizeof(x)))
const int MAXN = 100005; 
int a[ MAXN] ;
int  dp[MAXN] ;
int pos[MAXN] ;
int sum[MAXN] ;
 int main(int argc,char** argv)
{
	int n;
	cin >> n ;
	fill(sum,0) ;
	for(int i=1 ;i<= n;i++) 
	{
		cin >>a[i];
		sum[i]  = sum[i-1] + a[i];
	} 
	string str;
	cin >> str; 
	
	fill(dp,0);
	int last = 0;
	int lenstr = str.size();
	for(int i=1;i<=lenstr;i++) 
	{
		pos[i] = last;
		if(str[i-1] =='1') 
			last = i;
	}
	
	int ans = 0 ;
	for(int i=1;i<=lenstr;i++) 
		if (str [i-1] =='1') 
		{
			dp[i] = max ( sum[i-1] , a[i] + dp[pos[i]]) ;
			ans = max(dp[i] ,ans);
		}

	cout<< ans <<endl;

	return 0;
}

