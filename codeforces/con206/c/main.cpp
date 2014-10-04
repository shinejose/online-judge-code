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
const int MAXN = 1e5 +5;
int w[MAXN] ; 
long long sum[MAXN] ;
 int main(int argc,char** argv)
{
	int n,l,r,ql,qr;
	cin >> n >>l >>r >>ql>>qr;
	long long total=0;
	sum[0] = 0;
	for(int  i=1;i<=n;i++) 
	{
		cin >>w[i] ;
		sum[i]  = sum[i-1] + w[i];
		total+= w[i];
	} 

	long long ans = -1;
	for(int k=0;k<=n;k++) 
	{
		 long long temp = sum[k] * l + (total -sum[k]) *r ;
		 int left = k;
		 int right = n-k ;
		 if( left> right) 
			 temp +=(left-right -1 ) *ql;
		 else if ( left< right) 
			 temp +=(right  -left -1 ) *qr;
		 if( ans ==-1) 
			 ans = temp;
		 else 
			 ans = min(ans,temp);
	}
	cout<< ans<<endl;
	return 0;
}

