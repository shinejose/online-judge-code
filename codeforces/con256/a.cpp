#include <cstdio>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include  <vector>
#include <string>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
#include <map>

using namespace std;

int a[3];
int sum_a;
int b[3];
int sum_b;
int n;

int main(){
    for(int i=0;i<3 ;i++){
        scanf ("%d",&a[i]);
        sum_a += a[i];
    }
    for(int i=0;i<3 ;i++){
        scanf ("%d",&b[i]);
        sum_b += b[i];
    }
    scanf("%d",&n);

    int na= sum_a /5 ;
    if( !(sum_a %5 ==0) )
        na ++ ;
    int nb = sum_b /10;
    if(!(sum_b%10 == 0))
        nb ++ ;
    if( na + nb <=n){
        printf( "YES\n" ) ;
    }
    else
        printf("NO\n") ;

    return 0;
}

