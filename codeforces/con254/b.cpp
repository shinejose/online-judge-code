// c header 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <memory.h>
// c++ header
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
struct DisjointSets
{
	static const int MAXELEM = 1005;
	int father[MAXELEM];
	int rank[MAXELEM];
	DisjointSets()
	{
		for(int i=0;i<MAXELEM;i++)
		{
			father[i] = i;
			rank[i]=1;
		}
	}
	void Init()
	{
		for(int i=0;i<MAXELEM;i++)
		{
			father[i] = i;
			rank[i]=1;
		}
	}
	/*
	int  Find(int x)
	{
	if(x!=father[x])
	return father[x]=Find(father[x]);
	}
	*/
	int Find(int x)  
	{  
		int t=x;  
		int temp;  
		while(father[x]!=x)  
			x=father[x];  
		while(father[t]!=x)  
		{  
			temp=father[t];  
			father[t]=x;  
			rank[t]=1;  
			t=temp;  
		}  
		return x;  
	}  
	void Merge(int x,int y)
	{
		int fx=Find(x);
		int fy=Find(y);
		if(fx==fy)
			return;
		if(rank[fx]<rank[fy])
			father[fx] = fy;
		else
		{
			father[fy]=fx;
			if(rank[fx]==rank[fy])
				rank[fy]++;
		}
	}
};

int n,m;
DisjointSets ds;
int cnt[55];
int main(){
    ios::sync_with_stdio(false);
    cin >> n >>m ;
    ds.Init();
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >>y ;
        ds.Merge(x,y);
    }

    for(int i=1;i<=n;i++){
        cnt[ds.Find(i)]++;
    }
    ll num =0;
    for(int i=1;i<=n;i++){
        if(cnt[i]>0)
            num ++;
    }
    ll ans = (ll) pow(2,n-num);
    cout <<ans<<endl;
    
    return 0;
}









