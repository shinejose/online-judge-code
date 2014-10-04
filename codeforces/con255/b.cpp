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

#define MAXN 1000005
char s0[MAXN];
int k;
int w[27];
int maxs;
int maxindex;
int ans =0;

void preprocess(){
    
}
void input(){
    scanf("%s",s0);
    scanf("%d",&k);
    for(int i=0;i<26;i++){
        scanf("%d",&w[i]);
        if( w[i]> maxs) {
            maxs= w [i] ;
            maxindex = i;
        }
    }
}

void solution(){
    int len = strlen(s0);
    for(int i=0;i<len;i++){
        ans += w[s0[i]-'a'] * (i+1);
    }
    for(int i=0;i<k;i++){
        ans += (maxs  * (len+i+1));
    }
    
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
