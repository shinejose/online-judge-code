#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<memory.h>
#include<algorithm>
using namespace std;
class
ConvertibleStrings
{
	public:
		int ans ;
		int flag[10];
		int mark[10]; 
		void dfs(string A,string B ,int depth) 
		{
			if(depth==9) 
			{
				int count = 0;
				int n = A.size() ;
				for(int i=0;i<n;i++) 
				{
					if(flag[A[i]-'A'] != B[i] -'A') 
						count ++;
				}
				ans = min(ans,count);
			}
			else 
			{
				for(int i=0;i<9;i++) 
				{
					if(mark[i]) 
						continue;
					flag[depth] =i; 
					mark[i] = 1;
					dfs(A,B,depth+1) ;
					mark[i] = 0;
					
				}
			}
		}
		int leastRemovals(string A, string B)
		{
			ans =200;
			memset(flag,0,sizeof(flag));
			memset(mark,0,sizeof(mark));
			dfs(A,B,0);
			return ans;
		}
};
int main(int argc,char** argv)
{
	string A,B; 
	while( cin >> A>>B) 
	{
		ConvertibleStrings test;
		cout << test.leastRemovals(A,B) <<endl;
	}
	return 0;
}

