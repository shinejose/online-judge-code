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




ll t,x,y;
    



int main(){
    cin >> t ;
    for(int i=0;i<t;i++){
        cin >> x >> y;
        int sucess =0 ;
        if( (x >=1 && (x-1)%2 ==0 ) || (x <=0 && x%2 ==0) ) {
            ll n,a,b ;
            if( x>=1){
                n = (x-1 ) /2;
                a = 0 - 2 *n;
                b = 2 + 2 *n ;
            }
            else {
                n = x / -2;
                a = 0 - 2*n ;
                b = 0 + 2 *n ;
            }
            if( y >=a && y <=b ) sucess =1 ;
        }
        if(!sucess  &&  y%2 ==0)  {
            ll n ,a,b;
            if( y > 0 ){
                n = y /2 ;
                a = -1 - 2*(n-1) ;
                b = 0 + 2 *(n-1);
            }
            else {
                n = y/-2;
                a = -1 - 2*(n-1) ;
                b = 2 + 2*(n-1);
            }
            if( x >= a && x<=b ) sucess =1 ;
        }
        if( sucess ) cout << "YES\n"; else cout << "NO\n" ;
    }
    return 0;
}















