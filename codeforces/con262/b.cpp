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

const ll MAXX = 1e9;
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
    cin >> a >> b>>c;
    ans.clear();
    for(int i=1;i<=81;i++){
        ll i_a = 1;
        for(int j =0 ;j<a;j++)
            i_a  *= i;
        ll  x =b * i_a  + c  ;
        if(  s(x) == i && x> 0 && x <MAXX )
            ans.push_back(x);
    }
    sort(ans.begin(),ans.end());
    cout << ans.size()<<endl;
    for( auto &it : ans ) cout << it << ' ';
    
    return 0;
}









