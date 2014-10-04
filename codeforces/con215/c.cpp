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


string s;
int m;
const int MAXN = 100005;
int l[MAXN],r[MAXN];
int xnn[MAXN],ynn[MAXN],znn[MAXN];

int sucess;



int main(){
    cin >> s >> m;
    for(int i=0;i<m;i++){
        scanf("%d%d",&l[i],&r[i]);
    }

    int n = s.size();
    xnn[0] = ynn[0] = znn[0] = 0;
    for(int i=1;i<=n;i++){
        if(s[i-1] =='x'){
            xnn[i] = xnn[i-1] +1;
            ynn[i] = ynn[i-1];
            znn[i] = znn[i-1];
        }
        else if(s[i-1] == 'y'){
            ynn[i] = ynn[i-1] +1;
            xnn[i] = xnn[i-1] ;
            znn[i] = znn[i-1];
        }
        else if(s[i-1] == 'z'){
            znn[i] = znn[i-1]+1;
            xnn[i] = xnn[i-1] ;
            ynn[i] = ynn[i-1];
        }
    }
    for(int i=0;i<m;i++){
        sucess =0;
        int xnum = xnn[r[i]] -xnn[l[i]-1] ;
        int ynum = ynn[r[i]] -ynn[l[i]-1] ;
        int znum = znn[r[i]] -znn[l[i]-1] ;
        int all = r[i]-l[i] +1;
        if(all < 3 ){
            sucess =1;
        }
        else if( all %3 == 0){
            if(xnum == ynum && xnum == znum )
                sucess =1 ;
        }
        else if( all % 3== 1){
            if(max(xnum,max(ynum,znum)) == all/3 +1 &&
               min(xnum,min(ynum,znum)) == all/3 )
                sucess =1 ;
        }
        else {
            if(max(xnum,max(ynum,znum)) == all/3 +1 &&
               min(xnum,min(ynum,znum)) == all/3 ){
                
                sucess =1 ;
            }
        }
        if (sucess ){
            cout << "YES"<<endl;
        }
        else {
            cout << "NO"<<endl;
        }
    }
    
    return 0;
}





