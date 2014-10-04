#include <stdio.h>
#include <memory.h>

int flag[5][5];
int flag2[5][5];
int mark[10];

int
dfs(int depth){
    int i,j,count,index;
    if(depth ==0){
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                flag2[i][j] = flag[i][j];
            }
        }
        
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                if(mark[i] && mark[j+5]){
                    flag2[i][j]=0;
                }
            }
        }
        for(i=0 ;i<10 ;i++){
            if(! mark[i] )
                continue;
            if ( i < 5){
                count=0;
                index=0;
                for(j=0;j<5;j++){
                    if(flag2[i][j]){
                        count ++;
                        index = j;
                    }
                }
                if( count >1 ){
                    return 0;
                }
                flag2[i][index]=0;
            }
            else {
                count=0;
                index =0;
                for(j=0;j<5;j++){
                    if(flag2[j][i-5]){
                        count ++;
                        index =j;
                    }
                }
                if( count >1 ){
                    return 0;
                }
                flag2[index][i-5]=0;
            }
        }
        count =0 ;
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                if(flag2[i][j]){
                    count++;
                }
            }
        }
        if(count ==1)
            return 1;
        else
            return 0;
    }
    for(i=0;i<10;i++){
        if(mark[i])
            continue;
        mark[i] = 1;
        if(!dfs(depth-1))
            mark[i] =0;
        else
            return 1;
    }
    return 0;
}

int
main(int argc,
     char *argv[]){
    int n;
    scanf("%d",&n) ;
    char card[10];
    char color[5] ={'R','G','B','Y','W'};
    int i,j;
    memset(flag,0,sizeof(flag));
    for(i=0;i<n;i++){
        scanf("%s",card);
        for(j=0;j<5;j++){
            if(card[0] == color [j]){
                flag[j][card[1]-'1'] ++;
            }
        }
    }
    for(i=0;i<=10;i++){
        memset(mark,0,sizeof(mark));
        if(dfs(i)) {
            printf("%d\n",i);
            break;
        }
    }
    
    return 0;
}
