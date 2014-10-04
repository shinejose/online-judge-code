#include <stdio.h>
#define MAXN 20005
int t[MAXN];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf ("%d",&t[i]);
    }
    int ans = -10000000;
    for(int i=0; 3*(i+1) <=n ;i++){
        if( n %(i+1) != 0)
            continue;
        for(int j =0; j<=i; j++){
            int sum =0;
            for(int k=j;k<n;k+=i+1) {
                sum += t[k];
            }
            if(sum >ans){
                ans = sum;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
