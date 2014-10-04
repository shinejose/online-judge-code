#include <cstdio>
#include <cstring> 
#include <iostream>
using namespace std;

const int MAXN = 200000+5;

char str[MAXN];
char ans[MAXN];

int main(){
    scanf("%s",str);
    int len = strlen(str);
    int j =0 ;
    for(int i=0;i<len;i++){
        if(i == 0 ){
            ans[j++] = str[i];
        }
        else {
            if(j>=3 && ans[j-2] == ans[j-3] && str[i] ==ans[j-1]  ) {
                continue;
            }
            else if(j>=2  &&ans[j-2] ==  ans[j-1 ] && str[i] == ans[j-1] ) {
                continue;
            }
            ans[j++] = str[i];
        }
    }
    ans[j++]= 0 ;
    printf("%s\n",ans);
    return 0;
}
