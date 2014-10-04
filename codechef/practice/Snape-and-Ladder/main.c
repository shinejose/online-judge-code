#include <stdio.h>
#include <math.h>

int
main(int argc,
     char *argv[]){
    int cases;
    int b, ls;

    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        scanf("%d%d",&b,&ls);
        double min,max;
        min = sqrt((double)ls*ls - b*b ) ;
        max = sqrt((double)ls*ls + b*b) ;
        printf("%lf %lf\n",min,max);
    }
    return 0;
}
