#include <stdio.h>
#include <iostream>


int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    int  a,b,x,y;
    scanf("%d%d%d%d",&a,&b,&x,&y);

    int d = gcd(x,y);
    x /= d;
    y /= d;
    int ans =std::min(a/x,b/y);
    if( ans ==-1 ){
        printf("0 0\n");
    }
    else
        printf("%d %d\n",ans*x,ans*y);

    return 0;
}
