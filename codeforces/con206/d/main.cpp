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
char table[25 ][25];
int dp[25][25][4];
 int main(int argc,char** argv)
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++) 
			cin >> table[i][j];

	for(int i=0;i<n;i++) 
		for(int j=0;j< n;j++) 
		{
			if ( i== 0 && j==0 ) 
			{
				if( table[i][j] =='a'  ) 
				{
					dp[i][j][0] =1 ;
					dp[i][j][1] =0 ;
					dp[i][j][2] =1;
					dp[i][j][3] =0;
				}
				else if( table[i][j] == 'b') 
				{
					dp[i][j][0] =0 ;
					dp[i][j][1] =1 ;
					dp[i][j][2] =0;
					dp[i][j][3] =1;
				}
				else 
				{
				    for(int k=0;k<4;k++) 
						dp[i][j][k] =0 ;
				}
			}
			else 
			{

			}
		}

	return 0;
}

