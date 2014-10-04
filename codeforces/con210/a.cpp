#include <cstdio>
#include <iostream>

using namespace std;
int n,k;

int main(){
    cin >> n>> k ;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++ ){
            if(i ==j){
                printf("%d ",k);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
    return  0;
}
