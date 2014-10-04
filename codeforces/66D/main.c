#include <stdio.h>
#include <iostream>

#define MAXN 1000

int is_prime[MAXN];
int numPrime;
int prime[MAXN];

void find_prime(int n ){
    for(int i=2;i<=n;i++){
        is_prime[i]= 1 ;
    }
    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            is_prime[j]= 0;
        }
    }
    for(int i =2;i<=n;i++){
        if(is_prime[i]){
            prime[numPrime++]=i;
        }
    }
}

#define BASE 10000
struct BigInteger{
    int element[105];
    int size;
}ans;

void big_integer_init_one(BigInteger *ans){
    ans->size=1 ;
    ans->element [0] = 1;
}

void big_integer_times_small(BigInteger *a,int b){
    long long  muls , r,  c;
    
    c = 0 ;
    for(int i=0;i<a->size ;i++){
        muls = (long long) a-> element[i]  * b  +c ;
         r = muls % BASE;
         c = muls / BASE;
         a->element[i] = r;
    }
    while( c != 0 ) {
        r = c % BASE;
        c = c / BASE;
        a->element[a->size++] = r;
    } 
}

int main(){
    find_prime(MAXN-1);

    int n ;
    scanf("%d",&n);

    if( n ==2) {
        printf("-1\n");
    }
    else {
        for(int i=0;i<n;i++){
            big_integer_init_one(&ans);
            for(int j=0;j<n;j++){
                if(i == j)
                    continue;
                big_integer_times_small(&ans,prime[j]);
            }
            printf("%d",ans.element[ans.size-1]);
            for(int i=ans.size-2; i>=0 ; i--){
                printf("%04d",ans.element[i]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
