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
#define sz(x) ((int) (x).size())

const int MX = 3001; 
const int MOD = 1e9+7;

int dp[MX][MX]; 
char chart[MX][MX]; 
int n,m;

void DP(int x,int y) 
{
	if(chart[x][y] != '#' ) 
		dp[x][y] = 1;
	for(int i=x;i<n;++i ,y =-1 ) 
		for(int j=y+1;j<m;++j) 
			if(chart[i][j] !=  '#' )
			{
				if(i == 0 ) 
					dp[i][j] = dp[i][j-1] ;
				else if( j==0) 
					dp[i][j] = dp[i-1][j] ; 
				else 
					dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD ;
			}
}

int main(int argc,char** argv)
{
	cin >> n >>m;
	for(int i=0;i<n;++i) 
		scanf ("%s ", chart[i ]);
	DP(0,1) ;
	long long A =dp[n-2][m-1];
	long long B =dp[n-1][m-2];
	fill(dp,0);
	DP(1,0) ;
	long long C =dp[n-2][m-1];
	long long D =dp[n-1][m-2];
	long long ans = (A*D%MOD-B*C%MOD + MOD)%MOD; 
	cout<<ans<<endl;
	return 0;
}

