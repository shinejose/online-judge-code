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

const long  double PI = acos(-1.0);
const long double EPSILON = 2.7182818284590452353602874713527;

typedef long long ll;

const ll MOD  =1000000007; 

ll x,y,n;
ll f[105 ];
ll ans;

int main(){
    cin >> x>>y>>n;
    f[1] = (x + MOD)% MOD;
    f[2] = (y + MOD )%MOD;
    f[3] = (f[2] -f[1] + MOD  ) %MOD  ;
    for(int i=1;i<100;i++){
        if(i>=3) 
            f[i] =( f[i-1] -f[i-2]  + MOD )%MOD;
        // printf( "f[%d] = %lld\n",i,f[i]);
    }
    if(n% 6 == 0 ){
        ans = f[6] ;
    }
    else
        ans = f[n%6];
    cout <<ans;

    return 0;
}






