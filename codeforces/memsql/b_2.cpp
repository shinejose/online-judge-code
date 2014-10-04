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

set<pair<int,int>> ps;
vector<pair<int,int>> p;
double ans;


double dist(pair<int,int> a,pair<int,int> b ){
    double dx = get<0>(a)- get<0>(b) ;
    double dy = get<1>(a)- get<1>(b) ;
    return sqrt(dx*dx +dy*dy);
}


int main(){
    cin >> n >> m;
    for(int i=0;i<2;i++) for(int j=0;j<2;j++ ){
            if(i <=n && j <=m )      ps.insert(make_pair(i,j));
            if( n-i >=0 && m-j >=0 ) ps.insert(make_pair(n-i,m-j));
            if( i<=n && m-j  >=0 )   ps.insert(make_pair(i,m-j));
            if( j<=m && n-i >=0 )    ps.insert(make_pair(n-i,j));
        }
    for(auto it=ps.begin();it!=ps.end();it++ )
        p.push_back(*it);

    ans =-1;
    int ans_index[4];
    for(int p1=0;p1<p.size();p1++) for(int p2=0;p2<p.size();p2++ ) if( p1!= p2) {
                for(int p3 =0;p3<p.size();p3++)  if( p3!=p1 && p3!=p2) {
                        for(int p4 =0 ;p4<p.size();p4++ ) if( p4 !=p1 && p4!=p2 && p4!=p3) {
                                double t = dist(p[p1],p[p2]) + dist(p[p2],p[p3]) +dist(p[p3],p[p4]); 
                                if(t  > ans ){
                                    ans =t ;
                                    ans_index[0] = p1;
                                    ans_index[1] = p2;
                                    ans_index[2] = p3;
                                    ans_index[3] = p4;
                                }
                            }
                    }
            }
    for(int i=0;i<4;i++){
        printf("%d %d\n",get<0>(p[ans_index[i]]),get<1>(p[ans_index[i]]));
    }
    
    return 0;
}





