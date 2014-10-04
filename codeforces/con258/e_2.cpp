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
ll fac;
int prime[8]={2,3,5,7,11,13,17,19};
int factor[8];

map<ll,ll> poly;
map<ll,ll> added;

ll GCD(ll a,ll b) {
    return b==0? a : GCD( b, a %b );
}

void pre_second() {
    fac=1 ;
    for(int i=2;i<n;i++ ) fac *= i ;
    for(int i=0;i<8;i++){
        for(int j = prime[i]; n-1 >=j  ; j= j*prime[i])
            factor[i] += (n-1)/j;
    }
}

ll  second_part(ll s){
    ll ret=1;
    ll tfac = fac;
    for(ll i=s+1;i<=s+n-1;i++) {
        ll  t = i;
        if(tfac!=1) {
            ll d = GCD(t,tfac);
            t/=d ;
            tfac/=d;
        }
        ret = (ret * (t%P) ) % P;
    }
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
    pre_second();
    for(auto it =poly.begin();it!=poly.end();it++){
        if( it->first > s )  break;
        ret =( ret + it->second * second_part(s-it->first) + (1<<21)*P  ) % P ;
    }
    return ret;
}


int main(){
    cin >> n >>s ;
    for(int i=1;i<=n;i++)  cin >> f[i];
    first_part() ;
    cout << solve()<<endl;
    return 0;
}
