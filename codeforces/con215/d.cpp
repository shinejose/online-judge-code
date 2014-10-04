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


ll n,m,p;

const int MAXN = 200005;
int a[MAXN],b[MAXN];

map<int,vector<int>> sequence;
map<int,int> mycount;
vector<int> seqv;
vector<int> ans;

int main(){
    cin >> n >>m >>p ;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i =1;i<=m;i++){
        scanf("%d",&b[i]) ;
    }
    for(int i=1;i<=n;i++){
        if( i%p == 0) 
            sequence[p].push_back(a[i]);
        else 
            sequence[i%p].push_back(a[i]);
    }
    for(auto &seq : sequence ){
        mycount .clear();
        seqv = seq.second;
        int len_seq = seqv.size() ;
        for(int i=0;i<len_seq;i++){
            if( i <= m-1 ) {
                auto it_a = mycount.find(b[i+1]) ;
                if( it_a  == mycount .end()){
                    mycount [b[i+1]] =1 ;
                }
                else{
                    if( it_a->second   == -1)
                        mycount .erase(it_a);
                    else
                        it_a->second = it_a->second +1  ;
                }
                
                auto it_a_m = mycount .find(seqv[i]) ;
                if(it_a_m == mycount .end()) 
                    mycount [seqv[i]] =-1 ;
                else{
                    if( it_a_m->second == 1)
                        mycount .erase(it_a_m);
                    else
                        it_a_m->second = it_a_m->second -1 ;
                }
                if( i==m-1 && mycount .size() ==0){
                    ans.push_back(seq.first+(i-(m-1)) *p);
                }
            }
            else {
                auto it_a = mycount .find(seqv[i-m]) ;
                if(it_a == mycount .end()) 
                    mycount [seqv[i-m]] =1 ;
                else{
                    if( it_a->second == -1)
                        mycount .erase(it_a);
                    else
                        it_a->second = it_a->second +1  ;
                }

                auto it_a_m = mycount .find(seqv[i]) ;
                if(it_a_m == mycount .end()) 
                    mycount [seqv[i]] =-1 ;
                else{
                    if( it_a_m->second == 1)
                        mycount .erase(it_a_m);
                    else
                        it_a_m->second = it_a_m->second -1 ;
                }

                if( mycount .size() ==0){
                    ans.push_back(seq.first+(i-(m-1)) *p);
                }
            }
        }
    }
    cout << ans.size()<<endl;
    sort(ans.begin(),ans.end()) ;
    for(auto &i:ans){
        cout <<i <<" ";
    }
    

    
    return 0;
}





