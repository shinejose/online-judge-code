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


ll n,s;
ll f[25];

ll fac[20];

const ll P = 1e9  + 7 ;

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
int main(){
    cin >> n >>s ;
    for(int i=0;i<n;i++) cin >> f[i];
    factorize();
    ll ans =0 ;

    for(int i=0;i< (1<<n) ;i++){
        int count =0 ;
        for(int j = i; j ; j >>=1 ) if ( j&1)  count ++ ;
        ll  sgn =1 ;
        if( count &1 ) sgn =-1 ;
        ll a = s+n-1;
        ll b = n-1;
        for(int j = i,pos=0; j ; j>>=1,pos++  ) if(j &1) a-=(f[pos]+1);
        if( a >= b  )  ans = (ans + sgn*C(a,b)+P )%P; 
    }
    cout << ans <<endl;
    return 0;
}















