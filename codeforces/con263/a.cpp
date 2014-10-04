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
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;

int n;
string board[105];
int dir[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) cin >> board[i];
    bool sucess =true ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int count =0 ;
            for(int k=0;k<4;k++){
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if( x < 0 || y < 0 || x>=n || y>= n ) continue;
                if(board[x][y] == 'o')
                    count ++ ;
            }
            if( count %2 !=0 )
                sucess =false;
        }
        if( !sucess )
            break;
    }
    if( sucess)  cout << "YES" <<endl;
    else cout << "NO"<< endl;
    
    return 0;
}









