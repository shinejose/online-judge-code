#include <iostream>
#include <cstring>
#include <memory.h>
#include <cstdio>
using namespace std;

int a;
char s[4005];
int sum[4005];
int count[36005] ;

int main(){

    memset( count,0,sizeof(count ));
    memset( sum,0,sizeof(sum));
    cin >> a;
    scanf("%s",s+1);

    int len = strlen(s+1) ;
    sum[0] = 0 ;
    for(int i=1;i<=len;i++){
        sum[i] = sum[i-1] +(s [i] - '0');
    }
    int sum_count =0 ;
    for(int i=0;i<len;i++){
        for(int j=1;j+i<=len;j++){
            count[sum[j+i] -sum[j-1]] ++;
            sum_count++; 
        }
    }
    long long ans =0 ;
    for(int i=1;i<=len;i++){
        for(int j=i;j<=len;j++){
            int sum_ij = sum[j] - sum[i-1] ;
            if( sum_ij == 0 && a != 0 ){
                continue;
            }
            else if( sum_ij == 0 && a == 0 ){
                ans  +=sum_count;
            }
            else if( a % sum_ij == 0 && (a/sum_ij) <= 36000 ){
                ans += count[a/sum_ij] ; 
            }
        }
    }
    cout << ans<<endl;
    
    return 0;
}










