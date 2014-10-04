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


const int BASESYSTEM = 10000;
int n;
vector<int> BigInteger_MUL(vector<int> ret,int x){
    int r,c;
    r= c =0 ;
    for(int i=0;i<ret.size();i++){
        r = (ret[i] * x + c) % BASESYSTEM;
        c = (ret[i] * x + c ) /BASESYSTEM;
        ret[i] = r;
    }
    while(c) {
        r = c % BASESYSTEM ; 
        c = c /  BASESYSTEM;
        ret.push_back(r);
    }
    return ret;
}


int main(){
    while(1) {
        cin >> n;
        if(  n==0 ) break;
        vector<int> ans;
        ans.push_back(1);
        for(int i=2*n;i>=n+2;i--){
            ans =BigInteger_MUL(ans,i);
        }
        printf("%d",ans[ans.size()-1]);
        for(int i=ans.size()-2;i>=0;i--){
            printf("%04d",ans[i]);
        }
        printf("\n");
        
    }
    return 0;
}





