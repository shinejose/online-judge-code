#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


#define MAXN 100005

struct Item{
    int w;
    int  c;
    double value;
};
Item one[MAXN] ;
Item two[MAXN];
Item item[MAXN];
long long ans[2*MAXN];

bool cmp( Item a ,Item b){
    return a.c > b.c ; 
}

bool cmp2( Item a,Item b){
    if( a.value == b.value) {
        return a. w < b.w ;
    }
    else
        return a.value > b.value;
}


int main(int argc,
         char *argv[]){
    int n;
    int M =0;

    scanf("%d",&n);
    int n1, n2;
    n1 =n2 = 0 ;
    for(int i=0;i<n;i++){
        int w,c;
        scanf("%d%d",&w,&c);
        item[i].w = w ;
        item[i].c = c;
        item[i].value = (double)c/w;
        if(w==1){
            one[n1].value=(double)c/w;
            one[n1].w = w;
            one[n1++].c= c ;
        }
        else if(w==2){
            two[n2].value=(double)c/w;
            two[n2].w = w;
            two[n2++].c= c ;
        }
        M += w;
    }
    sort(one,one+n1,cmp);
    sort(two,two+n2,cmp);
    sort(item,item+n,cmp2);

    int sw = 0;
    long long sc =0;
    int pos1 =0;
    int pos2 =0 ;
    for(int i=0;i<n;i++){
        if( item[i].w ==2 ) {
            ans[sw+1] = ans[sw];
            if(pos1 < n1 && sc+one[pos1].c > ans[sw+1] ){
                ans[sw+1] = sc + one[pos1].c;
            }
            if( pos1  > 0 && ans[sw]-one[pos1-1].c +two[pos2].c > ans[sw+1]   ){
                ans[sw+1] = ans[sw] - one[pos1-1].c + two[pos2].c;
            }
            pos2 ++;
        }
        else {
            pos1 ++;
        }
        sw += item[i].w ;
        sc += item[i].c;
        ans[sw] = sc;
    }
    for(int i=1;i<=M;i++){
        printf("%lld ",ans[i]);
    }
    
    return 0;
}
