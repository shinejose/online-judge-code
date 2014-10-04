// c header 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <memory.h>
// c++ header
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

typedef long long  ll;

ll n,m,q;

ll ans  ;

int main(){
    cin >> n >> m ;
    for(int i=0;i<m;i++){
        cin >> q;
        if( q < n +2 || q >  3*n )
            ans =0;
        else if( q <= 2*n +1 ){
            ans = q- (n+2) +1 ; 
        }
        else {
            ans = n - ( q - (2 *n +1 ))  ;
        }
        cout << ans<<endl;
    }
    return 0;
}





