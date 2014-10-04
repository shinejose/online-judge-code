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
int n,m,a,b;

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >>a >>b;
    int temp =0;
    int ans = 1e8;
    for(int i=0;i<=n;i++){
        int y = (n-i) /m ;
        if( ((n-i) % m ) != 0 ) y ++ ;
        temp = i * a + y * b ;
        if( temp < ans )
            ans = temp;
    }
    cout << ans <<endl;
    return 0;
}









