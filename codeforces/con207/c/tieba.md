list 的性能问题
=== 

大家好，本人最近开始用python，看了下官方文档然后找了道题做了一下，

发觉python的硬是过不去怀疑是list 的 问题，各位有经验来看看到底是

哪里的问题。


数据是 3*10^5 算法的时间复杂度是O(3*10^5log(3*10^5) ) 

C++ 234ms python 22秒


#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<memory.h>
#include<algorithm>
#include<functional>
using namespace std;
#define fill(x,y) (memset(x,y,sizeof(x)))
#define L(x) ((x) << 1) 
#define R(x) (((x)<<1)+1 )
#define F(x) ((x)>>1)
typedef vector<int> vi;

class
Node 
{
    private:
    public:
        int l,r;
        int cover;
        int father;
};

const int MAXN = 3*1e5 +5 ;
 
Node tree[4*MAXN] ;
int index2[MAXN] ; 
int root =1;

void create(int node,int l,int r,int f) 
{
    tree[node].l = l ;
    tree[node].r = r;
    tree[node].cover = 0 ;
    tree[node].father = f ;
    if ( l == r-1 ) 
    {
        index2[l] = node;
        return ;
    }
    else 
    {
        create(L(node),l,(l+r) >> 1 ,node ) ;
        create(R(node),(l+r)>>1 , r,node ) ;
    }
}

void push(int node, int l, int r,int value) 
{
    if (tree[node].r == r && tree[node].l == l && tree[node].cover ==0 ) 
    {
        tree[node].cover = value;
    }
    else if ( tree[node].cover == 0 ) 
    {
        if( tree[L(node)].r >= r ) 
            push(L(node),l,r,value) ;
        else if ( tree[R(node)].l <= l) 
            push(R(node),l,r,value) ; 
        else 
        {
            push(L(node),l ,tree[L(node) ] .r,value) ;
            push(R(node),tree[R(node)].l,r ,value) ;
        }
    }
}

int up(int node) 
{
    do 
    {
        if(tree[node].cover!= 0) 
            return tree[node].cover;
        node =F(node) ; 
    }while(tree[node].father != -1) ;
    return 0;
}

int main(int argc,char** argv)
{
    int n,m; 
    cin >> n >> m;
    create(root,1,n+1 , -1 ) ; 
    for(int i =0;i<m;i++) 
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c) ;
        if( a <= c - 1 ) 
            push(root,a,c,c) ;
        if (c+1 <= b ) 
            push(root,c+1,b+1,c) ;

    }
    for (int i=1; i<= n ; i++) 
        cout << up(index2[i] ) <<' ';
    cout<< endl;
    return 0;
}

