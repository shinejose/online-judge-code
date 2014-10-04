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
const int MAXN=100005
int v[MAXN] ; 
vector<vector<int>> tree;
 int main(int argc,char** argv)
{
	int n;
	tree.clear();
	cin >> n;
    for(int i=0;i<n;i++) 
		cin>> v[i]; 
	for(int i=0;i<n-1;i++) 
	{
		int x,y ;
		cin >>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	
	return 0;
}

