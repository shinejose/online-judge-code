#include <cstdio>
#include <iostream> 
int n;
int main(){
    scanf("%d",&n);
    int a = n /10;
    int last  = n%10;
    int b =  (n / 100 ) *10 + last;
    printf("%d\n",std::max(a,std::max(b,n)));
    return 0;
}
