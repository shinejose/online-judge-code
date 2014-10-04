#include <cstdio>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int n,m;
int d[3005];

int main(){
    cin >>n>> m;
    for(int i=0;i<m;i++){
        scanf("%d",&d[i]);
    }
    sort(d,d+m);
    int sucess =1;
    for(int i=0;i<m;i++){
        if(d[i] == 1 || d[i] == n ){
            sucess =0;
            break;
        }
        if( i+2 < m && d[i] == d[i+1]-1 && d[i+1] == d[i+2] -1 ){
            sucess =0;
            break;
        }
    }
    if(sucess){
        printf("YES\n");
    }
    else
        printf("NO\n"); 
    
    return 0;
}










