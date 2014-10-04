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
const int MAXN = 2005;
int a[MAXN*2];
int b[MAXN*2] ;
int main(int argc,char** argv)
{
	int n;
	cin >> n;
	int sum =0;
	for(int i=0;i<n*2;i++) 
	{
		scanf("%d.%d",&a[i],&b[i]);
		sum +=b[i];
	}
	sort(b,b+2*n);
	int nz=0 ;
	for(int i=0;i<2*n;i++) 
		if(b[i] == 0) 
			nz++;
	int nn= 2*n-nz;
	double res = 20005;
	int ans;
	for(int i = min(nz,nn) ;i>=0;i--) 
	{
		int rest = 0 ;
		if( nn-nz >0) 
			rest = (nn-nz) /2  * 1000 ;
		ans =sum - i*1000 - rest;
		res = min(res,abs(ans)/1000.0);
	}
	printf("%.3f\n",res);
	return 0;
}

