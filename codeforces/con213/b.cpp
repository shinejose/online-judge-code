#include <iostream>
#include <vector> 
using namespace std;

int n;
int main(){
    cin >> n;
    vector<int> a(n);
    vector<int> is_fibo(n,0);
    vector<int> len(n,0);
    for(int i=0 ;i<n;i++){
        cin >> a [i] ;
    }
    int ans =min(2,n);
    is_fibo[0] = 0;
    is_fibo[1] = 0;
    for(int i=2;i<n;i++){
        if( a[i] == a[i-1] + a[i-2 ])
            is_fibo[i] = 1;
        else
            is_fibo[i] = 0;
    }
    int start =0;
    for(int i=2;i<n;i++){
        if(is_fibo[i-1] && is_fibo[i]){
            len[i] = len[i-1]+1;
        }
        else if(is_fibo[i]){
            len[i] = 3;
        }
        else
            len[i] =0;
        ans = max(ans,len[i]);
    }
    cout << ans <<endl;
    
    return 0;
}
