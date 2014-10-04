#include <stdio.h>
#include <algorithm>
#define MAXN  105
int a[MAXN];

int main(){
    int n;
    int sum =0;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
        sum +=a[i];
    }
    std::sort(a,a+n,[](const int &a,const int &b){
            return a >b ; 
        });
    int ans=0;
    if(sum % 2 ==1 ){
        printf("%d\n",sum);
    }
    else {
        for(int i=n-1;i>=0;i--){
            if(a[i] %2 ==1){
                ans = sum - a[i];
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
