#include <cstdio>
#include <cstring>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include  <vector>
#include <string>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
#include <map>

using namespace std;

char s[105],t[105];

int letters[50];
int lettert[50];

int main(){
    scanf("%s",s);
    scanf("%s",t);
    int lens = strlen(s) ;
    int lent = strlen(t);
    for(int i=0;i<lens;i++){
        letters[s[i]-'a'] ++;
    }
    for(int i=0;i<lent;i++){
        lettert[t[i]-'a'] ++;
    }
    

    int ans =0;
    if(lent > lens) {
        printf("need tree\n");
    }
    else if(lens== lent){
        ans =0 ;
        for(int i=0 ;i <26;i++){
            if(letters[i] != lettert[i]) {
                printf("need tree\n");
                ans =1 ;
                break;
            }
        }
        if(!ans){
            printf("array\n");
        }
    }
    else {
        ans =0;
        for(int i=0;i<26;i++){
            if(lettert[i] >letters[i]){
                ans =1;
                printf("need tree\n");
                break;
            }
        }
        if(!ans ){
            for(int i=0,j=0; i<lens  && j<lent;){
                if( s[i] == t[j]){
                    j ++ ;
                    i ++;
                    if(j==lent) {
                        ans =1 ;
                        break;
                    }
                }
                else {
                    i++;
                }
            }
            if(ans) {
                printf("automaton\n");
            }
            else {
                printf("both\n");
            }
        }
    }
    return 0;
}

