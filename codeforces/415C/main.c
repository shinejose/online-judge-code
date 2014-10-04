#include <cstdio>
int n , k;
int main(){
    scanf("%d%d",&n,&k);
    int m = (n-2)/2 ;
    int first = k - m ;
    if( ( n>1 && k == 0 ) || (first <=0 && k!=0 )  || (n ==1 && k!= 0) ){
        printf("-1\n");
    }
    else if ( n == 1 &&k==0 ){
        printf("%d\n",1);
    }
    else {
        printf("%d %d ",first,first*2);
        for(int i=0,j=1;i<n-2;i++ ){
            for(;1;j++){
                if(j== first ||j==first*2 ) {
                    continue;
                }
                printf("%d ",j++);
                break;
            }
        }
    }
    return 0;
}
