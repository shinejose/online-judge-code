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
struct temp
{
	int x,y;
};
temp a[105];
int main(int argc,char** argv)
{
	int n ;
	cin >> n;
	int sumu;
	int suml; 
	sumu =suml = 0 ;
	for(int i=0;i<n;i++) 
	{
		cin >> a[i].x;
		sumu += a[i] .x;
		cin >> a[i].y; 
		suml += a[i].y;
	} 
	int ans = -1   ;
	if( (sumu%2) == 0 && (suml%2)== 0 ) 
		ans =0 ;
	else if(  (sumu%2)==1  && (suml%2) ==1) 
	{
		for(int i=0;i<n;i++) 
			if( (a[i].x%2) ^ (a[i].y%2) ) 
			{
				ans =1;
				break;
			}
	}
	else 
		ans =-1;
	cout<< ans<<endl;

	return 0;
}

