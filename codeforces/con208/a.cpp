#include <cstdio>
#include <cmath>
#include <cstdlib>
#include  <memory.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <tuple>
#include <stack>
#include <queue>
#include <vector>


using namespace std ;

typedef long long ll ;


int n;
int x[1005];
int sucess;


int main(){
    scanf("%d",&n) ;
    for(int i=0;i<n ;i++){
        scanf("%d",&x[i]);
    }
    sucess =1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j || i  == n-1 || j==n-1)
                continue;
            if(x[i] < x[i+1]) {
                if(x[i] < x[j] && x[i+1] > x[j] &&  x[i+1] < x[j+1] ){
                    sucess =0 ;
                    break;
                }
                if(x[i] < x[j] && x[i+1] > x[j] &&  x[i] > x[j+1] ){
                    sucess =0 ;
                    break;
                }
                if(x[i] < x[j+1] && x[i+1] > x[j+1] &&  x[i] >  x[j] ){
                    sucess =0 ;
                    break;
                }
                if(x[i] < x[j+1] && x[i+1] > x[j+1] &&  x[i+1] <  x[j] ){
                    sucess =0 ;
                    break;
                }

            }
            if(x[i] >  x[i+1]) {
                if(x[i] > x[j] && x[i+1] < x[j] &&  x[i] < x[j+1] ){
                    sucess =0 ;
                    break;
                }
                if(x[i] > x[j] && x[i+1] < x[j] &&  x[i+1] > x[j+1] ){
                    sucess =0 ;
                    break;
                }
                if(x[i] > x[j+1] && x[i+1] < x[j+1] &&  x[i+1] >  x[j] ){
                    sucess =0 ;
                    break;
                }
                if(x[i] > x[j+1] && x[i+1] < x[j+1] &&  x[i] <  x[j] ){
                    sucess =0 ;
                    break;
                }
            }

        }
        if(!sucess)
            break;
    }
    if(!sucess){
        printf("yes\n");
    }
    else
        printf("no\n");
    
    return 0;
}
