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

const long  double PI = acos(-1.0);
const long double EPSILON = 2.7182818284590452353602874713527;


int n,m;
int a[105];
int f[105];

int main(){
    cin >> n >> m;
    int ans = -1;
    int index =0 ;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        f[i] = a[i]/m ;
        if(a[i]%m > 0 ){
            f[i]++;
        }
        if(f[i] >= ans) {
            ans=f[i];
            index = i;
        }
    }
    cout <<index +1 <<endl; 
    return 0;
}















