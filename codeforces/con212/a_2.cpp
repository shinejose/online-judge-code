#include <cstdio>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int t;
char board[10][10];

int pos[2][2];
queue<tuple <int,int,int>>  qpos;

int main(){
    cin >> t;
    for(int l=0;l<t;l++){
        for(int j=1;j<=8;j++){
            scanf("%s",&board[j][1]);
        }
        int count =0;
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++){
                if( board[i][j]== 'K'){
                    pos[count][0] = i;
                    pos[count++][1] = j;
                }
            }
        }
        while(! qpos.empty()){
            qpos.pop() ;
        }

        
        
    }
                    
                
    
    return 0;
}

