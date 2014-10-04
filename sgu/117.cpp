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
#include <utility>
#include <bitset>
using namespace std;

typedef long long  ll;
typedef unsigned long long ull;

typedef set<int>  setInt ;
typedef set<long long>  setLL;
typedef map<int,int> mapInt;
typedef map<long long,long long> mapLL;

class solution2{
public:
    template<typename   T > 
    set<T>  create_prime(T n) {
        set<T>  ret;
        vector<bool> isprime;
        isprime.assign(n+1,true);
        for(T i=2;i<=n;i++)
            for(int j=i+i;j<=n;j+=i)
                isprime[j]=false;
        for(T i=2;i<=n;i++)
            if(isprime[i])
                ret.insert(i);
        return ret;
    }

    template<typename  T,typename  N > 
    map<T,T>  prime_decompose(set<T> prime,N n){
        map<T,T>  ret;
        ret.clear();
        N t =n ;
        for(typename set<T>::iterator it=prime.begin();it!=prime.end() && (*it)*(*it) <= n ;it++){
            if( t % (*it) == 0) ret[*it] = 0 ;
            while ( t  % (*it) == 0 ){
                t /= (*it);
                ret[*it] ++;
            }
        }
        if( t!= 1  ) ret[t]=1;
        return ret;
    }

    bool test(int x,int m ,int k){
        setInt p = create_prime(100);
        mapInt kd = prime_decompose(p,k);
        mapInt ad = prime_decompose(p,x);
        
        for(mapInt ::iterator it =ad.begin();it!=ad.end();it++)
            it->second *= m;
        bool sucess =true ;
        for(mapInt ::iterator it = kd.begin();it!=kd.end();it++ ){
            if(ad.find(it->first) == ad.end() ||
               (ad.find( it->first)!=ad.end() &&  ad[it->first] < it->second ) ){
                sucess =false ;
                break;
            }
        }
        return sucess;
    }
    
    void MAIN(){
        int n , m, k;
        setInt p = create_prime(100);
        cin >>n>>m>>k ;
        int ans =0 ;
        mapInt kd = prime_decompose(p,k);
        for(int i=0;i<n;i++){
            int x ;
            scanf("%d",&x);
            mapInt ad = prime_decompose(p,x);
        
            for(mapInt ::iterator it =ad.begin();it!=ad.end();it++)
                it->second *= m;
            bool sucess =true ;
            for(mapInt ::iterator it = kd.begin();it!=kd.end();it++ ){
                if(ad.find(it->first) == ad.end() ||
                   (ad.find( it->first)!=ad.end() &&  ad[it->first] < it->second ) ){
                    sucess =false ;
                    break;
                }
            }
            if(sucess) ans ++;
        }
        cout << ans <<endl;
    }
};

class solution1 {
public:
    int ModularExp(int a,int b,int m)
        {
            int sum=1;
            for(;b;b>>=1,a=((ll)a*a)%m)  //若a*a超ll时用ModularMul(a,a,m);
                if(b&1)
                    sum=((ll)sum*a)%m;
            return sum;
        }
    bool  test(int x,int m,int k){
        int ans =0 ;
        if( ModularExp(x,m,k)  ==0 )
            return true;
    }
    void MAIN(){
        int n,m,k;
        cin >> n >> m >> k ;
        int ans =0 ;
        for(int i=0;i<n;i++){
            int x ;
            scanf ("%d",&x);
            if( ModularExp(x,m,k)  ==0 ) ans ++ ;
        }
        cout <<ans<<endl;
    }
};

class Random_Test{
public:
    void MAIN(){
        solution1 s1;
        solution2 s2;
        for(int i=1;i<1001;i++){
            for(int j=1;j<1001;j++){
                for(int k=1;k<1001;k++){
                    if( s1.test(i,j,k) != s2.test(i,j,k) ){
                        cout << i << ' ' << j << ' ' << k << '\n';
                        break;
                    }
                }
            }
        }
    }
}; 



int main(){
    solution2 s2;
    s2.MAIN();
    return 0;
    
}











