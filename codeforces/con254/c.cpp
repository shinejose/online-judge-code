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

int n,m;
int x[505];
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> x[i];
    double ans = 0.0;
    for (int i=0;i<m;i++){
        int a , b,c;
        cin >> a >>b >> c;
        ans = max(ans ,((double)x[a]+x[b] )/c );
    }
    cout.precision(15);
    cout << ans <<endl;
    
    return 0;
}









