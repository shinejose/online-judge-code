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

int t;
string s;
const ll MOD = 1e9 + 7;

ll moduler_exp(ll a,ll b,ll m)
{
    ll ret = 1 ;
    for(ll i =b , base = a; i ; i>>=1 , base = (base*base)%m)
        if(i&1)
            ret = (ret * base)%m ;
    return ret;
}


int main(){
    ios::sync_with_stdio(false);
    cin >> t ;
    while (t--)
    {
        cin >> s;

        int length = s.size();

        
        ll ans =0;

        if( (length %2 ) == 0  )
        {
            for(int i=0;i<length;i+=2)
                ans = (ans + moduler_exp(2,i+1,MOD))  %MOD;
            
            int pos = length;
            for(int j=0;j<s.size();j++)
            {
                if(s[j] == 'r')
                    ans = (ans + moduler_exp(2,pos,MOD))%MOD;
                pos--;
            }
            ans = (ans +2 ) % MOD;
            
            ans = (ans - 1 +MOD )%MOD;
        }
        else
        {
            for(int i=1;i<length;i+=2)
                ans = (ans + moduler_exp(2,i+1,MOD))  %MOD;
            
            int pos = length;
            for(int j=0;j<s.size();j++)
            {
                if(s[j] == 'r')
                    ans = (ans + moduler_exp(2,pos,MOD))%MOD;
                pos--;
            }
            ans = (ans +2 ) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}









