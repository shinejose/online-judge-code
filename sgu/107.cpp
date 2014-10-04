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


int n;


const ll r = 1e9;
const ll MOD = 987654321;

void find_a_number() {
    int count =0;
    for(ull i=100000000;i<=999999999;i++){
        if( (i*i) % r== MOD ){
            cout <<i<<endl; ;
            cout << i*i <<endl;
            count ++;
        }
    }
    cout << "count =" << count <<endl;
}
void solution(){
    cin >> n ;
    if(n<=8)
        cout << 0 <<endl;
    else {
        if(n == 9 ){
            cout << 8 <<endl;
        }
        else {
            cout << 72 ;
            for(int i=0;i<n-1-9;i++)
                putchar('0');
            cout <<endl;
        }
    }
}

int main(){
    solution();
    return 0;
}





