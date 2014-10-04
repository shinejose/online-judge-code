#include <stdio.h>

#define MAXN 1005 
int is_prime[MAXN] ;
int prime[MAXN];
int numPrime ;


void  find_prime(int n){
    for(int i=2;i<=n;i++){
        is_prime[i] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            is_prime[j] = 0;
        }
    }
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime[numPrime++]= i; 
        }
    }
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    find_prime(n);

    int numNoldbash =0 ;
    for(int i=0;i<numPrime-1;i++) {
        int x = prime[i];
        int y = prime[i+1];
        if(is_prime[x+y+1]){
            numNoldbash++;
        }
    }
    if(numNoldbash >= k ){
        printf("YES\n");
    }
    else
        printf("NO\n");
    return 0 ;
}
