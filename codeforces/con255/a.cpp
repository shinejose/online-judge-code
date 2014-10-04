#include <cstdio>
#include <cmath>
#include <memory.h>
#include <cstring> 
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
#include <functional>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

#define MAXN 305
int n,p;
int a[MAXN];
int b[MAXN];
int ans=-1;

void preprocess(){
    
}
void input(){
    int count =0;
    scanf("%d%d",&p,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        int temp = a[i]%p;
        if(b[temp] ==0   ){
            b[temp]=1;
        }
        else if( count ==0 ) {
            count ++;
            ans = i+1;

        }
    }
}

void solution(){
    
}

void output(){
    printf("%d\n",ans);
}

int main(){
    preprocess();
    input();
    solution();
    output();
    return 0;
}
