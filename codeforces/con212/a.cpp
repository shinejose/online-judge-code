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

int dir[4][2]={{-2,-2},{-2,2},{2,-2},{2,2}};
struct Node{
    int x,y,step,index;
    Node(){};
    Node(int ix,int iy,int is,int ii){
        x = ix;
        y = iy ;
        step =is;
        index =ii;
    }
};
int kmap[10][10];
queue<Node> qpos;

int main(){
    cin >> t;
    for(int l=0;l<t;l++){
        while(!qpos.empty()){
            qpos.pop();
        }

        for(int j=0;j<8;j++){
            scanf("%s",board[j]);
        }
        int count =1;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if( board[i][j]== 'K')
                    qpos.push(Node(i,j,0,count++));
            }
        }
        count =0;
        int sucess= 0;
        Node k1 = qpos.front();
        qpos.pop();
        while(!qpos .empty ()){
            Node top = qpos.front();
            qpos .pop();
            if(top.step>=4){
                sucess =0;
                break;
            }
            if(top.x == k1.x && top.y == k1.y ){
                sucess = top.step;
                break;
            }
            for(int i=0;i<4;i++){
                int x = top.x + dir[i][0];
                int y = top.y +dir[i][1];
                if(x<0 || x >=8 || y<0 || y>=8)
                    continue ;
                qpos.push(Node(x,y,top.step+1,top.index));
            }
        }
        if(sucess !=0 && sucess%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
                    
                
    
    return 0;
}
