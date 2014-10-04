// c header 
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <memory.h>
// c++ header
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;


int n,m;


int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};


int main(){
    cin >> n >>m;
    if( !( n>=1 && n <=day[m-1] ) || !( m >=1 && m <=12) )
        cout << "Impossible"<<endl;
    else {
        int count =0 ;
        for(int i=0;i<m-1;i++){
            count += day[i];
        }
        count += n;
        int ans = (count-1) % 7;
        cout << ans+1 <<endl;
    }
    return 0;
}





