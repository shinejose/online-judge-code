#include <cstdio>
#include <iostream>
using namespace std;

int n;
char number[15][20]={{'O','-','|','-','O','O','O','O'},
                     {'O','-','|','O','-','O','O','O'},
                     {'O','-','|','O','O','-','O','O'},
                     {'O','-','|','O','O','O','-','O'},
                     {'O','-','|','O','O','O','O','-'},
                     {'-','O','|','-','O','O','O','O'},
                     {'-','O','|','O','-','O','O','O'},
                     {'-','O','|','O','O','-','O','O'},
                     {'-','O','|','O','O','O','-','O'},
                     {'-','O','|','O','O','O','O','-'}
                     };

int main(){

    // for(int i=0;i<=9;i++){
    //     printf("%s\n",number[i]);
    // }
    cin >> n;
    if(n==0){
        printf("%s\n",number[n]);
    }
    else{
        while(n){
            printf("%s\n",number[n%10]);
            n/=10;
        }
    }
    
    
    return 0;
}
