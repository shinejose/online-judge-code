#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef unsigned long long ull;

int n;
int a[100005];
int b[100005];

vector<pair<int,int>> s;



int main(){
    cin >> n ;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s.push_back(make_pair(a[i],i-1));
    }
    int sucess=1;
    int start =0;
    int ind_start =0;
    int is_start =0 ;
    int end =0 ;
    sort(s.begin(),s.end()) ;
    
    for(int i =0;i<s.size();i++){
        if(is_start==1  && i - ind_start == start-get<1>(s[i]) ){
            end = get<1>(s[i]);
        }
        else if(is_start==0  && get<1>(s[i]) !=i ){
            start = get<1>(s[i]);
            is_start =1 ;
            ind_start = i;
        }
        else if( get<1>(s[i]) == i ){
            if(is_start==1 ) 
                is_start = 2;
            else if(is_start ==0){
                
            }
            else if(is_start ==2) {
                
            }
        }
        else{
            sucess =0 ;
            break;
        }
    }

        
    if(sucess ){
        printf("yes\n%d %d\n",end+1,start+1);
    }
    else
        printf("no\n");
    
    return 0;
}





