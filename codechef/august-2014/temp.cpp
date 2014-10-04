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






ll gcd(ll a,ll b) {
    return b==0?a : gcd(b,a%b);
}

int main(){
    ll fac = 1;
    for(int i=1;i<=10;i++) fac *= i;
    ll ans =1;
    for(int i=100;i>=100-10+1;i--){
        ll t = i;
        ll d = gcd(t,fac);
        t/= d;
        fac/=d;
        ans *= t;
    }
    cout << ans<<endl;
    return 0;
}





