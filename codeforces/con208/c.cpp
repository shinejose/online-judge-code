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

int n;
vector<pair<int,int>> va;

int main(){
    cin >> n ;
    int count =0;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if( a ==0){
            sort(va.begin(),va.end(),[](const pair<int,int> &a,const pair<int,int> &b){
                    return get<0>(a) >get<0>(b);
                });
            int len = va.size();
            if(len>=3){
                for(int j=0;j<len;j++){
                    if(get<1>(va[2]) == j){
                        printf("pushStack\n");
                    }
                    else if(get<1>(va[1])==j){
                        printf("pushQueue\n" ) ;
                    }
                    else if(get<1>(va[0]) ==j){
                        printf("pushFront\n");
                    }
                    else
                        printf("pushBack\n");

                }
                printf("3 popStack popQueue popFront\n");

            }
            else if( len ==2 ) {
                printf("pushStack\n");
                printf("pushQueue\n" ) ;
                printf("2 popStack popQueue\n");
            }
            else if(len ==1 ){
                printf("pushStack\n");
                printf("1 popStack\n");
            }
            else {
                printf("0\n");
            }
            count =0;
            va.clear();
        }
        else {
            va.push_back(make_pair(a,count++));
        }
    }
    if(va.size()>0){
        sort(va.begin(),va.end(),[](const pair<int,int> &a,const pair<int,int> &b){
                return get<0>(a) >get<0>(b);
            });
        int len = va.size();
        if(len>=3){
            for(int j=0;j<len;j++){
                if(get<1>(va[2]) == j){
                    printf("pushStack\n");
                }
                else if(get<1>(va[1])==j){
                    printf("pushQueue\n" ) ;
                }
                else if(get<1>(va[0]) ==j){
                    printf("pushFront\n");
                }
                else
                    printf("pushBack\n");

            }

        }
        else if( len ==2 ) {
            printf("pushStack\n");
            printf("pushQueue\n" ) ;
        }
        else if(len ==1 ){
            printf("pushStack\n");
        }
        else {
        }
    }
    return 0;
}
