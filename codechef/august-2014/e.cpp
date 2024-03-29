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


const int P = 1000000007;

int t,n;
int nn;
bitset<100> tshirts[10];
ll C[50][50];
int sum;

vector<vector<int>> c_dfs ;
vector<int> c_dfs_temp;
int flag[105];

void computeC() {
    C[0][0] =1;
    for(int i=1;i<50;i++){
        for(int j=0;j<=i;j++){
            if( j== 0 ) C[i][j] = C[i-1][j];
            else C[i][j] = (C[i-1][j]+C[i-1][j-1])%P ;
        }
    }
}

void dfs(int depth,int cur,vector<int> temp){
    if(depth == 0) {
        c_dfs.push_back(temp);
        return ;
    }
    for(int i=cur;i<n;i++){
        if(flag[i]) continue;
        temp.push_back(i);
        flag[i] =1;
        dfs(depth-1,i+1,temp);
        flag[i] =0;
        temp.pop_back();
    }
}



int main(){
    computeC();
    cin >> t;
    while(  t--){
        for(int i=0;i<10;i++) tshirts[i].reset();
        sum =0;
        scanf("%d\n",&n );
        string input; 
        for(int i=0;i<n;i++){
            getline(cin,input) ;
            vector<string> ids;
            string temp;
            for(int j=0;j<input.size();j++){
                if( input[j] == ' ' && !temp.empty() ){
                    ids.push_back(temp);
                    temp.clear();
                }
                else if(input[j] != ' ')
                    temp.push_back(input[j]) ;
            }
            if( !temp.empty())
                ids.push_back(temp);
            for(int j=0;j<ids.size();j++) tshirts[i].set(stoi(ids[j])-1 );
        }

        for(int i=0;i<n;i++) sum += tshirts[i].count();

        ll  ans  =1;
        for(int i=0;i<n;i++ ) ans = (ans * tshirts[i].count() )%P ;

        
        for(int i=2;i<=n;i++){
            memset(flag,0,sizeof(flag));
            c_dfs.clear();
            c_dfs_temp.clear();
            dfs(i,0,c_dfs_temp);
            int sign = 1 ;
            if(i%2 ==0 ) sign =-1; 
            for(int j=0;j<c_dfs.size();j++){
                int left = sum ;
                bitset<100> same = tshirts[c_dfs[j][0]] ;
                left -= tshirts[c_dfs[j][0]].count();
                for(int k=1;k<c_dfs[j].size();k++){
                    same &= tshirts[c_dfs[j][k]] ;
                    left -= tshirts[c_dfs[j][k]].count() ;
                }
                if( left ==0 ) left =1;
                ll sym =1;
                if(i>=3) {
                    sym =0;
                    for(int k=2;k<=i;k++){
                        if( k%2 ==0 ) sym = (sym+C[C[i][2]][k])%P ;
                        else sym = (sym-C[C[i][2]][k]+P)%P ;
                    }
                }
                ans = (ans + (sign* (  sym * same.count() * left ) + P )%P   )%P   ; 
            }
        }

        cout << ans <<endl;
        
    }
    return 0;
}





