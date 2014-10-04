#include <stdio.h>
#define MAXN 1005
int n ;
int is_lucky(int n){
    for(int i = n ; i ; i/=10){
        if( !((i%10 ) == 4 || 
             (i%10 ) == 7 )) 
            return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    int ok =0;
    for(int i=n;i>=1;i--){
        if( is_lucky(i) && n%i== 0){
            ok = 1 ;
            break;
        }
    }
    if(ok){
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
