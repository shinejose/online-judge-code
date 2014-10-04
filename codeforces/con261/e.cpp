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
#include <unordered_map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <iomanip>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;

const int MAXN=300005;

vector<pair<int,int>>  edges[MAXN];
int ne[MAXN];
int dp[MAXN];
int temp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int maxw =0;
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[w].push_back(make_pair(u,v));
        maxw = max(maxw,w);
    }
    ne[maxw] =-1;
    for(int i=maxw-1;i>=0;i--){
        if( edges[i+1].size() >0)
            ne[i] = i+1;
        else
            ne[i] = ne[i+1]; 
    }
    int ans=1;
    for(int i=ne[0];i!=-1 ;i=ne[i] ) {
            for(auto &vi: edges[i] ) temp[vi.second] =0;
            for(auto &vi: edges[i] )
                temp[vi.second] = max(temp[vi.second],dp[vi.first]+1) ;
            for(auto &vi: edges[i]){
                dp[vi.second]= max(dp[vi.second],temp[vi.second]);
                ans = max(ans,dp[vi.second]) ;
        }
    }
    cout << ans <<endl;
    return 0;
}









