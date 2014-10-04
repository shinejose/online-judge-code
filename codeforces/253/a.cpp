
#include <iostream>

#include <string>

#include <memory.h>
using namespace std;


int main(){
    string str;
    getline(cin,str);
    int len = str.size();
    int letters['z'-'a'+1];
    memset(letters,0,sizeof(letters));
    for(int i=0;i<len;i++ ){
        if(str[i] >= 'a' && str[i] <='z' )
            letters[ str[i]-'a'] =1 ;
    }
    int ans =0 ;
    for(int i='a';i<='z';i++){
        if(letters[i-'a'] )
            ans++;
    }
    cout << ans;
    
    return 0 ;
}
