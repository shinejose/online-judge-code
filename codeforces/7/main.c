#include <stdio.h>
#include <iostream> 

/* Time: O(log(b)) */
/* d = ax + by = bx'+(a%b)y' = ay' + b(x'-[a/b]y')  */
/* x = y'  */
/* y = x' - [a/b]y' */
int exgcd_32(int a,int b,int *x,int *y){
    if(b==0){
        *x = 1 ;
        *y = 0 ;
        return a;
    }
    else {
        int d = exgcd_32(b,a%b,x,y);
        int xpi = *x;
        int ypi = *y;
        *x = ypi;
        *y = xpi  - (int)(a / b )  * ypi ;  
        return d;
    }
}
long long  exgcd_64(long long  a,long long  b,long long  *x,long long  *y){
    if(b==0){
        *x = 1 ;
        *y = 0 ;
        return a;
    }
    else {
        long long  d = exgcd_64(b,a%b,x,y);
        long long  xpi = *x;
        long long  ypi = *y;
        *x = ypi;
        *y = xpi  - (long long )(a / b )  * ypi ;  
        return d;
    }
}

int
main(int argc,
     char *argv[]){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int n = -c;
    long long  x,y;
    long long  d =  exgcd_64(a,b,&x,&y);
    if( n % d  != 0){
        printf("-1\n");
    }
    else {
        long long  q = n/d ;
        long long xpi = q *x;
        long long ypi = q *y;
        std::cout << xpi << " " << ypi<< std::endl;
    }
    return 0;
}
