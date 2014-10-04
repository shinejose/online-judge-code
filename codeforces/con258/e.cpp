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

const ll P = 1e9  + 7 ;


ll n,s;
ll f[25];
ll fac[20];

map<ll,ll> poly;
map<ll,ll> added;

ll EXGCD(ll a,ll b,ll *x,ll *y){
    if ( b ==0 ) {
        *x=1 , *y = 0 ;
        return a ;
    }
    ll d = EXGCD(b,a%b,x,y);
    ll xpi = *x;
    ll ypi = *y;
    *x = ypi ;
    *y = xpi - (a/b) *ypi;
    return d;
} 

void factorize(){
    fac[0] = 1;
    fac[1] = 1;
    for(int i=2;i<20;i++){
        fac[i]= fac[i-1] * i;
    }
}

ll  C(ll m,ll  k){
    ll ret=1;
    ll tfac = fac[k];
    
    for(ll i=m ;i >= m - (k-1)   ;i--) {
        ll  t = i;
        ret = (ret * (t%P) ) % P;
    }

    ll x,y;
    EXGCD(fac[k],P,&x,&y);
    ret = (ret * ((x%P+P)%P)   ) % P;
    return ret;
}


void  first_part() {
    poly[0] =1; poly[f[1]+1] =-1  ;
    for(int i=2;i<=n;i++){
        added.clear();
        for(auto it = poly.rbegin(); it != poly.rend() ;it++ ) {
            ll new_exp = it->first + (f[i]+1) ;
            if( poly.find(new_exp ) == poly.end()) 
                added[new_exp] = poly[it->first] * (-1);
            else
                poly[new_exp] = poly[it->first]*(-1) + poly[new_exp] ;
        }
        for(auto &it : added) poly[it.first] = it.second;
    }
}
ll solve(){
    ll ret=0;
    for(auto it =poly.begin();it!=poly.end();it++){
        if( it->first > s )  break;
        ret =( ret + it->second * C(s-it->first+n-1,n-1) + (1<<21)*P  ) % P ;
    }
    return ret;
}


int main(){
    cin >> n >>s ;
    for(int i=1;i<=n;i++)  cin >> f[i];
    factorize();
    first_part() ;
    cout << solve()<<endl;
    return 0;
}
