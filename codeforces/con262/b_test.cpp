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

int a ,b,c;
vector<ll> ans;

int s(ll x){
    int sum =0;
    while(x) {
        sum += x %10;
        x /=10;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> a >> b>>c;
    for(int i=1;i<=81;i++){
        ll  x = (double)b *pow(i,a)   + c  ;
        if( s(x) == i && x>0 && x < (ll)1e9 )
            ans.push_back(x);
    }
    cout << ans.size()<<endl;
    for( auto &it : ans ) cout << it << ' ';
    
    return 0;
}










