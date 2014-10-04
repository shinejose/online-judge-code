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


// #define _DEBUG 


const int MAXN = 20000000 ;
const int MAXP =  50  + 3001134;
bool isprime[MAXN+10];
int prime[MAXP];
int primenum;
void create_prime(int n) 
{
    for(int i=2;i<=n;i++){
        if(!isprime[i])
            prime[primenum++]=i;
        for(int j=0; j<primenum && i*prime[j]<=n;j++) 
        {
            isprime[i*prime[j]]=1; //删去 （当前这个数×小于等于+其最小素因子）的数
            if(i%prime[j]==0)  // 也就是每个合数可以划分成一个最小素因子和另一个数
                break;      // 一个是另一个数×最小素因子来删除这个合数的
        }                // 不能找到第二种删除方法也就是说每个合数只能被删除1次
    }
}

ll string_to_longlong( string str){
    if( str.size() <= 16) {
        long long ret = 0;
        for(int i=0;i<str.size();i++){
            ret  =  ret*10 +  (str[i]-'0');
        }
        return ret;
    }
}
string n;
ll nl;
vector<pair<ll,ll> > ans;




void solution(){
    if(n.size()<=14){
        ans.clear();
        nl = string_to_longlong(n);
        for( int i=0;i<primenum;i++){
            if( (nl % prime[i] ) == 0 ) {
                ans.push_back(make_pair(prime[i],0));
            }
            while ( (nl % prime[i] )== 0){
                nl /= prime[i];
                ans[ans.size()-1].second++;
            }
        }
        if( nl > 1 ) {
            ans.push_back(make_pair(nl,1));
        }
        ll realAns =0 ;
        for(auto &it : ans){
            realAns += it.second;
        }
        cout <<realAns <<endl;
        for( auto &it: ans){
            for(int i=0;i<it.second;i++){
                cout << it.first << endl;
            }
        }
    }
    else {
        cout << 1 << endl;
        cout << n << endl;
    }
}


int main(){
    ios::sync_with_stdio(false);
    create_prime(MAXN);
#ifdef _DEBUG    
    cout <<primenum <<endl;
#endif 
    int t;
    cin >> t ;
    while(t -- ){
        cin >> n;
        solution();
    }
    return 0;
}









// void out_prime(){
//     printf("prime[50847539]={");
//     for(int i=0;i<primenum;i++){
//         printf("%d,",prime[i]);
//     }
//     printf("}\n");
// }
