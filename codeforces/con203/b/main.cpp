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
const int MAXN = 100005;
int a[MAXN] ,t[MAXN];
int outd[MAXN] ;
vector<int> hotel;
vector<int> path; 
vector<int> _max; 
int main(int argc,char** argv)
{
	int n;
	cin>> n; 
	for(int i=0;i<n;i++) 
		scanf("%d",&t[i+1]);
	for(int i=0;i<n;i++) 
		scanf("%d",&a[i+1]);
	fill(outd,0) ;
	for(int i=1 ;i<=n;i++) 
		if(a[i]!=0 ) 
		outd[a[i]]++;
	
	for(int i=1;i<=n;i++) 
		if(t[i] == 1 ) 
			hotel.push_back(i);
	int nh = sz(hotel) ;
	for(int i=0;i<nh;i++) 
	{
		int cur =hotel[i] ;
		path.clear();
		for(int j = cur;j!=0 ;j = a[j] ) 
		{
			path.push_back(j);
			if(outd[a[j]] >1) 
				break;
		}
		if(path.size() > _max.size() ) 
		{
			_max.clear();
			for( auto &k:path) 
				_max.push_back( k) ;
		}
	}
	cout<<_max.size()<<endl;
	for(int i=_max.size() -1;i>=0;i--) 
		cout<< _max[i]<<" ";
	cout<< endl;
	return 0;
}

