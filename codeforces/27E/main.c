#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>


#define MAXN 4000

std::vector<int > nd[1005];

int n;

int is_prime[MAXN];
int prime[MAXN];

int numPrime;




void find_prime(int n){
    
    for(int i=2;i<=n;i++){
        is_prime[i] =1 ;
    }
    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            is_prime[j] =0;
        }
    }
    
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime[numPrime++]=i;
        }
    }
}


void factoring(){
    for(int i=1 ;i<=1000;i++){
        for(int j=2;j<=i;j++){
            if(i%j == 0 ){
                nd[i].push_back(j);
            }
        }
    }
}

std::vector<int> ans;
long double result=1e100;
void dfs(int depth,int last,int left){
    if(left == 1 ){
        int size = ans.size();
        long double temp  = 1.0;
        for(int i=0;i<size;i++){
            temp  *= (long double)pow(prime[i],ans[i]-1);
        }
        if( temp < result )
            result = temp;
    }
    else {
        int len = nd[left].size();
        for(int i=0;i<len;i++){
            if(nd[left][i] <=last ) {
                ans.push_back(nd[left][i]);
                dfs(depth+1,nd[left][i],left / nd[left][i]);
                ans.pop_back();
            }
        }
    }
}


int main(){
    find_prime(MAXN-1);
    factoring();
    scanf("%d",&n);
    dfs(0,n,n);
    long long temp = result;

    if( std::abs(result- temp) < std::abs(result - (temp+1)) ){
        std::cout << temp <<std::endl;
    }
    else {
        std::cout << temp+1  <<std::endl;
    }

    

    return 0;
}




