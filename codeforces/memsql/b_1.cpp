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




double dist(int x,int y,int x1,int y1){
    return (double)sqrt((double)(x-x1) *(x-x1) + (double)(y-y1) * (y-y1));
}


double ans;
int p[4][2];
int n;
int m;

int main(){
    cin >> n >>m ;
            ans =-1;
            
            for(int x0=0;x0<=n && x0 <=10;x0++){
                for(int y0 =0;y0<=m && y0<=10;y0++){
                    for(int x1=n;x1<=n;x1++){
                        for(int y1 =m;y1<=m;y1++){
                            if(x0 ==x1 && y0 == y1) continue;

                            for(int x2=0;x2<=0;x2++){
                                for(int y2 =0;y2<=0;y2++){
                                    if(x0 ==x2 && y0 == y2) continue;
                                    if(x1 ==x2 && y1 == y2) continue;


                                    for(int x3=n ;x3>=n-10 && x3 >= 0 ;x3--){
                                        for(int y3 =m;y3<=m-10 && y3 >=0 ;y3-- ){
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
                for(int i=0;i<4;i++){
        printf("%d %d\n",p[i][0],p[i][1]);
    }
    


    return 0;
}





