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

int n,v;
vector<int> ans;

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> v;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        bool sucess = false;
        for(int j=0;j<k;j++){
            int tmp;
            cin >> tmp;
            if( !sucess && tmp  < v ){
                ans.push_back(i+1);
                sucess = true;
            }
        }
    }
    cout << ans.size() <<endl;
    for( auto & it : ans ) cout << it << ' ';

    return 0;
}









