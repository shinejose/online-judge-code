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

double ans;
int p[4][2];

double dist(int x,int y,int x1,int y1){
    return (double)sqrt((double)(x-x1) *(x-x1) + (double)(y-y1) * (y-y1));
}
int main(){
    cin >> n>>m;

    if( n == 0 || m ==0 ){
        if(n==0){
            p[0][0] = 0; p[0][1] = 1;
            p[1][0] = 0; p[1][1] = m;
            p[2][0] = 0; p[2][1] = 0;
            p[3][0] = 0; p[3][1] = m-1;
        }
        else {
            p[0][1] = 0; p[0][0] = 1;
            p[1][1] = 0; p[1][0] = n;
            p[2][1] = 0; p[2][0] = 0;
            p[3][1] = 0; p[3][0] = n-1;
        }
    }
    else if( n==1 || m ==1 ){
        if(n==1){
            p[0][0] = 0; p[0][1] = 0;
            p[1][0] = n; p[1][1] = m;
            p[2][0] = n; p[2][1] = 0;
            p[3][0] = 0; p[3][1] = m;
        }
        else {
            p[0][0] = 0; p[0][1] = 0;
            p[1][0] = n; p[1][1] = m;
            p[2][0] = 0; p[2][1] = m;
            p[3][0] = n; p[3][1] = 0;
        }
    }
    else {
        if( n * m <= 50   ){
            for(int x0=0;x0<=n;x0++){
                for(int y0 =0;y0<=m;y0++){
                    for(int x1=0;x1<=n;x1++){
                        for(int y1 =0;y1<=m;y1++){
                            if(x0 ==x1 && y0 == y1) continue;

                            for(int x2=0;x2<=n;x2++){
                                for(int y2 =0;y2<=m;y2++){
                                    if(x0 ==x2 && y0 == y2) continue;
                                    if(x1 ==x2 && y1 == y2) continue;


                                    for(int x3=0;x3<=n;x3++){
                                        for(int y3 =0;y3<=m;y3++){
                                            if(x0 ==x3 && y0 == y3) continue;
                                            if(x1 ==x3 && y1 == y3) continue;
                                            if(x2 ==x3 && y2 == y3) continue;

                                            if(dist(x0,y0,x1,y1) +
                                               dist(x1,y1,x2,y2) +
                                               dist(x2,y2,x3,y3) > ans) {
                                                ans =dist(x0,y0,x1,y1) + dist(x1,y1,x2,y2) +
                                                    dist(x2,y2,x3,y3);
                                                p[0][0] = x0; p[0][1] =y0;
                                                p[1][0] = x1; p[1][1]= y1;
                                                p[2][0] = x2; p[2][1]= y2;
                                                p[3][0] = x3 ;p[3][1]= y3 ;
                                                
                                            }
                                    
                                    
                                        }
                                    }
                                    
                                    
                                }
                            }

                        }
                    }
                }
            }
        }
        else {

            
            p[0][0] = 0; p[0][1] =0;
            p[1][0] = n; p[1][1]= m;
            if( n <m ){
                p[2][0] = n; p[2][1]= 0;
                p[3][0] = 0;p[3][1]=m ;
            }
            else {
                p[2][0] = 0  ; p[2][1]= m;
                p[3][0] = m ;p[3][1]=0 ;
            }
            ans = 2.0 * dist(1,1,n,m);
            if( dist(0,0,n,m) + dist( n,m,p[2][0],p[2][1]) +
                dist(p[2][0],p[2][1],p[3][0],p[3][1])  < ans) {
                p[0][0] = 1; p[0][1] =1;
                p[1][0] = n; p[1][1]= m;
                p[2][0] = 0; p[2][1]= 0;
                p[3][0] = n-1;p[3][1]=m-1;
            }
            else
                ans = dist(0,0,n,m) + dist( n,m,p[2][0],p[2][1]) +
                    dist(p[2][0],p[2][1],p[3][0],p[3][1]);

            
            if( dist(0,1,n,m) + dist( n,m,0,0) +
                dist(0,0,n-1,m)  < ans) {
                p[0][0] = 0; p[0][1] =1;
                p[1][0] = n; p[1][1]= m;
                p[2][0] = 0; p[2][1]= 0;
                p[3][0] = n-1;p[3][1]=m;
                ans = dist(0,1,n,m) + dist( n,m,0,0) +
                    dist(0,0,n-1,m) ;
            }
            if( dist(1,0,n,m) + dist( n,m,0,0) +
                dist(0,0,n-1,m)  < ans) {
                p[0][0] = 1; p[0][1] =0;
                p[1][0] = n; p[1][1]= m;
                p[2][0] = 0; p[2][1]= 0;
                p[3][0] = n-1;p[3][1]=m;
                ans = dist(1,0,n,m) + dist( n,m,0,0) +
                    dist(0,0,n-1,m) ;
            }

            

            for(int i=1;i<=m;i++){
                if( 2.0 * dist(0,i,n,m) > ans  ){
                    p[0][0] = 0; p[0][1] = i;
                    p[3][0] = n; p[3][1] = m-i;
                    ans = 2.0 * dist(0,i,n,m);
                }
            }
        
            for(int i=0;i<n;i++){
                if( dist(i,0,0,m) > ans  ){
                    p[0][0] = i; p[0][1] = 0;
                    p[3][0] = n-i; p[3][1] = m;
                    ans = dist(i,0,0,m);
                }
            }

            for(int i=1;i<=n;i++){
                if(dist(i,0,0,m) + dist(i,0,n,m)  >ans){
                    p[0][0] = 0; p[1][0] =0;
                    p[1][0] = n; p[1][1]= m;
                    p[2][0] = i; p[2][1]= 0;
                    p[3][0] = 0;p[3][1]=m ;
                    ans = dist(i,0,0,m) + dist(i,0,n,m) ;
                }
            }
            for(int i=1;i<=m;i++){
                if(dist(0,i,n,m) + dist(0,i,n,0)  >ans){
                    p[0][0] = 0; p[1][0] =0;
                    p[1][0] = n; p[1][1]= m;
                    p[2][0] = 0; p[2][1]= i;
                    p[3][0] = n;p[3][1]=0 ;
                    ans = dist(0,i,n,m) + dist(0,i,n,0) ;
                }
            }
        }
    } 

    for(int i=0;i<4;i++){
        printf("%d %d\n",p[i][0],p[i][1]);
    }
    
    return 0;
}





