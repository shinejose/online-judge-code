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
#include <unordered_set> 
#include <map>
#include <unordered_map> 
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
#include <bitset>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;


const int P = 1000000007;

int t,n;
bitset<100> tshirts[10];
ll dp[(1<<10)+5][105];

ll rec(int mask,int tid){
    if( mask == (1<<n)-1 )
        return dp[mask][tid] =1;
    if(tid==101)
        return 0;
    if(dp[mask][tid] != -1 )
        return dp[mask][tid] ;
    ll ans =0 ;
    ans = (ans +  rec(mask,tid+1) ) % P;
    for(int i=0;i<n;i++){
        if(tshirts[i][tid] && !(mask & (1 << i) )){
            ans = (ans + rec(mask | (1<<i),tid+1) ) %P ;
        }
    }
    return dp[mask][tid]=ans;
}


int main(){
    cin >> t;
    while(  t--){
        for(int i=0;i<10;i++) tshirts[i].reset();
        scanf("%d\n",&n );
        string input; 
        for(int i=0;i<n;i++){
            getline(cin,input) ;
            vector<string> ids;
            string temp;
            for(int j=0;j<input.size();j++){
                if( input[j] == ' ' && !temp.empty() ){
                    ids.push_back(temp);
                    temp.clear();
                }
                else if(input[j] != ' ')
                    temp.push_back(input[j]) ;
            }
            if( !temp.empty())
                ids.push_back(temp);
            for(int j=0;j<ids.size();j++) tshirts[i].set(stoi(ids[j])-1 );
        }

        memset(dp,-1,sizeof(dp));
        cout << rec(0,0)<<endl;
        
    }
    return 0;
}















