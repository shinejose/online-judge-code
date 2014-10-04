#include <cstdio>
#include <cmath>
#include <iostream>

#define MAXN 1234567
int is_prime[MAXN];
int prime[MAXN] ;
int numPrime;

void find_prime(int n){
    for(int i=2;i<=n;i++){
        is_prime[i] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            is_prime[j] =0 ;
        }
    }
    for(int i=2;i<=n;i++){
        if(is_prime[i])
            prime[numPrime++] = i;
    }
}


int n;
int main(){
    find_prime(MAXN-1) ;
    scanf("%d",&n) ;
    for(int i=0;i<n;i++){
        long long x;
        std::cin >> x ;
        int root= sqrt (x);
        
        if( (long long) root * root == x && is_prime[root]  ){
            printf("YES\n") ;
        }
        else {
            printf("NO\n");
        }
    }
}
