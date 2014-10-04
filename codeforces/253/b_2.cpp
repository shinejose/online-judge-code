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
    int ans=n;

    for(int i=(len+n)/2;i>=0;i--){
        for(int j=0;j+i+i<=len+n;j++){
            bool ok = true;
            for(int k=0;k<i;k++){
                int index1 = j+k;
                int index2 = j+i+k;
                if( index1 >=len || index2 >=len )
                    continue;
                else {
                    if( str[index1] != str[index2] ){
                        ok=false;
                        break;
                    }
                }
            }
            if(ok){
                ans = i*2 ;
                cout<<ans;
                return 0;
            }
        }
    }
}
