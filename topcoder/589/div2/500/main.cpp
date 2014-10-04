#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<memory.h>
using namespace std;
class 
GearsDiv2
{
	public:
		int getmin(string di)
		{
			int n =di.size();
			string di2;
			if(di[n-1] ==di[0]) 
			{
				int type =1; 
				for(int i=1;i<n;i++) 
					if(di[i]!=di[0])  
					{
						type =2 ;
						break;
					}
				if(type ==1) 
				{
					if(n==1) 
						return 0;
					else 
					{  
						if(n&1) 
							return n/2 +1 ;
						else 
							return n/2;
					}

				}
				else 
				{
					for(int i=0;i<n-1;i++) 
					{
						if(di[i]!=di[i+1]) 
						{
							for(int j=0;j<n;j++) 
								di2.push_back(di[(i+1+j)%n]) ;
							di = di2;
						}
					}
				}

			}
			int count =1 ;
			int ans =0;
			for(int i=0;i<n;i++) 
			{
				if( i==0) 
					continue;
				else 
				{
					if( di[i] == di[i-1])
						count ++;
					else 
					{
						ans += count /2;
						count =1 ;
					}
				}
			}
			if(count !=1 )
				ans +=count/2;
			return ans;
		}
};
int main(int argc,char** argv)
{

	string temp;
	GearsDiv2 test;
	while (cin>>temp) 
	{
		cout <<test.getmin(temp) <<endl;
	}
	return 0;
}

