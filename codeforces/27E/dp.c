#include <cstdio>
#include <iostream>
#include <memory.h>
#include <cmath>
int n ;
 double  dp[1005][10];
int p[10] ={2 ,3, 5, 7 ,11, 13, 17 ,19 ,23 ,29 };

int main(){
    for(int i=0;i<1005;i++){
        for(int j=0;j<10;j++){
            dp[i][j] = 1e100;
        }
    }
    for(int i=1;i<=1000;i++ ){
        for(int j=0;j<10;j++){
            if(i== 1 ) {
                dp[i][j] =1 ;
            }
            else {
                if( j ==0 ){
                    dp[i][j] =  std ::pow(p[j],i-1);
                }
                else {
                    for(int k=0;k<i;k++){
                        if(i % (k+1) ==0 && j!=0 ) {
                            dp[i][j] = std::min(dp[i][j] ,
                                                dp[i/(k+1)][j-1] *std::pow(p[j],k));
                        }
                    }
                }
            }
        }
    }

    int n ;
    scanf("%d" ,&n);
     double result =1e100;
    for(int i=0;i<10;i++){
        result  = std::min(result,dp[n][i]);
    }
    long long temp = result ;
    
    if( std::abs(result- temp) < std::abs(result - (temp+1)) ){
        std::cout << temp <<std::endl;
    }
    else {
        std::cout << temp+1  <<std::endl;
    }
    
    return 0;
}
