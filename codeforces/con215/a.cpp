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
typedef unsigned long long ull;

int n,d;
int a[105];
int m;

int sum[105];
int ans;



int main(){
    cin >> n >> d;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> m;
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(i==0){
            sum[i] = a[i];
        }
        else
            sum[i] = sum[i-1] + a[i];
    }
    if( m <=n ){
        ans = sum[m-1] ;
    }
    else{
        ans = sum[n-1]- d * (m-n);
    }
    cout << ans<<endl;
    
    
    return 0;
}





