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




int t,n,k,a[55];
int even[55] ;


int main(){
    cin >> t ;
    for(int i=0 ;i<t;i++){
        cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> a[i];
        even [0] = 0; for(int i=1;i<=n;i++)  if( a[i] %2 ==0 ) even[i] = even[i-1] +1 ; else even[i] = even[i-1] ;
        int sucess =0;
        for(int i=1; i<=n;i++) for(int j=1;i+j-1<=n;j++ ) if(even[i+j-1] -even[i-1] ==k ) sucess =1;
        if( sucess ) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}





