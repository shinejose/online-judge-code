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




string n;



int main(){
    cin >> n;
    int base =1;
    int ans =0;
    for(int i=n.size()-1;i>=0;i--){
        ans = (ans + (base * ((n[i]-'0')%4))%4 ) %4 ;
        base = (base *10) %4; 
    }
    int m =( 1 + (int) pow(2,ans)+ (int)pow(3,ans)+(int)pow(4,ans)  )% 5 ;
    cout << m <<endl;
    return 0;
    
}





