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

const int MAXN =100005;
int n;

struct laptop{
    int p,q;
}l[MAXN ];

int sucess ; 


int main(){
    cin >> n ;
    for(int i=0;i<n;i++){
        scanf("%d %d",&l[i].p,&l[i].q);
    }
    sort(l,l+n,[](const laptop &a,const laptop &b) {
            if( a .p ==b .p )
                return a.q <= b.q ;
            return a.p<b.p;
        });

    int mm=l[0].q;
    int index=0;
    int price = l[0].p ;
    for(int i=1;i<n;i++){
        if( l[i].p > price && mm > l[i].q ) {
            sucess =1 ;
            break;
        }
        if( mm < l[i].q){
            mm = l[i].q;
            index = i;
            price=l[i].p;
        }
    }
    if(sucess) {
        cout << "Happy Alex\n";
    }
    else
        cout << "Poor Alex\n"; 
    return 0;
}










