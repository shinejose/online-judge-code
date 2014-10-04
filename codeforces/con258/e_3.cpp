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

ll GCD(ll a,ll b) {
    return b==0? a : GCD( b, a %b );
}

int prime[8]={2,3,5,7,11,13,17,19};
int factor[8];

void factorize(){
    fac[0] = 1;
    fac[1] = 1;
    for(int i=2;i<20;i++){
        fac[i]= fac[i-1] * i;
    }
}
void pre_second() {
    for(int i=0;i<8;i++){
        for(int j = prime[i]; n-1 >=j  ; j= j*prime[i])
            factor[i] += (n-1)/j;
    }
}    

ll  C(ll m,ll  k){
    ll ret=1;
    ll tfac = fac[k];

    int tfn=0;
    int tfactor[8];
    int tprime[8];
    for(int i=0;i<8;i++) {
        if( factor[i]) 
            tfactor[tfn++] = factor[i];
        tprime[i] = prime[i];
    }
    
    for(ll i=m ;i >= m - (k-1)   ;i--) {
        ll  t = i%P;
        for( int j=0;j<tfn;j++){
            while( t % tprime[j] == 0) {
                tfactor[j] --;
                t /= tprime[j];
                if(tfactor[j]== 0 ) {
                    if( j ==tfn-1 ) tfn-- ;
                    else {
                        swap(tprime[j],tprime[tfn-1]);
                        swap(tfactor[j],tfactor[tfn-1]) ;
                        tfn--;
                        j--;
                    }
                    break;
                }
            }
        }
        // if(tfac!=1) {
        //     ll d = GCD(t,tfac);
        //     t/=d ;
        //     tfac/=d;
        // }
        ret = (ret * (t%P) ) % P;
    }
    return ret;
}
int main(){
    cin >> n >>s ;
    for(int i=0;i<n;i++) cin >> f[i];
    factorize();
    ll ans =0 ;

    pre_second();
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















