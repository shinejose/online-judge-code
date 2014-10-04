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
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;




const int MAXN = 1000006;
int n;
int a[MAXN];
map<int,int> ma;
int front[MAXN];
int back[MAXN];

ll ans;

#define L(x) ((x) <<1)
#define R(x) ((((x) <<1) +1))
#define F(x) ((x) >>1) 
class Node{
public:
    int l,r;
    int sum ;
}st[MAXN*5];
int root;

int  segmentTree_create(int node,int l,int r){
    st[node].l = l;
    st[node].r = r;
    if(r-l==1) {
        return st[node].sum = 0;
    }
    else{
        return    st[node].sum =
            segmentTree_create(L(node),l,(l+r) >>1) +
            segmentTree_create(R(node),(l+r)>>1,r);
    }
}
void segmentTree_pushUp(int node){
    while(node  >=root ){
        st[node].sum = st[L(node)].sum + st[R(node)].sum;
        node = F(node);
    }
}
int segmentTree_getSum(int node,int l,int r) {
    if( r <=l ) return 0;
    if(st[node].l == l && st[node].r == r ){
        return st[node].sum;
    }
    else if( r<= st[L(node)].r   ){
        return segmentTree_getSum(L(node),l,r);
    }
    else if( l>= st[R(node)].l ) {
        return segmentTree_getSum(R(node),l,r);
    }
    else {
        return segmentTree_getSum(L(node),l,st[L(node)].r) + 
            segmentTree_getSum(R(node),st[R(node)].l,r);
    }
    
}
void segmentTree_insert(int node,int l,int r,int value) {
    st[node].sum++;
    if(st[node].l == l && st[node].r == r ){
        return ;
    }
    else if( r<= st[L(node)].r   ){
        segmentTree_insert(L(node),l,r,value);
    }
    else if( l>= st[R(node)].l ) {
        segmentTree_insert(R(node),l,r,value);
    }
    else {
        segmentTree_insert(L(node),l,st[L(node)].r,value);
        segmentTree_insert(R(node),st[L(node)].l,r,value);
    }
}



int main(){
    cin >> n;
    for(int i=0;i<n;i++ ) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++) {
        ma[a[i]]++;
        front[i] = ma[a[i]];
    }
    ma.clear();
    for(int i=n-1;i>=0;i--) {
        ma[a[i]]++;
        back[i] = ma[a[i]];
    }

    root =1;
    segmentTree_create(root,1,MAXN);
    for(int i=n-1;i>=1;i--){
        segmentTree_insert(root,back[i],back[i]+1,1);
        ans += segmentTree_getSum(root,1,front[i-1]);
    }
    cout << ans<<endl;
    return 0;
}









