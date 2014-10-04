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


int n,m;

char board[105][105];
char  ans[105][105];
char GOOD = '.';
char BAD = '-';
int dir[4][2]  = {{1,0},{-1,0},{0,-1},{0,1}};

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> board[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if((i+j)%2 ==1)
                ans[i][j] = 'W';
            else
                ans[i][j] = 'B';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( board[i][j] == BAD) {
                cout << BAD;
            }
            else
                cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}









