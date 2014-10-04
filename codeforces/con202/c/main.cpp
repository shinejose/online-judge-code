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
	vector<int>a; 
	cin >> n ;
	long long sum =0 ; 
	long long _max =-1;
	for(int i=0;i<n;i++)
	{
		long long temp;
		cin >> temp ;
		sum += temp;
		_max = max(_max,temp) ;
	}
	long long ans = sum /(n-1) ;
	if(sum%(n-1) !=0) 
		ans ++;	
	ans = max(ans,_max);
	cout<< ans<<endl;
return 0;
}

