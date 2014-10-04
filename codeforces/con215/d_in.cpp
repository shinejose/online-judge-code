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








int main(){
    int n = 200000;
    int m = 100000;
    int p = 1;
    cout << n << " "  << m << " " << p<<endl;;
    for(int i=1;i<=n;i++){
        if( i %m ==0 )
            cout << m <<" " ;
        else 
            cout << i%m << " " ;
    }
    cout << endl;
    for(int i=1;i<=m;i++){
        cout << i << " " ;
    }
    cout << endl;
    return 0;
}





