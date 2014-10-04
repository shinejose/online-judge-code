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
#include <unordered_set> 
#include <map>
#include <unordered_map> 
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
#include <bitset>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;



int n,m;
int first_win;

int f(int n,int m){
    int ans = 1;
    if( n == 1 || m==1 )
        ans =  1;
    else
        ans ^= f(n-1,m-1);
    return ans;
}

int main(){
    cin >> n >> m ;

    if(f(n,m))
        cout << "Akshat" << endl;
    else
        cout << "Malvika"<< endl;

    return 0;
}















