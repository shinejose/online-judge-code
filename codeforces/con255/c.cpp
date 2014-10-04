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

#define MAXN 100005
int n;
int a[MAXN];
int l[MAXN];
int r[MAXN];
int ans;



void preprocess(){
}
void input(){
    scanf ("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void solution(){
    int count ;
    for(int i=0;i<n;i++){
        if(i ==0 ){
            count =1;
        }
        else if(a[i] > a[i-1]  ){
            count ++;
        }
        else
            count =1;
        l[i] = count;
        // printf("l[%d]=%d \n",i,l[i]);
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            count =1;
        }
        else if(a[i] < a[i+1] ){
            count++;
        }
        else
            count =1;
        r[i] = count;
        // printf("r[%d]=%d \n",i,r[i]);
        
    }

    if(n==1){
        ans = 1;
    }
    else {
        ans = max(r[1]+1,l[n-2]+1);
        for(int i=1;i<n-1;i++){
            if(a[i-1] + 1 < a[i+1]){
                ans = max(ans,l[i-1]+1+r[i+1]);
            }
            else {
                ans = max(ans,max(l[i-1]+1,1+r[i+1]));
            }
        }
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
