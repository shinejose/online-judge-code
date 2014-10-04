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
// c++11 header
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <thread>
#include <chrono>
#include <atomic>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;


class Targer{
public:
    vector<string> draw(int n ){
        vector<string> ans;
        for(int i=0;i<n;i++){
            string temp;
            for(int j=0;j<n;j++){
                temp.push_back(' ');
            }
            ans.push_back(temp);
        }
        int x = n /2;
        int y = n/2 ;
        for(int i=0;i<=n/2;i+=2) {
            int left = x - i;
            int right= x + i;
            int button =y +i;
            int top = y - i ;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if( j == top && k >= left && k <=right)
                        ans[j][k] = '#';
                    if( j == button && k >= left && k<=right)
                        ans[j][k] = '#';
                    if( k== left && j <= button && j >=top)
                        ans[j][k] = '#';
                    if( k == right &&  j <=button && j >=top)
                        ans[j][k] = '#';
                }
            }
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    return 0;
}









