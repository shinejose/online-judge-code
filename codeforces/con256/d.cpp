#include <cstdio>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include  <vector>
#include <string>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
#include <map>

using namespace std;

typedef long long ll;
ll  n,m,k;

ll f(ll x ){
    ll ret =0;
    x--;
    for(int i=1;i<=n;i++){
        ret+= min(x/i,m);
    }
    return ret;
}

int main(){
    cin >> n>>m>> k ;


    ll   l =1;
    ll  r = m*n;
    while(l<=r){
        ll  x = (l+r)/2;
        if( f(x) <k  ) l = x+1;
        else r = x-1;
    }
    
    cout << l-1  <<endl;
    
    return 0;
}

