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
int a[100005];


int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int sucess =1;
    int start =0 ;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1] && start ==0 ){
            if(a[i] <=a[0]){
                start = i;
                continue;
            }
            else {
                sucess =0;
                break ;
            }
        }
        if( start!=0){
            if(a[i] > a[0]){
               sucess =0;
               break;
            }
            if(a[i] <a[i-1]){
                sucess =0;
                break;
            }
                
        }
    }
    
    if(sucess) {
        cout << (n-start)%n<<endl;
    }
    else cout << "-1"<<endl;
    
    return 0;
}





