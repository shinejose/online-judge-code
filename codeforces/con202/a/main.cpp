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
stack<int> x;
stack<int> y;
int main(int argc,char** argv)
{
	int n;

	while( cin >> n )
	{
		int temp;
		for(int i=0;i<n;i++)
		{
			cin>> temp;
			if(temp == 25) 
				x.push(temp);
			else if (temp ==50) 
			{
				if(x.empty()) 
				{
					cout<<"NO"<<endl;
					return 0;
				}
				x.pop();
				y.push(temp);
			}
			else 
			{
				if(!y.empty())
				{
					temp -= 50;
					y.pop();
				}
				for(int j=0;j<3;j++) 
				{
					if ( temp ==25) 
						break;
					if(x.empty()) 
					{
						cout<<"NO"<<endl;
						return 0;
					}
					x.pop();
					temp -= 25;
				}
			}
		}
		cout<<"YES"<<endl;
	}
	return 0;
}

