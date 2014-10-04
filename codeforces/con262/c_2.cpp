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

const int MAXN =1e5+5; 
vector<ll> a;
int n,m,w;

class  Node{
public:
    int l,r;
    pair<ll,int> min;
    ll added;  
}st[MAXN*4];
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define F(x) ((x) >>1 ) 

pair<ll,int>   segment_tree_init(int pNode,int l, int r ){
    st[pNode].l =l , st[pNode].r = r;
    st[pNode].added =0 ;
    if( r - l ==1 ) return st[pNode].min =make_pair(a[l],l);
    else return st[pNode].min= min(segment_tree_init(L(pNode),l,(l+r) >>1 ),
                                   segment_tree_init(R(pNode),(l+r) >>1 ,r));
}
void segment_tree_push_up(int pNode){
    while(pNode > 1 ){
        pair<ll,int> cur =make_pair(st[pNode].min.first+st[pNode].added,
                                    st[pNode].min.second);
        pair<ll,int> lUncle=make_pair(st[L(F(pNode))].min.first+st[L(F(pNode))].added,
                                    st[L(F(pNode))].min.second);
        pair<ll,int> rUncle=make_pair(st[R(F(pNode))].min.first+st[R(F(pNode))].added,
                                     st[R(F(pNode))].min.second);
        if(L(F(pNode)) == pNode) 
            st[F(pNode)].min = min( cur , rUncle );
        else 
            st[F(pNode)].min = min( cur,  lUncle );
        pNode = F(pNode);
    }
}
void segment_tree_add(int pNode,int l,int r,int value) {
    if( st[pNode].l == l && st[pNode].r ==r ) {
        st[pNode].added += value;
        segment_tree_push_up(pNode);
    }
    else {
        if( st[pNode].added  >0 ) {
            st[L(pNode)].added += st[pNode].added ;
            st[R(pNode)].added += st[pNode].added;
            st[pNode].added = 0;
        }
        if( st[L(pNode)].r >= r)  segment_tree_add(L(pNode),l,r,value);
        else if( st[R(pNode)].l <= l)  segment_tree_add(R(pNode),l,r,value);
        else{
            segment_tree_add(L(pNode),l,st[L(pNode)].r,value);
            segment_tree_add(R(pNode),st[R(pNode)].l,r,value);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m >> w;
    a.assign(n,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    segment_tree_init(1,1,n+1);
    for(int i=0;i<m;i++){
        int index = st[1].min.second ;
        int right =min(index+w, n+1) ;
        int left = max(1,right-w) ;
        segment_tree_add(1,left,right,1);
    }
    cout << segment_tree_min(1,1,n+1).first <<endl;
    return 0;
}









