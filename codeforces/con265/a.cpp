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
string str;
string str2;

int main(){
  ios::sync_with_stdio(false);
  cin >> n >> str;
  int left =1 ;
  str2 = str;
  for(auto & i : str ) {
    if(left){
      if(i=='0') {
	i = '1';
	left --;
      }
      else {
	i ='0';
      }
    }
    else
      break;
  }
  
  int ans =0 ;

  for( int i =0 ;i<str.size(); i++ ) {
    if( str[i] != str2[i])
      ans ++;
  }
  cout <<ans;
  return 0;
}









