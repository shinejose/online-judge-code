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


class BishopMove{
    public:
    int howManyMoves(int r1, int c1, int r2, int c2){
        queue<tuple<int,int,int>> q;
        q.push(make_tuple(r1,c1,0));
        int dir[4][2] ={{1,1},{1,-1},{-1,1},{-1,-1}};
        int flag[10][10];
        memset(flag,0,sizeof(flag) ) ;
        while( !q.empty()) {
            tuple<int,int,int> top = q.front();
            if( get<0>(top) == r2 && get<1>(top) == c2) {
                return get<2>(top);
            }
            q.pop();
            if( flag[get<0>(top)][get<1>(top)] ) continue; 

            flag[get<0>(top)][get<1>(top)] = 1;
            for(int i=0;i<4;i++){
                for(int k=1;k<10;k++){
                    int x = get<0>(top)+k*dir[i][0];
                    int y = get<1>(top)+k*dir[i][1];
                    if( x<0 || x >=8 || y <0 || y >=8) continue;
                    q.push(make_tuple(x,y,get<2>(top) +1) ) ;
                }
            }

        }
        return -1;
    }
};


int main(){
    return 0;
}





