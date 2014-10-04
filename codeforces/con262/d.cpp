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

ll l,r,k;
vector<ll> ans;
ll fs;
int main(){
    ios::sync_with_stdio(false);
    cin >> l  >> r >>k;
    ll x = l /4 ;
    ll rx = l %4 ;
    ll y = r /4 ;
    ll ry = r %4;
    ll xx = x ;
    ll yy = y;
    if( rx !=0 ) xx ++ ;

    if(k==1)  ans.push_back(l);
    else if(k==2 ){
        if( l ==r ){
            ans.push_back(l) ;
        }
        else if(r-l+1 ==2 ){
            if( (l ^ r)  < l ){
                ans.push_back(l) ;
                ans.push_back(r) ;
            }
            else ans.push_back(l);
        }
        else {
            if(r%4==0 || r%4 ==2  ){
                ans.push_back(r-1) ;
                ans.push_back(r-2) ;
            }
            else {
                ans.push_back(r) ;
                ans.push_back(r-1) ;
            }
        }
    }
    else if(k==3 ) {
        if( l ==r ){
            ans.push_back(l) ;
        }
        else if(r-l+1 ==2  ){
            if( (l ^ r)  < l ){
                ans.push_back(l) ;
                ans.push_back(r) ;
            }
            else ans.push_back(l);
        }
        else {
            bool sucess =false;
            for(ll i = l ; i < r ; i<<=1 ) {
                ll x = i^r;
                if( x >=l && x<=r && x!=i && x!= r ){
                    ans.push_back (i);
                    ans.push_back (x);
                    ans.push_back (r);
                    sucess =true;
                    break;
                }
            }
            if(! sucess ) {
                if(r%4==0 || r%4 ==2  ){
                    ans.push_back(r-1) ;
                    ans.push_back(r-2) ;
                }
                else {
                    ans.push_back(r) ;
                    ans.push_back(r-1) ;
                }
            }
        }
    }
    else if( k>=4 ) {
        if( l ==r ){
            ans.push_back(l) ;
        }
        else if(r-l+1 ==2 ){
            if( (l ^ r)  < l ){
                ans.push_back(l) ;
                ans.push_back(r) ;
            }
            else ans.push_back(l);
        }
        else {
            if ( xx < yy || (xx==yy && ry == 3 )  ) {
                ans.push_back(4*xx);
                ans.push_back(4*xx+1);
                ans.push_back(4*xx+2);
                ans.push_back(4*xx+3);
            }
            else if( rx <=2 && ry >=1 ){
                ans.push_back(4*xx) ;
                ans.push_back(4*xx+1) ;
                ans.push_back(4*xx-1) ;
                ans.push_back(4*xx-2) ;
            }
            else {
                bool sucess =false;
                for(ll i = l ; i < r ; i<<=1 ) {
                    ll x = i^r;
                    if( x >=l && x<=r && x!=i && x!= r ){
                        ans.push_back (i);
                        ans.push_back (x);
                        ans.push_back (r);
                        sucess =true;
                        break;
                    }
                }
                if(! sucess ) {
                    if(r%4==0 || r%4 ==2  ){
                        ans.push_back(r-1) ;
                        ans.push_back(r-2) ;
                    }
                    else {
                        ans.push_back(r) ;
                        ans.push_back(r-1) ;
                    }
                }
            }
        }
    }
    
    for( auto &it:ans ) fs ^= it;
    cout << fs <<endl;
    cout << ans.size()<<endl;
    for(auto &it : ans) cout << it << ' ' ; 
    
    
    return 0;
}









