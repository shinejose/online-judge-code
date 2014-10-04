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
WolfDelaymaster
{
	private:
	public:
		bool cut(string & str) 
		{
			int n =str.size();
			int d =0;
			for(int i=0;i< n;i ++) 
			{
				if(str[i] == 'w') 
					d ++;
				else 
					break; 
			}
			if(d == 0) 
				return false;
			for(int i=d;i<2*d;i++) 
				if(str[i] != 'o') 
					return false;
			for(int i=2*d; i<3*d;i++) 
				if( str[i] !='l') 
					return false;
			for(int i=3*d;i<4*d;i++) 
				if( str[i] !='f') 
					return false;
			str.erase(0,4*d) ;
			return true;
		}
		string check(string str)
		{
		    while(  cut(str ) && str.size() > 0) 
				;
			if( str.size() == 0  ) 
				return "VALID";
			else return "INVALID";
		}
};

int main(int argc,char** argv)
{
	WolfDelaymaster test;
cout <<	test.check("flowolf") <<endl;
	return 0;
}

