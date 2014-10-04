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

const int MAXN = 100005;
int n,m,w;
int a[MAXN];

int water[MAXN];

bool check(ll ans){
    memset(water,0,sizeof(water));
    ll addedWater =0 ;
    ll moves =0;
    for(int i=0;i<n;i++){
        if(i-w >=0) addedWater -= water[i-w];
        if( addedWater + a[i] < ans ){
            water[i] = ans - addedWater - a[i];
            addedWater += water[i];
            moves += water[i];
        }
        if( moves  > m ) return false ;
    }
    if( moves> m ) return false;
    else return true; 
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >>w;
    for(int i=0;i<n;i++ ) cin >>a[i];


    ll ans ;
    for(ll l =1 , r = 1e9 +1e5 +10 , mid = (l+r) >>1 ; l<=r  ;  mid=(l+r) >>1 ) 
        if( check(mid) ) l = mid+ 1 ,ans = mid ; else r = mid -1 ;
    cout << ans <<endl ;
    return 0;
}









