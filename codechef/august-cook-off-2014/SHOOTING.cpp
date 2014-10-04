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

int t,n,m;
char  board[55][55];
int dir[3][2] = {{-1,0},{0,1},{0,-1}};




int main(){
    cin >> t ;
    while(t--) {
        scanf("%d%d\n",&n,&m);
        
        for(int i=0;i<n;i++)
            scanf("%s",board[i]);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'L') {
                    for(int l=1;l<=55;l++){
                        for(int k=0;k<3;k++){
                            int x = i + l*dir[k][0];
                            int y = j + l*dir[k][1];
                            if( x < 0 || y < 0 || x>=n || y >= m) continue;
                            if( board[x][y] == 'E'){
                                board[x][y] = '.';
                            }
                        }
                    }
                }
            }
        }

        bool sucess =true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'E')
                    sucess = false ;
            }
        }

        if(sucess){
            cout << "Possible"<<endl;
        }
        else
            cout << "Impossible"<< endl;
    }
    return 0;
}









