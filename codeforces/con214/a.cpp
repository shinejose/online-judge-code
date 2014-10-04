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

int n;
int a[4],b[4],c[4],d[4];
int ab[4],cd[4];



int main(){
    cin >> n;
    for(int i=0;i<4;i++){
        cin >> a[i] >> b[i] >> c[i]>>d[i] ;
        ab[i] = min(a[i],b[i]) ;
        cd[i] =min(c[i],d[i]) ;
    }
    int sucess =0;
    for(int i=0;i<4;i++){
        if( n >= ab[i] + cd[i] ){
            cout << i+1<< " " << ab[i] << " "<< n-ab[i] <<endl;
            sucess =1 ;
            break;
        }
    }
    if(sucess==0)
        cout << -1 ; 
    
    return 0;
}





