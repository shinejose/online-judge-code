#include <cstdio>
#include <iostream>
int a,b,c;

#define MOD 1073741824
#define MAXP 101
int is_prime[MAXP];
int prime[MAXP];
int index[MAXP];
int numPrime;
void find_prime (int n){
    for(int i=2;i<=n;i++){
        is_prime[i] = 1 ;
    }
    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            is_prime[j] =0;
        }
    }
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            index[i] = numPrime;
            prime[numPrime++]=i;
        }
    }
}


int   d[MAXP][MAXP];

int main(){
    find_prime(MAXP-1);
    for(int i=1;i<=100;i++){
        int temp=i;
        for(int j=0;j<numPrime && prime[j] *prime[j] <= i ;j++){
            while( temp % prime[j]==0 ){
                d[i][j]++;
                temp /= prime[j];
            }
        }
        if(temp != 1 ) {
            d[i][index[temp]] ++;
        }
    }

    
    scanf("%d%d%d",&a,&b,&c);
    long long sum = 0;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                long long  muls=1;
                for(int p=0;p<numPrime;p++){
                    muls *= (long long) (d[i][p] +d[j][p] +d[k][p]+1) % MOD;
                }
                sum = (sum+muls)%MOD;
            }
        }
    }
    std::cout << sum <<std::endl;
    return 0;
}
