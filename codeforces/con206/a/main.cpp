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
int main(int argc,char** argv)
{
	int k,d;
	cin >> k>>d;
	if( d ==0 ) 
	{
		if(k==1) 
		{
			cout<<0<<endl;
		}
		else 
		{
			cout<<"No solution"<<endl;
		}
	}
	else 
	{
		cout<<d;
		for(int i=0 ;i< k-1;i++) 
			cout<<0;
		cout<<endl;
	}
	return 0;
}

