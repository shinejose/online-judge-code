#include <cstdio>
#include <iostream>
using namespace std;

int n,m;
int a[55][55];
int ans ;
int main(){
    cin >> n >> m;
    ans = 4;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf( "%d",& a[i][j]);
            if( a[i][j] ==1 && (i==n || i ==1 || j ==1 ||j ==m ))
                ans =2;
        }
    }
    printf("%d\n",ans);
    return 0;
}
