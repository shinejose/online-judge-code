#include <cstdio>
#include <iostream>
#include <algorithm> 
using namespace std;


const int MAXN = 100005;
int n,m,a;
int b[MAXN];
int p[MAXN];
int r,s;
int compute(int r){
    long long  ret =0;
    for(int i = n-r, j=0; j < r; i++ ,j++ ){
        if(b[i] > p[j] ){
            continue;
        }
        else {
            ret += (long long) p[j] - b [i];
        }
    }
    if( a >=ret) {
        return 1 ;
    }
    else
        return 0;
}
int main(){
    cin >> n >> m>>a ;
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&p[i]);
    }

    sort(b,b+n);
    sort(p,p+m);

    r = s =0 ;


    int left =0;
    int right = min(n,m);
    while(left<=right ){
        int mid = (left +right ) / 2 ;
        if(compute(mid)){
            r = mid;
            left  =mid +1;
        }
        else
            right = mid-1;
    }
    long long  ret=0 ;
    for(int i = n-r , j=0; j < r; i++ ,j++ ){
        if(b[i] > p[j] ){
            s += p[j];
            continue;
        }
        else {
            s += b[i];
            ret += (long long) p[j] - b [i];
        }
    }
    s = (long long)s - (a -ret);
    if(s < 0){
        s =0 ;
    }
    printf("%d %d\n",r,r==0?0:s);
    
    return 0;
}









