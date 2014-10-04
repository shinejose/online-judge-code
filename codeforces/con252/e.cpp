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
#include <unordered_map>
#include <unordered_set>
#include <ctime>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;

int x,k,p;

int  program(int  x,int k,int p ){
    srand(time(NULL));
    int a =x ;
    for(int step =1 ;step <=k ; step ++ ){
        int rnd = rand()%100+1;
        if( rnd <= p){
            a  = a *2 ;
        }
        else
            a = a + 1; 
    }
    int s =0 ;
    while ( (a %2)  == 0 ){
        a = a / 2;
        s = s +1 ;
    }
    return s ;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> x >> k >> p ;
    cout << program(x,k,p) <<endl;
    return 0;
}









