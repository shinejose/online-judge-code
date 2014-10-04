#include <cstdio>
#include <iostream>
using namespace std;
int n , k ;

int main(){
    cin >> n >> k;

    int t = n-k;
    if( t <= 0){
        printf("-1\n");
    }
    else {
        for(int i=1;i<=t;i++){
            if(i ==1 )
                printf("%d ",t);
            else
                printf("%d ",i-1);
        }
        for(int i=t+1;i<=n;i++){
            printf("%d ",i);
        }
    }
    
    
    return 0;
}
