/* 
 * DP 
 *
 * d[i][p] = 第i个spaw在前p个格子符合条件的所有个数
 *        = d[i-1][j-1] ，假设符合条件的格子j，那么
 *        d[i-1][j-1] 表示 前i个spaw在前j-1格子，第i个spaw在j上 的个数
 *        对前 p个格子 符合的所有 j 求和 ,就等于 d[i][p] 
 *
 *
 * 
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
const long long MOD = 1000000007;
class FoxAndShogi
{
	public: 
		long long col(string str) 
		{
			string temp ;
			int n = str.size();
			vector<int> x ;
			for(int i=0;i<n;i++)
				if( str[i] != '.') 
				{
					temp.push_back(str[i]);
					x.push_back(i);
				}
			int t = temp.size();
			long long dp[51][51];
			memset(dp,0,sizeof(dp));
			if( t== 0 )
				return 1;
			for(int i=0;i<=n;i++)
				 dp[0][i] = 1;

			for(int i=1;i<=t;i++)
			{
				for(int p=1;p<=n;p++)
				{
					 int l,h;
					 if(temp[i-1]=='D') 
					 {
						 l=x[i-1]+1  ;
						 h = min(n - (t-i) , p ) ;
						 if(p>=l && p<=(n-(t-i))) 
						 dp[i][p] = dp[i][p-1] + dp[i-1][p-1];
					 }
					 else 
					 {
						 l = i;
						 h = min(x[i-1]+1,p);
						 if(p<=x[i-1] +1) 
						 dp[i][p] = dp[i][p-1] + dp[i-1][p-1];
						 else 
							 dp[i][p] = dp[i][p-1] ;
					 }
					 //for(int j=l;j<=h;j++)
					//	 dp[i][p] += dp[i-1][j-1]; 
				}
			}
			return dp[t][n]%MOD;
			

		}
		int differentOutcomes(vector<string> board) 
		{
			int n = board.size();
			string str;
			long long ans =1;
			for(int i=0;i<n;i++) 
			{
				str.clear();
				for(int j=0;j<n;j++)
				{
					str.push_back(board[j][i]);
				}
					ans = (ans * col(str) )% MOD;
			}
		    return ans%MOD;

		}
};
int main() 
{
	vector<string> board;
	FoxAndShogi test;
	char in [100][100] = 
	   {"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		"..................................................",
		"UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU",
		"..................................................",
		".................................................."};

   char in2 [100][100] = 	{
 "....D..",
 "U....D.",
 "D.D.U.D",
 "U.U...D",
 "....U..",
 "D.U...D",
 "U.U...."};
	for(int i=0;i<7;i++) 
	{
		string row = in2[i];
		board.push_back(row);
	}


	cout<< test.differentOutcomes(board)<<endl;
	
	return 0;
}
