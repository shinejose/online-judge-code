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
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

typedef long long  ll;

class BracketExpressions {
public:
    int x[5];
    char bracket[6]={'(',')','[',']','{','}'};
    int xn =0;
    int n;
    int sucess ;
    stack<char> s;
    void  dfs( int depth,string expression){
        if(sucess ) return ;
        if( depth==xn) {
            while(!s.empty()){
                s.pop();
            }
            for(int k=0;k<n;k++){
                if (!s.empty() && s.top() == '(' && expression[k] == ')'){
                    s.pop();
                    continue;
                }
                else if (!s.empty() && s.top() == '[' && expression[k] == ']'){
                    s.pop();
                    continue;
                }
                else if (!s.empty() && s.top() == '{' && expression[k] == '}'){
                    s.pop();
                    continue;
                }
                s.push(expression[k]);
            }
            if(s.empty()) {
                sucess =1;
                return;
            }
        }
        else {
            for(int j=0;j<6;j++){
                expression[x[depth]]=bracket[j];
                dfs(depth+1,expression);
            }
        }
    }
    string ifPossible(string expression){
        string possible = "possible";
        string impossible= "impossible";
        sucess =0 ;
        n =expression .size();
        for(int i=0;i<n;i++){
            if(expression[i] == 'X' ){
                x[xn++] = i;
            }
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        if(xn>0){
            dfs(0,expression);
        }
        else {
            for(int k=0;k<n;k++){
                if (!s.empty() && s.top() == '(' && expression[k] == ')'){
                    s.pop();
                    continue;
                }
                else if (!s.empty() && s.top() == '[' && expression[k] == ']'){
                    s.pop();
                    continue;
                }
                else if (!s.empty() && s.top() == '{' && expression[k] == '}'){
                    s.pop();
                    continue;
                }
                s.push(expression[k]);
            }
            
            if(s.empty()) {
                sucess =1;
            }
        }
        if(sucess ) {
            return possible;
        }
        else
            return impossible;
        
    }
};
 

int main(){
    return 0;
}





