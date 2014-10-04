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


int n,m,k;

queue<pair<int,int>> ans;

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >>k;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int real ;
            if( i%2 == 1){
                real = j+1;
            }
            else {
                real = m-j;
            }
            ans.push(make_pair(i,real));
        }
    }
    for(int i=0;i<2*(k-1);i+=2){
        cout << 2 << ' ' ;
        pair<int,int> top = ans.front();
        ans.pop();
        cout  << top.first << ' '<< top.second <<' ';
        
        top = ans.front();
        ans.pop();
        cout  << top.first << ' '<< top.second <<' ';
        cout << endl;
    }
    cout << n*m -2*(k-1) << ' ' ;
    while(!ans.empty()) {
        pair<int,int> top = ans.front();
        ans.pop();
        cout  << top.first << ' '<< top.second <<' ';
    }
    cout << endl;
    
    return 0;
}









