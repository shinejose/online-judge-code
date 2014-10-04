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



const int MAXN = 1e9 + 5;
//SegmentTree st;

vector<int>x ;

vector<int> maxPos;
vector<int> dp;


struct Node
{
	int l,r;
	int val,min;
};
const int MAXST = 1000006 ;
Node st[MAXST*4] ; 
int nodex[MAXST] ;
int root =1;
#define LL(x) (((x)<<1)) 
#define RR(x) (((x)<<1)+1)
#define FF(x) (((x)>>1))

int create(int node,int l,int r,int val) 
{
	st[node].l = l;
	st[node].r = r;
	if(r - l == 1) 
	{
		st[node].min =  st[node].val = val;
		nodex[l] =node ;
		return st[node].min ;
	}
	st[node].min = min(
			create(LL(node),l,(l+r)>>1,val) , 
			create(RR(node),(l+r)>>1,r ,val) ) ;
}

void updateUp(int node,int val) 
{
	st[node].min = st[node].val = val;
	do
	{
		node = FF(node) ;
		st[node].min = min( st[LL(node)].min , st[RR(node)].min) ;
	}while(node);
}

int getMin(int node,int l,int r) 
{
	if(st[node].l == l && st[node].r == r) 
		return st[node].min;
	else if( st[LL(node)].r >= r ) 
		return  getMin(LL(node),l,r);
	else if( st[RR(node)] .l <= l ) 
		return  getMin(RR(node),l,r);
	else 
		return min(getMin(LL(node),l,st[LL(node)].r),getMin(RR(node),st[RR(node)].l,r)) ;
}

int main(int argc,char** argv)
{
	/*
	clock_t start,finish;
	double duration;
	start = clock();
	*/
	int n;
	cin>> n;
	for(int i=0;i<n;++ i) 
	{
		int temp;
		cin >> temp;
			x.push_back(temp);
	}
	sort(x.begin(),x.end()) ;
	x.resize(unique(x.begin(),x.end())-x.begin());
	int a,b;
	cin >>a >>b;
	int m = a-b ;
	maxPos.assign(m+1,2) ;
	n = x.size();
	for(int i=0;i<n;i++) 
	{
		int cur = x[i];
		if ( cur ==2) 
			continue;
		int start;
		if( b %cur) 
			start = cur-b%cur + b;
		else 
			start = b;
		for(int j=start;j<=a;j+=cur)
		{
			int pos = j -b; 
			maxPos[pos] = max(maxPos[pos],cur);
		}
	}
	fill(st,0);
	fill(nodex,0);
	dp.assign(m+1,0);
	create(1,0,m+1,MAXN) ; 
	//st.create(0,m+1,MAXN);
	//st.relaxMin(st.root);
	dp[m] = 0 ;
	//st.insert(m,dp[m]) ;
	updateUp(nodex[m],dp[m]);
	for(int i=m-1;i>=0;--i) 
	{
		int up =  i + maxPos[i]  -1  ;
		if( up >m) 
			up =m;
		//dp[i] = 1+ st.getMin(i+1,up+1) ;
		//st.insert(i,dp[i]) ;
		dp[i] = 1 + getMin(root,i+1,up+1);
		updateUp(nodex[i],dp[i]);
	}
	cout << dp[0]<< endl;
	/*
	finish =clock();
	duration  =(double) (finish-start) /CLOCKS_PER_SEC; 
	cout<<duration<<endl;
	*/
	return 0;
}

