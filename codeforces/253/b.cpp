#include <iostream>
#include <string>
#include <memory.h>
using namespace std;


int main(){
    string str;
    int n;
    cin >> str;
    cin >> n;
    int len = str.size();
    int ans=0;

    if( len == n )
        ans = 2*n;
    else if( len  < n ){
        if( (n-len)%2 ==0 )
            ans = len+n;
        else 
            ans = len+n -1;
    }
    else{
        ans = 2*n;
        for(int i=1; (i+n)*2 <= len+n  ;i++){
            bool ok = true;
            for(int j=0;j<i;j++){
                int start2 = len - i ;
                int start1 = len - i -n -1 ;
                if( str[start1+j] != str[start2+j] ){
                    ok = false;
                    break;
                }
            }
            if( !ok){
                break;
            }
            ans = 2*(n+i);
        }
        for(int k=ans/2;k+k<=len+n;k++){
            bool ok = false;
            for(int pos=0;pos+pos<=len+n;pos++){
                bool find = true;
                for(int i=pos;i<k+pos;i++){
                    int start1 = i;
                    int start2 = i+k;
                    if(str[start1] != str[start2] ){
                        find= false;
                        break;
                    }
                }
                if(find){
                    ok = true;
                    break;
                }
            }
            if(ok) {
                ans = k*2;
            }
        }
    }
        
    cout << ans;
    
    return 0 ;
}
