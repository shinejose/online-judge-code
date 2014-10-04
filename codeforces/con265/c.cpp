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
int n,p;
string str;

pair<bool,string> next_tolerable(string input,int cur){
    if( cur < 0 )             return make_pair(false,"NO");
    else if(cur ==  0 ){
        for(int i=input[cur]-'a'+1;i<p;i++){
            input[cur] = 'a' +i ;
            if(cur!= input.size())
                input[cur+1] = 'a' -1;
            pair<bool,string> ret = next_tolerable(input,cur+1);
            if(ret.first)
                return ret;
        }
        return make_pair(false,"NO");
    }
    else if(cur ==1){
        for(int i=input[cur]-'a'+1;i<p;i++){
            if(input[cur-1] != 'a'+i ){
                input[cur] = 'a' +i ;
                if(cur!= input.size())
                    input[cur+1] = 'a' -1;
                pair<bool,string> ret = next_tolerable(input,cur+1);
                if(ret.first)
                    return ret;
            }
        }
        pair<bool,string> ret = next_tolerable(input,cur-1);
        if(ret.first ==false)
            return make_pair(false,"NO");
        else
            return ret;
    }
    else if(cur <= input.size()) {
        for(int i=input[cur]-'a'+1;i<p;i++){
            if(input[cur-2] != 'a' +i  && input[cur-1] != 'a'+i ){
                input[cur] = 'a' +i ;
                if(cur!= input.size())
                    input[cur+1] = 'a' -1 ;
                pair<bool,string> ret = next_tolerable(input,cur+1);
                if(ret.first)
                    return ret;
            }
        }
        pair<bool,string> ret = next_tolerable(input,cur-1);
        if(ret.first ==false)
            return make_pair(false,"NO");
        else
            return ret;
    }
    else
        return make_pair(true,input);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> p >> str;

    cout << next_tolerable(str,str.size()-1).second << endl;
    
    return 0;
}









