#include <cstdio>
#define MAXN 505
int n,m;
int a[MAXN ][MAXN] ;
int ans;

#define MAXP 100005
int is_prime[MAXP];
int prime[MAXP];
int index[MAXP];
int numPrime;
void find_prime(int n){
    for(int i=2;i<=n;i++){
        is_prime[i] =1;
    }
    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            is_prime[j] =0;
        }
    }
    for(int i=2;i<=n;i++){
        if(is_prime[i]) {
            prime[numPrime++]=i;
        }
        index[i] = numPrime-1;

    }
}

void input(){
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void solution(){
    index[1] = -1;
    ans = 100000000;
    /* row  */
    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=0;j<m;j++){
            if(!is_prime[a[i][j]]){
                temp += prime[index[a[i][j]]+1] - a[i][j] ;
            }
        }
        if(temp < ans)
            ans = temp;
    }
    /* column */
    for(int i=0;i<m;i++){
        int temp=0;
        for(int j=0;j<n;j++){
            if(!is_prime[a[j][i]]){
                temp  += prime[index[a[j][i]]+1] - a[j][i] ;
            }
        }
        if(temp < ans)
            ans = temp;
    }
    printf("%d\n",ans);
}
void precals(){
    find_prime(MAXP -1);
}    
int main(){
    precals();
    input();
    solution();
    return 0;
}
