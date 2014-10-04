// c header 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <memory.h>
// c++ header
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

typedef long long  ll;

int n,k;
int a[100005];


int main(){
    cin >> n >>k;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int ans =-1;
    int ans_index=-2;
    for(int i=0;i<k;i++){
        int sum =0;
        for(int j=i;;) {
            sum += a[j];
            j = (j+k)%n;
            if( j== i)
                break;
        }
        if(sum < ans || ans==-1){
            ans = sum ;
            ans_index= i;
        }
    }
    cout << ans_index+1 <<endl;
    
    
    return 0;
}





