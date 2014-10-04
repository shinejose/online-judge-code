#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <queue>

using namespace std;


#define MAXN 500005
int a[MAXN];
pair<int,int> p[MAXN];
int pr[MAXN],ne[MAXN];

int
main(int argc,
     char *argv[]){
    int n,i ;

    scanf("%d",&n);
    for( i=0;i<n ;i++){
        scanf("%d",&a[i]);
        p[i]= make_pair(a[i],i);
        pr[i] = i-1;
        ne[i] = i+1;
    }

    
    
    sort(p,p+n);

    int low =0,high = n-1;
    long long ans =0;
    for(int i=0;i<n-2;i++){
        int j =p[i].second;
        if(j == low) {
            ans += p[i].first;
            low = ne[j];
            continue;
        }
        if(j==high) {
            ans += p[i].first;
            high = pr[j];
            continue;
        }
        ans+=min(a[pr[j]],a[ne[j]]);
        ne[pr[j]] =ne[j];
        pr[ne[j]]= pr[j];
    }
    printf("%I64d\n",ans);
    
    return 0;
}
