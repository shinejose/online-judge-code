#include <stdio.h>
int p[4];
int flag[4];
int index[4];
int a,b;

void dfs(int depth,int x,int *res){
    if(depth==5){
        if( x == ((((x % p[index[0]])%p[index[1]])%p[index[2]])%p[index[3]]) )
            (*res)++;
        return ;
    }
    else{
        for(int i=0;i<4;i++){
            if (flag[i])
                continue;
            flag[i] =  depth;
            index[depth-1] = i;
            dfs(depth+1,x,res);
            flag[i] = 0;
            index[depth-1] = 0;
        }
    }
}


int main(){
    for(int i=0;i<4;i++){
        scanf("%d",&p[i]);
    }
    scanf("%d%d",&a,&b);
    int count  =0 ;
    for(int i=a;i<=b;i++){
        int times =0;
        dfs(1,i,&times);
        if(times >=7 ){
            count ++;
        }
    }
    printf("%d\n",count);
    return 0;
}
