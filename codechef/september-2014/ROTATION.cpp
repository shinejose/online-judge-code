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

int n,m;
int pos;
int a[100000+5];
int main(){
    ios::sync_with_stdio(false);
    pos =0 ;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++)
    {
        string cmd;
        int d;
        cin >> cmd >> d ;
        if( cmd == "C" )
        {
            pos  = (pos+d) %n;
        }
        else if (cmd == "A")
        {
            pos = (pos-d +n)%n;
        }
        else
        {
            cout << a[(pos-1+d)%n] <<endl;
        }
    }
    return 0;
}









