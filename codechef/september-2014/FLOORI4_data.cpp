// c header 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <memory.h>
#include <ctime>
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
// c++11 header
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <thread>
#include <chrono>
#include <atomic>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;

int t;
int n;

int main(){
    ios::sync_with_stdio(false);
    srand(time(NULL));
    t  = 3000  ;
    cout << 3030 <<endl;
    for(int i=1 ;i<=t;i++){
        int n = rand() %1000000 +1 ;
        int m = rand() % 100000 +1 ;
        cout << n << " " << m << endl;
    }
    ll MAXN = 10000000000-1000000 ;
    t = 30;
    for(int i=1 ;i<=t;i++){
        ll n = rand() %MAXN +1  + 1000000 ;
        int m = rand() % 100000 +1 ;
        cout << n << " " << m << endl;
    }

    return 0;
}









