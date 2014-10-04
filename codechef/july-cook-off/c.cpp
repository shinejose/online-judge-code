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
typedef unsigned long long ull;

int n;

ull f[2001][35];
char ff[2001][2001];
int kn;

int main(){
    cin >> n ;
    for(int i=0;i<n;i++){
        scanf ("%s",ff[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ff[i][j] == '1') {
                int k = j/64;
                int r = j%64 ;
                f[i][k] |= ((ull)1 << r );
                kn = max(kn,k);
            }
        }
    }
    ull ans =0 ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && ff[i][j]=='0'  ){
                for(int k=0;k<=kn;k++){
                    if( f[i][k] & f[j][k] ){
                            ans++;
                            break;
                    }
                }
            }
        }
    }
    cout << ans <<endl;

    
    return 0;
}





