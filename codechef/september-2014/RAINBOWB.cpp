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


const ll MOD = 1e9+7;

ll n;

ll gcd(ll a,ll b)
{
    return b==0? a: gcd(b,a%b);
}

ll C(ll n,ll m)
{
    if( n < m  )
        return 0;
    vector<ll> temp ;
    for(ll i=0;i<m;i++)
    {
        temp.push_back(n-i);
    }
    for(ll i=2;i<=m;i++)
    {
        ll left = i;
        for(ll j =0;j<temp.size();j++)
        {
            ll d = gcd(temp[j],left) ;
            if(   d > 1  )
            {
                temp[j] /= d;
                left /=d;
            }
            if(left ==1)
                break;
        }
    }
    ll ret =1;
    for(ll i=0;i<temp.size();i++)
    {
        ret = (ret * temp[i]) %MOD;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n ;
    ll ans = 0;
    for(ll a7 =1;a7<=n;a7++)
    {
        if((n-a7)%2==0)
        {
            ll left = (n-a7) /2;
            ans  = (ans+C(left-1,5)) %MOD ;
        }
    }
    cout << ans <<endl;
    return 0;
}









