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
int n;
int a[1005];

int main(){
    ios::sync_with_stdio(false);
    cin >> n ;
    for(int i=0;i<n;i++) cin >> a[i] ;

    int cur =-1;
    int count =0;
    int ones=0;
    for(int i=0;i<n;i++){
        if(a[i] == 1 && cur == -1 ) cur = i;
        if(a[i]==1 ) ones ++ ;
        if( cur == -1 ) continue;
        if( a[i] ==0  && a[i-1] == 1 ) {
            count  ++;
        }
        
    }
    if(a[n-1] == 0 ) count --;
    cout << max(ones + count,0)  <<endl;
    return 0;
}









