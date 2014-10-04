#include <cstdio>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include  <vector>
#include <string>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
#include <map>

using namespace std;
// RMQ := range minimum query ;
// min([i,i+2^j-1]) = min ( min([i,i+2^(j-1)-1])  ,min([i+2^(j-1),[i+2^j-1] );
// dp(i,j) = min(dp(i,j-1),dp(i+2^(j-1),j-1));
template <typename  T=int> 
class RMQ {
    public:
    vector<vector<T>>  dp;
    vector<vector<T>> pos;
    T (*compare)(const T &a,const T &b) ;
    void init(vector<T> a){
        int n = a.size();
        int k = log2(n) +1;
        vector<int> temp(k);
        dp.assign(n,temp);
        pos.assign(n,temp);

        for(int i=0;i<n;i++){
            dp[i][0] = a[i];
            pos[i][0] = i;
        }
        for(int j=1;(1<<j)<=n;j++)
            for(int i=0;i+(1<<j)-1<n;i++){
                dp[i][j] = compare(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
                if(dp[i][j] == dp[i][j-1] )
                    pos[i][j] = pos[i][j-1];
                else
                    pos[i][j] = pos[i+(1<<(j-1))][j-1];
            }
    }
    T get_min(T i,T j){
        T k =log2(j-i+1.0)  ;
        return  compare(dp[i][k],dp[j-(1<<k)+1][k]);
    }
    T get_index(T i,T j){
        T k =log2(j-i+1.0)  ;
        if(dp[i][k] == compare(dp[i][k], dp[j-(1<<k)+1][k]) )
            return pos[i][k];
        else
            return pos[j-(1<<k)+1][k];
    }
};

RMQ<> rmq;
int rmq_min(const int &a,const int &b){
    return min(a,b);
}

int n;
vector<int> a;
int  f(int l,int r,int h){
    if(l > r) return 0;
    int m = rmq.get_index(l,r);
    int min_h = a[m];
    return min(f(l,m-1,min_h)+f(m+1,r,min_h)+min_h-h ,r-l+1);
}



int main(){
    cin >> n;
    a.assign(n,0);
    for(int i=0;i<n;i++)
        cin >> a[i];
    rmq.compare= rmq_min;
    rmq.init(a);
    printf("%d",f(0,n-1,0));
    return 0;
}










