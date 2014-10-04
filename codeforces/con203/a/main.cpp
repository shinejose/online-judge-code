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
int a[101];
int b[101];
int main(int argc,char** argv)
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++) 
		scanf("%d",&a[i]) ;
	for(int i=0;i<m;i++) 
		scanf("%d",&b[i]);

	sort(a,a+n);
	sort(b,b+m);
	for(int i=1;i<=101;i++) 
	{
		if(a[n-1]>i) 
			continue;
		if(a[0] *2 > i ) 
			continue;
		if( i>= b[0] ) 
			continue;
	    cout<< i<<endl;
		return 0;
	}
	cout<<"-1"<<endl;

	return 0;
}

