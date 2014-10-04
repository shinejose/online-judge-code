#include <cstdio>
#include <memory.h>
#include <iostream>

using namespace std;

int n,k;
int a[105];
int b[20];
int ans ;
int is_k_good(int n){
    memset(b,0,sizeof(b));
    while(n){
        b[n%10] =1 ;
        n /= 10;
    }
    for(int i =0;i<=k;i++){
        if(b[i]==0)
            return 0;
    }
    return 1;
}
int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ans = 0 ;
    for(int i=0;i<n;i++){
        if( is_k_good(a[i]) )
            ans ++;
    }
    printf("%d\n",ans);
    return 0;
}
