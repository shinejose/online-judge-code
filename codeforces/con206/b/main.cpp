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
const int MAXN =1005;
int a[MAXN] ;
int b[MAXN] ;
 int main(int argc,char** argv)
{
	int c1,c2,c3,c4,n,m;
	cin >> c1>>c2>>c3>>c4;
	cin >> n >> m ;
	for(int i=0;i<n;i++) 
		cin >>a[i];
	for(int i=0 ;i<m;i++) 
		cin>> b[i];

	sort(a,a+n);
	sort(b,b+m) ;
	int ans =c4;
	ans =min(2*c3,ans );
	int temp =0 ;
	for(int i=0 ;i<  n;i++) 
		if( a[i] * c1 <  c2) 
			temp += a[i] *c1;
		else 
			temp +=c2;
	int temp2=0 ;
	for(int i=0 ;i< m;i++) 
		if( b[i] *c1 <c2) 
			temp2+=b[i] *c1;
		else 
			temp2+=c2;
	ans = min(temp+c3 ,ans) ;
	ans = min(temp2+c3,ans);
	ans = min(temp+temp2,ans) ;
	cout<<ans<<endl;

	return 0;
}

