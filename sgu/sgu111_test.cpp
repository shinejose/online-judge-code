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



void test(){
    int n = 5000 ;
    for(int i=0;i<n;i++){
        cout << '9';
    }
    cout << "\n";
}
void fast(){
    ll  n =1;
    for(int i=1;i<16;i++){
        n *=10;
        cout << setw(2) << i << setw(20) << n ;
        cout << setw(20) << (n/9.0)*pow((n/9.0),1.59);
        cout << setw(20) << n * log2(n);
        cout << setw(20) << n *log2(n) * n * log2(10) ;
        cout << endl;
    }

}
int main(){
    return 0;
}









