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
    for(int d =1;d <=1000;d ++){
        for(int n =1 ;n <=1000;n++){
            double k = (n + pow(2,d) -2.0) / (pow(2,d)+1) ;
            cout << setw(5) << d ;
            cout << setw(5)  << n ;
            cout << setw(10) << k <<endl;
        }
    }
    return 0;
}
















