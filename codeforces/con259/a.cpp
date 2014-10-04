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




int n;



int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int len ;
            if( i <= (n-1)/2) 
                len = 2*i+1;
            else
                len = n - (i-((n-1)/2))*2;
            int start = (n - len) /2;
            int end = start + len -1;
            if(j >= start && j <=end){
                cout << "D";
            }
            else
                cout << "*";
        }
        cout << endl;
    }
    return 0;
}





