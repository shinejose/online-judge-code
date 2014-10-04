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
class Jumping{
public:
    string ableToGet(int x, int y, vector <int> jumpLengths){
        bool isSucess =false ;
        int numJump = jumpLengths.size();
        int posibleIner = jumpLengths[0];
        int posibleOuter = jumpLengths[0];
        for(int i=1;i<numJump;i++){
            posibleIner = max ( 0 , posibleIner-jumpLengths[i]);
            posibleOuter += jumpLengths[i];
        }
        if(  x * x + y * y >= posibleIner * posibleIner &&
             x * x + y * y <= posibleOuter * posibleOuter)
            return "Able";
        else
            return "Not able";
             
    }
};

int main(){
    ios::sync_with_stdio(false);
    return 0;
}









