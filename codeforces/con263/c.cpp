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
int n;
int a[300005];
ll  sum[300005];

map<pair<int,int>,int> gmap;
map<pair<int,int>,int> fmap;
map<pair<int,int>,int> f2map;

ll f(int l,int r) ;
ll f2(int l,int r) ;

ll g(int l,int r) {
    if( gmap.find ( make_pair(l,r) ) != gmap.end() )
        return  gmap[make_pair(l,r)];
    ll ans =0;
    ll ans2 =0 ;
    ans += sum[r] - sum[l-1];
    ans2 += sum[r] - sum[l-1];
    ans += f(l,r);
    ans2 += f2(l,r);
    return gmap[make_pair(l,r)] = max (ans,ans2);
}
ll g2(int l,int r) {
    ll ans =0;
    ans += sum[r] - sum[l-1];
    ans += f2(l,r);
    return ans;
}

ll f(int l,int r){
    if( fmap.find ( make_pair(l,r) ) != fmap.end() )
        return  fmap[make_pair(l,r)];
    if( l ==r ) return 0 ;
    ll ans =0;

    int mid = (l+r) /2 ;
    if( (r-l+1) %2 ==1 )
        mid --;
    ans += g(l,mid);
    ans += g(mid+1,r);
    return fmap[make_pair(l,r)] = ans;
}
ll f2(int l,int r){
    if( l ==r ) return 0;
    ll ans =0;
    int mid = l;
    ans += g2(l,mid);
    ans += g2(mid+1,r);
    return  ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n ;
    for(int i=1;i<=n;i++) cin >> a[i] ;
    sort(a+1,a+n+1);
    sum[0] = 0; 
    for(int i=0;i<=n;i++) sum[i] = sum[i-1] + a[i];
    cout << g2(1,n) <<endl;
    return 0;
}









