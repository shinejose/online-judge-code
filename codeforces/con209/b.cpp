#include <cstdio>
#include <iostream>

int n,k ;
int ans[50005*2];
int main(){
    std::cin >>n >> k;
    for(int i=0;i<2*n;i++){
        ans[i] = i+1;
    }
    for(int i=0;i<k;i++){
        std::swap(ans[2*i],ans[2*i+1]);
    }
    for(int i=0;i<2*n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
