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
class
RaiseThisBarn
{
	private:
	public:
		int calc(string str)
		{
			int n = str.size();
			int count =0 ;
			int ans =0 ;
			for(int i=0;i<n;i++) 
				if(str[i]=='c') 
					count ++;
			if(( count %2 ) != 0 ) 
				return 0;
			else 
			{
				int count2 =0 ;
				for(int i=0;i<n;i++)
				{
					if(str[i] =='c') 
						count2 ++;
					if( i <n-1 &&i>0  &&count2==count/2 && str[i] == '.' ) 
					{
						ans ++;
					}
				}
				return ans +1 ;
			}
		}
};

int main(int argc,char** argv)
{
	return 0;
}

