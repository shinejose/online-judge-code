#include <cstdio>
#include <cmath> 
#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
ll  x,k;
vector<ll> ans;
map<ll,set<ll>> divisors;

void dfs(ll  depth,ll  x){
    if(ans.size()>=100000) return ;
    
    if(x==1 || depth == k){
        ans.push_back(x);
        return ; 
    }
    auto it = divisors.find(x);
    if( it == divisors.end()){
        set<ll> temp;
        for(ll  i=1;i*i<=x;i++){
            if(x%i==0){
                temp.insert(i);
                if(i*i != x)
                    temp.insert(x/i);
            }
        }
        divisors[x]=temp;
    }

    for(auto &i:divisors[x] ){
        dfs(depth+1,i);
        if(ans.size()>=100000) return ;
    }
  
}

int main(){
    cin >> x >>k ;
    dfs(0,x);
    for(auto &i:ans)
        cout << i << " ";

    return 0;
}
