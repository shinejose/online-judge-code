// c header 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <memory.h>
// c++ header
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

typedef long long  ll;

int n,k;
int a[105];
int b[105];
const int shift = 120000;
int dp[105][shift*2];

int main(){
    cin >> n >> k ;
     for(int i=0;i<n;i++){
        scanf ("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    memset(dp,-1,sizeof(dp));
    dp[0][shift] = 0;
    dp[0][a[0]-k*b[0] + shift ]= a[0] ;
    for(int i=1;i<n;i++){
        for(int j=0;j<2*shift;j++){
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            int t = j - (a[i] - k*b[i]) ;
            if( t <0 || t >= 2*shift ) continue;
            if( dp[i-1][t] !=-1 ){
                dp[i][j] = max(dp[i][j],dp[i-1][t]+a[i]);
            }
        }
    }
    if ( dp[n-1][shift] ==0 )
        cout << -1 <<endl;
    else
        cout << dp[n-1][shift] <<endl;
    return 0;
}





