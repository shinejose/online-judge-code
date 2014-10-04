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


int main(){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if( x1 == x2) {
        cout <<  x1 + (y2 - y1)<< ' '  << y1  << ' ' ;
        cout <<  x1 + (y2 - y1)<< ' ' << y2 << endl;
    }
    else if( y1 == y2 ){
        cout <<  x1 << ' '  << y1 + ( x2-x1)  << ' ' ;
        cout <<  x2 << ' ' <<  y2 + (x2 -x1)  << endl;
    }
    else if( abs( x1 -x2 )  == abs( y1- y2)){
        cout <<  x1 << ' '  << y2  << ' ' ;
        cout <<  x2 << ' ' <<  y1  << endl;
    }
    else
        cout << -1 << endl;
   
    return 0;
}









