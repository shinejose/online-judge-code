#include <stdio.h>
#define MAXN 3005
int numPrime;
int prime[MAXN];
int is_prime[MAXN];

void find_prime(int n){
    for(int i=2;i<n;i++){
        is_prime[i] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            is_prime[j]=0;
        }
    }
    for(int i=2;i<=n;i++){
        if(is_prime[i])
            prime[numPrime++] = i;
    }
}



int main(){
    int n;
    find_prime(MAXN-1);
    scanf("%d",&n);
    int ans=0;
    /* for(int i=0;i<numPrime;i++){ */
    /*     for(int j=i+1;j<numPrime;j++){ */
    /*         if(prime[i] * prime[j] <=n ) */
    /*             ans++; */
    /*     } */
    /* } */

    for(int i=1;i<=n;i++){
        int temp = i;
        int count =0;
        for(int j=0;prime[j] <= n ;j++){
            if((temp%prime[j])==0 )
                count++;
            while((temp %prime[j])==0){
                temp  /= prime[j];
            }
            if(count > 2)
                break;
        }
        if(count ==2 ){
            ans++;
        }
    }

    
    printf("%d\n",ans);
    
    return 0;
}
