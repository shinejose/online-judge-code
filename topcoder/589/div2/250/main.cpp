#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<memory.h>
using namespace std;
class
GooseTattarrattatDiv2
{
	public:
		int getmin(string s) 
		{
			int flag[26];
			memset(flag,0,sizeof(flag));
			int max =-1 ;
			for(auto &i :s) 
			{
				flag[i-'a'] ++;
				if(flag[i-'a'] >max)
					max = flag[i-'a'] ;
			}
			return s.size() - max;
		}
};


int main(int argc,char** argv)
{

	return 0;
}

