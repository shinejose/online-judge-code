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

int n;
ll a[500005];
ll frontSum[500005];
ll ans;
unordered_map<ll,int> cnt;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)  scanf("%I64d",&a[i]);
    frontSum[0] = 0;
    for(int i=1;i<=n;i++)  
        frontSum[i] = frontSum[i-1] + a[i];
    ans =0 ;
    for(int i=n-1;i>=1;i--){
        if (frontSum[i] *3 == frontSum[n] ){
            if( cnt.find(frontSum[i]*2 )!= cnt.end() ) {
                ans += cnt[frontSum[i]*2] ;
            }
        }
        cnt[frontSum[i]] ++ ;
    }
    cout << ans <<endl;   
    return 0;
}









