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
int main(int argc,char** argv)
{

	int n ;
	cin >> n;
	int a[10] ;
	int _max = 1000000 ;
	int index ; 
	int r;
	for(int i=0;i< 9;i++) 
	{
		cin >> a[i] ;
		if(a[i] <=_max) 
		{
			_max = a[i];
			index = i+1;
		}
	}
	int num = n/_max;
	if(num == 0 ) 
	{
		cout<<"-1"<<endl;
	}
	else
	{
		int count =0;
		r = n % _max;
		while(1) 
		{
			int large =-1; 
			for(int i=0;i<9;i++) 
			{ 
				if(r+a[index-1] >= a[i] && i+1 >large ) 
					large = i+1 ;
			}
			if(large == index || r ==0 ) 
				break;
			cout<<large;
			r= r+_max - a[large-1] ;
			count ++;
		}
		for(int i=0;i<num-count;i++) 
			cout<<index;
		cout<<endl;
	}
	return 0;

}
