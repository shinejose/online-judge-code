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
#include <unordered_set> 
#include <map>
#include <unordered_map> 
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
#include <bitset>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;


const int MAXN = 100010;

int n;
ll a[MAXN];
ll dp[ MAXN];


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x ;
        scanf("%d",&x);
        a[x]++;
    }
    dp[1]= a[1] ;
    ll ans =-1;
    for(int i=2;i< MAXN ;i++){
        dp[i]  = max(dp[i-1] ,dp[i-2] + a[i]*i);
        ans = max(ans,dp[i]);
    }
    cout << ans <<endl;
    return 0;
}





