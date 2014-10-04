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




ll t,n,k;
ll d[10];


int main(){
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n >> k >> d[1]  >>d[2] ;
        
        d[3] = d[1] + d [2] + d[2];
        if( d[1] > d[2] ) 
            d[4] = d[1] +(d[1]-d[2 ]);
        else
            d[4] = d[2] +(d[2]-d[1] );

        int sucess =0 ;

        int left = n - k;
        if(  left >= d[3] && (left -d[3]) % 3== 0 ){
            sucess =1 ;
        }
        if( left >= d[4] && (left-d[4]) %3 == 0 ){
            sucess =1 ;
        }
        
        if(sucess ){
            cout <<"yes"<<endl;
        }
        else
            cout << "no"<<endl;

    }
    return 0;
}










