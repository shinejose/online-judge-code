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


class BigInteger
{
public:
    const ll  ELEMSYSTEM = 100000000;
    const ll  ELEMSYSTEMLEN = 8;
    vector<int> elem;
    BigInteger() {
        this->clear();
    }
    ~BigInteger(){
        this->clear();
    }
    int size() {
        return elem.size();
    }
    void clear() {
        elem.clear();
    }
    BigInteger(int x) {
        this->clear();
        elem.push_back(x);
    }
    BigInteger(ll x ) {
        this->clear();
        while(x >0 ){
            this->elem.push_back(x%ELEMSYSTEM);
            x = x / ELEMSYSTEM;
        }
    }
    BigInteger(string x){
        if(isInteger(x)) {
            int ELEMSYSTEMLEN = log10(ELEMSYSTEM);
            int count =0;
            int temp = 1;
            int sum =0;
            int start =0 ;
            if(x[0] == '-' || x[0] == '+' ) start =1 ;
            for(int i = x.size() -1; i>=start ; i--){
                count = count +1 ;
                temp = temp *10;
                sum  = sum + temp * (x[i]-'0');
                if( count  == ELEMSYSTEMLEN ) {
                    count = 0 ;
                    temp =1;
                    elem.push_back(sum);
                    sum =0 ;
                }
            }
        }
    }
    bool isInteger(string  x){
        int start =0;
        if(x[0] == '-' | x[0] =='+') start =1 ;
        for(int i=start ;i<x.size();i++)
            if(! (x[i] >= '0' && x[i] <= '9'))
                return false;
        return true;
    }
    
    string toString(){
        if(this->elem[0] ==0 && this->elem.size() ==1 )
            return "0";
        else if( this->elem.size() ==0 ){
            return "0";
        }
        string ret;
        for(auto &it : this->elem ) {
            int temp = it;
            int ELEMSYSTEMLEN = log10(ELEMSYSTEM);
            for ( int i =0 ; i<ELEMSYSTEMLEN ;i++){
                ret.push_back( abs(temp % 10 )+'0' ) ;
                temp  = temp / 10;
            }
        }
        for(auto it = ret.rbegin() ;it != ret.rend();it++ ){
            if( *it == '0' )
                ret.pop_back();
            else
                break;
        }
        if(this->elem[0] <0 )
            ret.push_back('-');
        std::reverse(ret.begin(),ret.end());
        return ret;
    }
    BigInteger clear_leading_zero() {
        for (auto it = this->elem.rbegin();it!=this->elem.rend();it++ ){
            if( *it  == 0 )
                this->elem.pop_back() ;
            else
                break;
        }
        return *this;
    }
    BigInteger operator + (BigInteger x){
        BigInteger ret;
        int minLen = min(x.size(),this->size());
        int maxLen = max(x.size(),this->size());
        if (x.size() == maxLen ) 
            for ( int i = elem.size() +1 ; i<=maxLen;i++)
                this->elem.push_back(0);
        else
            for ( int i = x.size() +1 ; i<=maxLen;i++)
                x.elem.push_back(0);
            
        ll r =0;
        ll c =0 ;
        for(int i=0;i<maxLen;i++){
            r = ((ll)this->elem[i] + x.elem[i] + c )  % ELEMSYSTEM;
            c = ((ll)this->elem[i] + x.elem[i] + c )  / ELEMSYSTEM; 
            ret.elem.push_back(  r  ) ;
        }
        while( c >  0 ) {
            r =  c  % ELEMSYSTEM;
            c =  c  / ELEMSYSTEM; 
            ret.elem.push_back(  r  ) ;
        }
        return ret.clear_leading_zero();
    }

    BigInteger negative(){
        for( auto &it  : this->elem ) it = -it;
        return *this;
    }
    BigInteger  operator = (BigInteger x) {
        this->elem = x.elem;
        return *this;
    }
    BigInteger operator - (BigInteger x){
        BigInteger ret;
        ret = (*this)  + x.negative() ;
        int len = ret.size();
        if(ret.elem[len-1] > 0){
            for(int i=0;i<len-1;i++) {
                if( ret.elem[i] < 0 ){
                    ret.elem[i]  += ELEMSYSTEM;
                    ret.elem[i+1] --;
                }
            }
        }
        else {
            for(int i=0;i<len-1;i++) {
                if( ret.elem[i] >  0 ){
                    ret.elem[i]  -= ELEMSYSTEM;
                    ret.elem[i+1] ++ ;
                }
            }
        }
        return ret;
    }
    BigInteger operator * (BigInteger x){
        
    }
    BigInteger operator * (ll x ){
        BigInteger ret ;
        ret.clear();
        int len =this->elem.size();
        ll r = 0;
        ll c = 0;
        for(int i=0;i<len;i++){
            r = (((ll)this->elem[i]) * x +c  ) % ELEMSYSTEM;
            c = (((ll) this->elem[i])* x +c  ) /ELEMSYSTEM;
            ret.elem.push_back( r );
        }
        while( c > 0 ){
            r = c % (ll) ELEMSYSTEM;
            c = c / (ll)ELEMSYSTEM;
            ret.elem.push_back(r);
        }
        return ret;
    }
    ll operator % (ll x) {
        ll ans =0;
        ll base = 1;
        for(auto it= this->elem.begin() ; it !=elem.end() ; it ++ ){
            ans  = (ans + (ll)(*it) * base) % x ;
            base = (base * ELEMSYSTEM) % x ;
        }
        return ans;
    }
    BigInteger operator / (int x ){
        BigInteger ret;
        ll remainder =0 ;
        for(int i = this->elem.size() -1 ; i>=0;i--){
            ll elem = ((ll)this->elem[i] +remainder) /x;
            if ( !(ret.size() == 0 && elem == 0)) 
                ret.elem.push_back( elem  ) ;
            remainder = (this->elem[i] + remainder)  %x;
            remainder = remainder * ELEMSYSTEM;
        }
        reverse(ret.elem.begin(),ret.elem.end());
        return ret;
    }
};
const ll MAXN = 1e10;
vector<pair<ll,BigInteger>> vf;
map<ll,BigInteger>  vm; 


BigInteger S4(ll n)
{
    if( n <= 0 ) return 0;
    
    BigInteger n_pow[6];
    BigInteger temp(1);
    for(int i=1;i<6;i++){
        temp = temp * n;
        n_pow[i] = temp;
    }
    return  (n_pow[5]*6  + n_pow[4]*15  +n_pow[3]*10 - n_pow[1] ) /30 ;
}

ll a[6] = {0,1,15,50,60,24};
ll gcd(ll a,ll b){
    return b == 0 ? a : gcd(b , a %b );
}
ll S4_2(ll n , ll m ){
    vector<ll> numerator,denomiantor ;
    ll ret =0 ;
    for(ll k = 5 ;k>=1;k--){
        numerator.clear();
        denomiantor.clear();
        for(ll i=0;i<k;i++){
            numerator.push_back(n-i);
            denomiantor.push_back(k-i);
        }
        for( auto & i  : denomiantor ){
            for(auto & j : numerator ){
                ll d = gcd(i,j);
                i = i / d ;
                j = j / d ;
                if( i == 1 ) break;
            } 
        }
        ll temp =1;
        for(auto & it : numerator ) {
            temp = (temp * it ) %m;
        }
        ret = (ret  + a[k] * temp ) %m;
    }
    return ret;
    
}

void preprocess(){
    vf.push_back(make_pair(0,BigInteger(0)));
    for(ll i =1 ,next;i<=MAXN; i= next+1) {
        ll value = MAXN/i;
        next = MAXN / (MAXN/i) ;

        vf.push_back(make_pair(next,S4(next)));
    }
    for( auto &it : vf)
        cout << it.first << "  " << it.second.toString() << endl; 
}

void solution(){
    int t ;
    cin >> t ;
    while( t-- ){
        ll n , m;
        cin >> n >> m ;
        vector <pair<ll,ll>> vn;
        for(ll i =1 ,next ; i <= n ;i = next +1 ){
            next = n / ( n / i )  ;
            vn.push_back ( make_pair( next, n/i)  ) ;
        }
        ll addLevel =0 ;
        ll  level =0;
        ll ans =0 ;
        for(int i = vn.size()-1 ;i >=0 ;i -- ){
            addLevel = vn[i].second   - level;
            level = level +addLevel;
            ans =  (ans + (S4_2(vn[i].first,m) * (addLevel %m ))) %m ;
        }
        cout << ans <<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    solution();
    return 0;
}









