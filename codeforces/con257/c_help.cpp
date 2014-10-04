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


int n; 

map<int,int> count_floor; 

int main(){
    cin >> n ;
    for(int i=1;i<=n;i++){
        cout << "a["<< i << " ]="<< n /i << endl;
        count_floor  [n/i]  ++;
    }
    int count =0;
    for(auto it = count_floor.begin();it!=count_floor.end();it++){
        cout << it->first << " " << it->second<<endl;
    }
    cout << "count="<<count_floor.size()<<endl;

    for(int i=1; i<=n;i++){
        double x1 = (double)n/(i+1);
        double x2 =  (double) n/i;
        int ix1 = ceil(x1);
        int ix2 = floor(x2);
        if(ix1 == x1)
            ix1++;
        int num =0;
        
        if( ix1 == ix2 )
            num =1;
        else
            num = ix2 -ix1 +1;
        printf("[n/x]=%d   n/%d < x <= n/%d  (%lf,%lf]  %d \n",
               i,i+1,i,x1,x2  ,num ) ;
    }
    for(int i=1;i<n;){
        int next = n / (n /i) ;
        cout << i<<" " <<  next <<endl;
        i = next +1;
    }
    
    return 0;
}

















