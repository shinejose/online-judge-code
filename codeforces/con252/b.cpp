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


int n,v;
int lleft[3003];
int mm;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> v;
    mm = -1;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b ;
        lleft[a] += b ;
        mm = max(mm, a);
    }
    int ans=0;
    for(int i=1;i <= mm+1;i++){
        if( i== 1) {
            int cur  = min(lleft[i],v) ;
            lleft[i] -= cur;
            ans +=cur;
        }
        else {
            int cur = min(lleft[i-1],v);
            int r = v-cur;
            int rr =  min(lleft[i],r);
            lleft[i] -= rr ;
            ans += cur + rr ;
        }
    }
    cout << ans <<endl;
    
    return 0;
}









