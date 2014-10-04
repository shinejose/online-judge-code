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
const int MAXN = 1e6+ 5 ;
int dp[MAXN] ;
int cnt[MAXN] ;
int pos[MAXN ] ;
int main(int argc,char** argv)
{
	string str;
	cin >> str;
	int lenstr = str.size();
	for(int i =0 ;i< lenstr;i++) 
	{
		if(str[ i ]=='F') 
		{
			if(i == 0 ) 
				cnt[i] =1 ;
			else 
				cnt[i] = cnt[i-1] +1 ;
			pos[i] =  i;
		}
		else 
		{
			if(i ==0 ) 
			{
				pos[i] = 0;
				cnt[i] = 0 ;
			}
			else 
			{
				pos[i]=pos[i-1] ;
				cnt[i]= cnt[i-1] ;
			}
		}
	}

	for(int  i=0 ;i<lenstr;i++) 
	{
		if(i ==0 ) 
		{
			dp[i] =0 ;
			continue;
		}
		if(str[i] == 'F') 
		{
			if( cnt[i] ==1) 
				dp[i] =   i -cnt[i-1]  ;
			else 
			{
				int lastdp  = dp[pos[i-1]] ;
				int lastf = i-pos[i-1] -1 ;
				int prelaststep = pos[i-1]-(cnt[pos[i-1]]- 1) ;
				int laststep = pos[i-1] +1 - cnt[i-1] ;
				int gap = lastdp-lastf - ( prelaststep  -1 ) ;
				if( lastdp > lastf )
				{
					if ( lastdp -lastf   == prelaststep -1 )  
						dp[i] = i-cnt[i-1]      ;
					else if (lastdp -lastf > prelaststep -1 ) 
						dp[i] =  lastf + gap  + laststep;
					else 
						dp[i] =   i -cnt[i-1 ]   ;
				}
				else 
					dp[i] =    i -cnt[i-1 ]  ;
			}
		}
		else 
			dp[i]= dp[i-1] ;
	}
	cout << dp[lenstr-1] <<endl;
	return 0;
}

