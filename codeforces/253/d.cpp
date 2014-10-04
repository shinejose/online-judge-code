#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;


bool cmp(double a,double b){
    return a > b ;
}

int main(){
    int n;
    cin >> n;
    vector<double> p(n,0) ;
    for(int i=0;i<n;i++){
        cin >> p[i] ; 
    }
    sort(p.begin(),p.end(),cmp);
    double ans = p[0];
    for(int i=2;i<=n;i++){
        double sum =0;
        for(int j=0;j<i;j++){
            double temp=p[j];
            for(int k=0;k<i;k++){
                if(k == j )
                    continue;
                temp *= (1.0-p[k]);
            }
            sum += temp;
        }
        if(  sum  >ans)
            ans =sum ;
    }
    printf("%.9lf",ans);
    return 0 ;
}
