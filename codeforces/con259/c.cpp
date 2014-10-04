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


int m,n;

long double ans;



int main(){
    cin >> m >> n;
    ans = m;
    for(int i=1;i<m;i++){
        ans -=  pow((double)i/m,n);
    }
    cout.precision(10);
    cout << ans<<endl;
    return 0;
}





