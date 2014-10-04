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
const int MX = 100005;
int d[MX*10];
 int main(int argc,char** argv)
{
	int n ,a,b;
	cin >> n;
	vector<int> x(n) ;
	for(int i=0;i<n;++i) 
		cin  >> x[i] ;
	cin>>a>>b;
	sort(x.begin(),x.end());
	x.resize(unique(x.begin(),x.end())-x.begin());
	n = x.size();
	for(int i=0;i<MX*10;++i) 
		d[i] = i-1;
	for(int i=0;i<n;++i) 
		for( int j=(b+x[i]-1)/x[i]*x[i] ; j<=a;j+=x[i] ) 
		{
			int pos = min(j+x[i]-b-1, a-b)  ;
			d[pos] = min(d[pos],j-b) ;
		}
	for(int i=a-b -1 ;i>=0;--i) 
		d[i] = min(d[i],d[i+1]);


    int ans =0 ;
	a-= b;
	while(a> 0) 
	{
		a= d[a];
		ans ++;
	}
	cout << ans<<endl;
	return 0;
}

