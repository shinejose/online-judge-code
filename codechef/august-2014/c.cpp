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



int n,m;
vector<map<int,int>> graph;
vector<map<int,int>> regraph;

const int MAXN = 100000+5;
const int INF = 1e9+7; 
int d[MAXN];
bool visited[MAXN];
deque<int> qvisiting;

int main(){
    cin >> n >>m ;
    map<int,int> temp;
    temp.clear();
    graph.assign(n+1,temp);
    regraph.assign(n+1,temp);
    for(int i=0;i<m;i++){
        int xi,yi;
        cin >> xi >> yi ;
        if( graph[xi].find(yi)  == graph[xi].end() )
            graph[xi][yi] = 1;
        else
            graph[xi][yi] ++;
        if( regraph[yi].find(xi) == regraph[yi].end())
            regraph[yi][xi] =1;
        else
            regraph[yi][xi] ++;
    }

    qvisiting.push_front(1);
    for(int i=0;i<=n;i++) d[i] = INF;
    d[1] = 0;
    while(!qvisiting.empty()) {
        int top = qvisiting.front();
        if( visited[top]  ) {
            qvisiting.pop_front();
            continue;
        }
        visited[top] = true;
        qvisiting .pop_front();
        for(auto it=graph[top].begin();it!=graph[top].end();it++){
            d[it->first] = min(d[it->first],d[top])  ;
            if(! visited[it->first ] ) qvisiting.push_front(it->first);
        }
        for(auto it=regraph[top].begin();it!=regraph[top].end();it++){
            d[it->first ] = min(d[it->first ],d[top] +1 );
            if(! visited[it->first ] ) qvisiting.push_back(it->first);
        }
    }
    if( d[n] == INF ) cout << "-1\n"; else cout << d[n] <<endl;

    
    
    
    return 0;
}









