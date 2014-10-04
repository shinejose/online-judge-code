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
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;

vector<vector<int>> ans;
vector<int> temp;
int n,k,d;

void dfs(int depth){
    if(ans.size() >= n )
        return;
    if(depth==0) {
        ans.push_back(temp);
        return; 
    }
    for(int i=1;i<=k;i++){
        temp.push_back(i);
        dfs(depth-1);
        temp.pop_back();
    }
}

int main(){
    cin >>n >> k>>d;

    if( k>=n) {
        for(int i=0;i<n;i++ ) cout << i+1 << ' ';
        cout <<endl;
        for(int i=1;i<d;i++ ) {
            for(int j=0;j<n;j++)
                cout << 1 << ' ';
            cout << endl;
        }
    }
    else {
        int mul = k;
        bool ok = false;
        for(int i=2;i<=d;i++){
            mul *= k;
            if( mul >= n ){
                ok = true;
                break;
            }
        }
        if(ok) {
            temp.clear();
            ans.clear();
            dfs(d);
            for(int i=0;i<d;i++){
                for(int j=0;j<n;j++){
                    cout << ans[j][i] << ' ';
                }
                cout << endl;
            }
        }
        else cout << -1 <<endl;
    }
    
    
    return 0;
}









