#include <stdio.h>
#include <string.h>

#define  MAXN 1000005 
char b[MAXN] ;
char n[ MAXN] ;
int c;


int big_mod(char a[],int m){
    int ans =0 ;
    int len = strlen(a);
    for(int i = len-1,b =1 ; i >=0; i-- , b= (long long)b*10%m){
        ans = ( (long long)ans +  ((long long) (a[i] -'0') * b ) % m )%m;
    }
    return ans;
}


int exp_big_mod(int a,char n[],int m){
    int len =strlen(n);
    int a_i_mod_m[10];
    for(int i=0;i<10;i++){
        if(i ==0 ){
            a_i_mod_m[i] = 1 ;
        }
        else{
            a_i_mod_m[i]= ((long long)a_i_mod_m[i-1]*a )%m;
        }
    }
    int ans = a_i_mod_m[n[len-1]-'0'] ;
    int a_10_mod_m = a ;
    for(int i = len-2;i>=0;i--){
        int temp=1;
        for(int j=0;j<10;j++){
            temp  = ((long long)temp *a_10_mod_m) % m;
        }
        a_10_mod_m = temp;
        temp =1 ;
        for(int j=0;j<n[i]-'0';j++){
            temp = ((long long) temp * a_10_mod_m) %m;
        }
        ans = ((long long) ans * temp  ) %m;

    }
    return ans;
}

void big_minus_1 (char b[]){
    int len_b =strlen(b);
    for(int i=len_b-1;i>=0;i--){
        if(b[i] != '0'){
            b[i]-=1;
            break;
        }
        else{
            b[i]='9';
        }
    }
}
int main(){
    scanf("%s %s %d",b,n,&c);
    
    int b_mod_c = big_mod(b,c);
    big_minus_1(n);
    int b_n_mod_c = exp_big_mod(b_mod_c,n,c);
    big_minus_1(b);
    int b_1_mod_c  = big_mod(b,c);
    int ans=((long long)b_1_mod_c *b_n_mod_c ) %c ;
    printf("%d\n",ans==0?c:ans);
    return 0;
}
