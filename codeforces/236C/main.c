#include <cstdio>
#include <iostream> 
long long  n ;
long long  gcd(long  long  a,long long  b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    std::cin >> n;
    if(n>=3){
        long long  ans =-1;
        for(int i=n-2;i>=1;i--){
            long long  d = gcd(n*(n-1),i) ;
            long long  temp = n*(n-1) * i / d;
            if(temp >ans )
                ans = temp;
        }
        if( n%2 == 0 ){
            if(  (n-1) * (n-2) *(n-3 ) > ans) {
                ans =  (n-1) *( n-2) * (n-3);
            }
        }
        std::cout <<  ans << std::endl;
    }
    else
        std::cout << n<<std::endl;
    return 0;
    
}

