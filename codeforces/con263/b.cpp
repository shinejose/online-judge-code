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
int n,k;
string card;
ll cnt[26];

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k >> card;
    int len = card.size();
    for(int i=0;i<len;i++) {
        cnt[card[i]-'A'] ++;
    }
    sort(cnt,cnt+26,[](const int &a,const int &b){
            return a >b ;
        });
    ll ans =0;
    ll left = k;
    for(int i=0;i<26;i++){
        if(  left > cnt[i]) {
            left -= cnt[i] ;
            ans += cnt[i] *cnt[i];
        }
        else {
            ans += left * left;
            break;
        }
    }
    cout <<ans<<endl;
    
    return 0;
}









