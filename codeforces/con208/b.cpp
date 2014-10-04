#include <cstdio>
#include <cmath>
#include <cstdlib>
#include  <memory.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <tuple>
#include <stack>
#include <queue>
#include <vector>


using namespace std ;


typedef long long ll ;

const int MAXN = 100005;
int n ;
string  word[MAXN] ;
string encode;
string decode;
string en_left;
int main(){
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        cin >> word[i];
    }
    cin >> encode;

    for(int i=0,j=0;i<n;i++){
        decode += "<3" + word[i];
    }
    decode += "<3"; 

        
    // cout << encode  << endl ;
    // cout << decode << endl ;
    int len_encode = encode.size();
    int len_decode = decode.size();
    int i =0 ,j =0 ;
    for(;i<len_encode && j<len_decode;){
        if(encode[i] != decode[j]){
            en_left.push_back(encode[i]);
            i++;
        }
        else{
            i++,j++;
        }
    }

    for(;i<len_encode;i++){
        en_left.push_back(encode[i]);
    }

    
    // cout << j <<" " << len_decode<< endl;
    // cout << en_left << endl;
    

    if(j == len_decode ) {
        int len = en_left.size();
        int sucess =1;
        for(int i=0;i<len;i++){
            if(en_left[i] >='a' && en_left[i] <='z' )
                continue;
            if(en_left[i] >='0' && en_left[i] <='9')
                continue;
            if(en_left[i] == '<' || en_left[i] =='>')
                continue;
            sucess =0 ;
            break;
        }
        if(sucess ) {
            printf("yes\n");
        }
        else
            printf("no\n");
    }
    else {
        printf("no\n");
    }
    
    
    return 0;
}


