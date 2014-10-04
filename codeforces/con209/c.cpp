#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define P 1000000007

int  n,x;
int a[100005];
long long  s[100005];
long long  sum_a ;

int a_n_mod(int x,long long n ,int p){
    int ans =1;
    for(long long b = x;n;n>>=1, b=(b*b)%p ) {
        if( n&1){
            ans = (ans*b)%p;
        }
    }
    return ans;
}
typedef long long li;
const li mod = 1000000007;
li bpow(li x, li v) {	
	if (v == 0)
		return 1 % mod;

	if (v % 2 == 1)
		return (x * bpow(x, v - 1)) % mod;

	li r = bpow(x, v / 2);

	return (r * r) % mod;	
}

int main(){
    cin >> n >> x ;
    sum_a =0 ;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum_a += (long long)a [i];
    }
    for(int i=0;i<n;i++){
        s[i] = sum_a - a[i] ;
    }
    sort(s,s+n,[](const int &a,const int &b){
            return a> b ; 
        });
    long long v = s[n-1];
    int count  =0 ;
    for(int i=n-1;i>=0;i--){
        if(s [i] == v ){
            count ++;
        }
        else {
            if( count != 0 && count % x ==0 ){
                n = (n-count );
                count = count / x ;
                v ++ ;
                i ++;
            }
            else {
                // printf("%d\n",a_n_mod(x,min(sum_a,v),P));
                break;
            }
        }
    }
    while( count !=0  && count % x ==0 ){
        count = count / x;
        v++ ;
    }
    cout << a_n_mod(x,min(sum_a,v),P)<<endl;
    return 0;
}






