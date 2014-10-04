// c header 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <memory.h>
// c++ header
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <iomanip>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;

ll n;
ll b[200005];

int main(){
    cin >> n ;
    ll minB,numMin=0;
    ll maxB,numMax=0;
    for(int i=0;i<n;i++) {
        cin >> b[i];
        if( i==0 ) minB= maxB = b[i];
        else {
            minB = min(b[i],minB);
            maxB = max(b[i],maxB);
        }
    }
    for(int i=0;i<n;i++)  {
        if( b[i] == maxB ) numMax ++ ;
        if( b[i] == minB)  numMin ++;
    }
    cout << maxB-minB << ' ' ;
    if( maxB != minB) cout << numMax * numMin << endl;
    else cout << n * (n-1)/2<<endl;
    
    return 0;
}









