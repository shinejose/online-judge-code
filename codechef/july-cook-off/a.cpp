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

int t ,n;
int a[100005];

set<int> cnt;

int main(){
    cin >> t ;
    for(int i=0 ;i<t;i++){
        cin >> n ;
        cnt.clear();
        for(int j=0;j<n;j++){
            cin >> a[i];
            cnt.insert(a[i]);
        }
        cout << cnt.size()<<endl;
    }
    return 0;
}
















