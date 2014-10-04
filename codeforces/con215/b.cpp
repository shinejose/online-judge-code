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

int n,m;
int a[100005];
int l[100005];

set<int> st;
int ans[100005];


int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&l[i]);
    }
    for(int i=n-1;i>=0;i--){
        st.insert(a[i]);
        ans[i]=st.size();
    }
    for(int i=0;i<m;i++){
        cout << ans[l[i]-1] <<endl;
    }

    return 0;
}





