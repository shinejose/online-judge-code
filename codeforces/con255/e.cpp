#include <cstdio>
#include <cmath>
#include <memory.h>
#include <cstring> 
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
#include <functional>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

#define MAXN 300005
#define MOD 1000000009
int n,m;
long long  f[MAXN];
int  a[MAXN];
long long suma[MAXN];
ll sumf[MAXN];

struct Node{
    int  l,r;
    long long  sum;
    long long sumf;
    int mark;
    int low;
}tree[MAXN*4];

int root =1;
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define F(x) ((x)>>1) 

long long  create(int node,int l,int r){
    tree[node].l=l;
    tree[node].r=r;
    tree[node].mark=0;
    tree[node].sumf=0 ;
    if(r-l==1){
        return tree[node].sum = a[l];
    }
    int mid=(l+r)/2;
    return tree[node].sum =  (long long) create(L(node),l,mid) + create(R(node),mid,r);
}

long long   sum(int node,int l,int r,int low){
    if( tree[node].l == l && tree[node].r == r){
        if(r - l == 1 ){
            if(tree[node ].mark) 
                tree[node].sumf = (tree[node].sumf + f[r-tree[node].low+2]- f[l-tree[node].low+2])%MOD;
            tree[node].mark =0;
            tree[node].sumf = (tree[node].sumf + f[r-low+2]- f[l-low+2])%MOD ;
            return f[r-low+2]- f[l-low+2];
        }
        else{
            if(tree[node].mark){
                tree[node].mark = 0;
                tree[R(node)].mark = tree[L(node)].mark=1;
                tree[R(node)].low =  tree[L(node)].low = tree[node].low;
                tree[node].sumf += f[r-tree[node].low+2]-f[l-tree[node].low+2] %MOD;
            }
            tree[node].mark=1;
            tree[node].low = low;
            return f[r-tree[node].low+2]-f[l-tree[node].low+2];
        }
    }
    else {
        if(tree[node].mark){
            tree[node].mark = 0;
            tree[R(node)].mark = tree[L(node)].mark=1;
            tree[R(node)].low =  tree[L(node)].low = tree[node].low;
            tree[node ].sumf += f[r-tree[node].low+2]-f[l-tree[node].low+2] %MOD;
        }
        long long ret =0 ;
        if( tree[L(node)].r >= r ){
            ret = sum (L(node),l, r,low)  ;
        }
        else if(tree[R(node)].l <= l){
            ret = sum (R(node),l, r,low);
        }
        else {
            ret = sum(L(node),l,tree[L(node)].r,low) + 
            sum(R(node),tree[R(node)].l,r,low);
        }
        tree[node].sumf = (tree[node].sumf+ret)%MOD;
        return ret;
    }
}
long long  get(int node,int l,int r ){
    if( tree[node].l == l && tree[node].r == r ){
        if(tree[node].mark) {
            return (f[r-tree[node].low+2]-f[l-tree[node].low+2] +tree[node].sum+tree[node].sumf)%MOD;
        }
        else {
            return (tree[node].sum + tree[node].sumf)%MOD;
        }
    }
    else {
        long long ret =0 ;
        if(tree[node].mark) {
            ret = (ret + f[r-tree[node].low+2] -f[l-tree[node].low+1] ) %MOD;
        }
        if( tree[L(node)].r >= r ){
            ret =  ( ret  + get (L(node),l, r))%MOD ;
        }
        else if(tree[R(node)].l <= l){
            ret = (ret +get (R(node),l, r ))%MOD;
        }
        else {
            ret  = (ret + 
                    ((get(L(node),l,tree[L(node)].r ) +
                      get(R(node),tree[R(node)].l,r))%MOD ) )%MOD;
        }
        return ret;
    }
}


void preprocess(){
    f[0]=0;
    f[1]=1;
    sumf[0]=0;
    sumf[1]=1;
    for(int i=2;i<MAXN;i++){
        f[i] = (f[i-1] + f[i-2]) %MOD;
        sumf[i] = (sumf[i-1] +f[i]) %MOD;
    }
}
void input(){
    scanf("%d%d",&n,&m);
    a[0] =0 ;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        suma[i]=suma[i-1]+a[i];
    }
    create(root,1,n+1);
    for(int i=0;i<m;i++){
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op ==1){
            sum(root,l,r+1,l);
        }
        else if (op ==2)  {
            cout << get(root,l,r+1) << endl;

        }
    }
}

void solution(){
    
}

void output(){
    
}

int main(){
    preprocess();
    input();
    solution();
    output();
    return 0;
}
