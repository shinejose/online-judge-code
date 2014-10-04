#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN =150005;
int n,k;
int h[MAXN];
int sum[MAXN];
int ans ;
int ans_index;

int main(){
    cin >> n >> k;
    sum[0] = 0;
    for(int i =1;i<=n;i++){
        scanf("%d",&h[i]);
        sum[i] = sum[i-1] + h[i];
    }
    
    ans =123456789;
    ans_index = 1;
    for(int i=1;i+k-1<=n;i++){
        if( ans >   sum[i+k-1]-sum[i-1]){
            ans = sum[i+k-1] -sum[i-1];
            ans_index = i;
        }
    }
    printf( "%d\n",ans_index);
    
    return 0;
}
