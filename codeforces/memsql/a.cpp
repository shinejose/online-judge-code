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
string str;


char name[8][20] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"} ;




int main(){
    cin >> n >> str;
    for(int k=0;k<8;k++){
        int count =0;
        for(int i=0;i<n;i++){
            if(str[i] ==  name[k][i] || str[i] == '.' ){
                count++;
            }
        }
        if(count == n && n == strlen(name[k]) ){
            cout <<name[k] <<endl;
            break;
        }
    }
    
    return 0;
}






