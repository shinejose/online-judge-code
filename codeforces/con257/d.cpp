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
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

typedef long long  ll;


int n;
vector<pair<int,int>>ans;
vector<int> left_even;
map<int,int> flag;


int main(){
    cin >> n;
    for(int i=3;i<=n/2; i++){
        int cnt =0 ;
        for(int j=i;j<=n;j+=i) {
            if(flag.find(j) == flag.end() ){
                cnt++;
            }
        }
        if(cnt % 2 == 1 ){
            left_even.push_back(i+i);
            flag[i+i] = 1;
        }
        deque <int> temp;
        for(int j=i;j<=n;j+=i) {
            if(flag.find(j) == flag.end() ){
                flag[j] = 1;
                temp.push_back(j);
                if(temp.size()%2 == 0){
                    ans.push_back(make_pair(temp[0],temp[1])) ;
                    temp.pop_front();temp.pop_front();
                }
            }
        }

    }
    for(int i=2;i<=n;i+=i){
        if(flag.find(i) == flag.end())
            left_even.push_back(i);
    }
    int m=left_even.size()/2;
    for(int j=0;j<m;j++ ){
        ans.push_back(make_pair(left_even[2*j],left_even[2*j+1]));
    }
    cout << ans.size() << endl;
    for(auto i = ans.begin();i!=ans.end();i++){
        printf("%d %d\n",get<0>(*i),get<1>(*i));
    }
    return 0;
}





