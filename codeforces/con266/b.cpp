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
// c++11 header
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <thread>
#include <chrono>
#include <atomic>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;

ll gcd(ll a,ll b){
    return b==0 ? a : gcd( b ,a%b);
}
template<typename Integer>
Integer exgcd(Integer a,Integer b,Integer *x,Integer *y){
    if(b==0){
        *x = 1 ;
        *y = 0 ;
        return a;
    }
    else {
        Integer d = exgcd(b,a%b,x,y);
        Integer xpi = *x;
        Integer ypi = *y;
        *x = ypi;
        *y = xpi  - (Integer)(a / b )  * ypi ;  
        return d;
    }
}

ll n,a,b;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    ll ans =a *b;
    ll ansa =a  ;
    ll ansb =b ;
    if( a* b <  6 * n ){
        for(int i=0;i<a;i++){
            ll aa = b ;
            ll bb =  6*n - a*b - i;
            ll mm = a;
            ll x ,y;
            ll d = gcd(aa,mm);
            if( d ==1 ) {
                exgcd(aa,mm,&x,&y);
                ll xx = -bb * x;
                if( xx < 0) continue;
                ans = 6*n + i;
                ansa = a + xx;
                ansb = ans/ansa;
                if( ansa < a || ansb < b )
                    swap( ansa ,ansb) ;
                if( ansa < a || ansb < b )
                    continue;
                break;
            }
            if( b % d == 0 ){
                aa = aa / d ;
                bb = bb / d;
                mm = mm / d;
                
                exgcd(aa,mm,&x,&y);
                ll xx ;
                bool sucess =false ;
                for(int j=0;j<d;j++){
                    xx = -bb *x +  j*mm;
                    ans = 6*n + i;
                    ansa = a + xx;
                    ansb = ans/ansa;
                    if( ansa < a || ansb < b ){
                        swap( ansa ,ansb) ;
                        sucess =true;
                        break;
                    }
                    if( ansa < a || ansb < b )
                        sucess =false;
                }
                if(sucess)
                    break;
            }
        }
    }
    cout << ans <<endl;
    cout << ansa << " " << ansb <<endl;
    return 0;
}









