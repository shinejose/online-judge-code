#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN =100005;
int is_prime[MAXN];
int prime[MAXN];
int numPrime;
void find_prime(int n){
    for(int i=2;i<=n;i++){
        is_prime[i]= 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            is_prime[j] = 0;
        }
    }
    for(int i=2;i<=n;i++){
        if(is_prime[i])
            prime[numPrime++] = i;
    }
}

int n,k;
int main(){
    
    cin >> n>>k;
    find_prime(n);
    int t = n-k;
    if( n<1 )
        printf("-1\n");
    else if( n ==1 ){
        if( k == 0 ){
            printf("1\n");
        }
        else 
            printf("%d\n",-1);
    }
    else if(n==2){
        if(k==1){
            printf("1 2\n");
        }
        else if(k ==0 ) 
            printf("2 1\n",-1);
        else 
            printf("-1\n");
    }
    else if(n==3){
        if(k==2 ) {
            printf("1 2 3\n");
        }
        else if(k==1){
            printf("2 1 3\n");
        }
        else if(k ==0 ) 
            printf("1 3 2\n",-1);
        else 
            printf("-1\n");
    }
    else if(t < 1 )
        printf("-1\n");
    else if( t ==1){
        for(int i=1;i<=n;i++){
            printf("%d ",i);
        }
    }
    else if ( t ==2){
        printf("4 2 3 1 ");
        for(int i=5;i<=n;i++)
            printf("%d ",i);
    }
    else if( t ==3 ){
        printf("1 3 2 ");
        for(int i=4;i<=n;i++)
            printf("%d ",i);
    }
    else if( numPrime < t-2 ){
        printf("-1\n");
    }
    else if ( numPrime ==t-2){
        printf("%d %d ",4,prime[t-2-1]);
        int index =0 ;
        for(int i=3;i<=n;i++){
            if(index < t-1 && is_prime[i]){
                printf("%d ",prime[index++]);
            }
            else if(i==4){
                printf("1 ");
            }
            else {
                printf("%d ",i);
            }
        }
    }
    else {
        printf("%d %d %d %d ",4,prime[t-3],2,1);
        int index =1 ;
        for(int i=5;i<=n;i++){
            if(index <= t-4 &&  is_prime[i]){
                printf("%d ",prime[index++]);
            }
            else {
                printf("%d ",i);
            }
        }
    }
    return 0;
}










