#include <cstdio>
#include <vector>
#include <map>
#include <tuple>
int n;
#define MAXN 50
int f[MAXN];
int fn;
std::map<int,std::tuple<int,int,int>> hash;
int main(){
    

    f[0] =0;
    f[1] =1;
    int count =0;
    for(int i=2;i<MAXN;i++){
        f[i] = f[i-1]+f[i-2];
        if(f[i]>=1000000000){
            fn = i-1;
            break;
        }
    }

    for(int i=0;i<=fn;i++){
        for(int j=0;j<=fn;j++){
            for(int k=0;k<=fn;k++){
                hash[f[i]+f[j]+f[k]]  = std::make_tuple(f[i],f[j],f[k]);
            }
        }
    }

    int n;
    scanf("%d",&n);
    auto temp = hash.find(n);
    if (temp != hash.end()){
        printf("%d %d %d\n",std::get<0>(temp->second),
               std::get<1>(temp->second),
               std::get<2>(temp->second));
    }
    else
        printf("I'm too stupid to solve this problem\n");
    
    
    
    
    
    return 0;
}
