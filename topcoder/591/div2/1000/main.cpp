/*
 * 排序好skill
 * 枚举j （当前所有组合的和为j的个数)
 * skill[i]为Team 1 的最小值 ，符合条件2,3 的所有组合的和为j + skill的个数是d[j] 
 * 答案是枚举所有Team1 的最小值的个数之和
 */
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<memory.h>
#include<algorithm>
using namespace std;
const int m = 3060001;
long long dp[m];
class 
YetAnotherTwoTeamsProblem
{
	public:
		long long count(vector <int> skill)
		{
			long long ans= 0 ;
			sort(skill.begin(),skill.end());
			int sum = 0;
			for(auto &i  :skill) 
				sum +=i;
			int _max=0;
			memset(dp,0,sizeof(dp));
			dp[0] =1 ;

			for(int i =skill.size()-1;i>=0;i--) 
			{
				for(int j=_max;j>=0;j--) 
					if(dp[j]  ) 
					{
						dp[j+skill[i]] +=dp[j] ;
						if( 2* (j + skill[i]) >sum && 2*j < sum) 
							ans += dp[j] ;
					}
				_max+=skill[i];
			}
			return ans;
		}
};
int main(int argc,char** argv)
{
	return 0;
}

