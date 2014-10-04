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


const int INF = 500;
int t,n,m;
map<int,deque<int> > timestamps;
int q[405];

class Node {
    public:
    int next_ts;
    int people;
    Node() {
        
    }
    Node(int ts,int p ){
        next_ts =ts;
        people =p;
    } 
    bool operator <  (const Node & tmp ) const {
        return next_ts > tmp.next_ts;
    }
};
deque<Node> tables;

int main(){
    cin >> t ;
    while(t--){
        tables.clear();
        timestamps.clear();
        int ans =0 ;
        
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int x ;
            cin >> x ;
            timestamps[x].push_back(i);
            q[i]= x;
        }
        for(int i=0;i<m;i++){
            int is_find=0;
            for(int j=0;j<tables.size();j++){
                if(tables[j].people == q[i]){
                    timestamps[q[i]].pop_front();
                    tables[j].next_ts = timestamps[q[i]].front();
                    is_find=1 ;
                    break;
                }
            }
            if(!is_find) {
                if(tables.size() == n) {
                    tables.pop_front();
                }
                timestamps[q[i]].pop_front();
                if(timestamps[q[i]].size() ==0 )
                    tables.push_back(Node(INF,q[i]));
                else 
                    tables.push_back(Node(timestamps[q[i]].front(),q[i]));
                ans ++ ;
            }
            sort(tables.begin(),tables.end());
        }
        cout << ans<<endl;
    }
    return 0;
}





