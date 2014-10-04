#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;


class 
IncrementingSequence{
    public :
    int match[55][55];
    int flag[55];
    int flag2[55];
    int len ;
    string canItBeDone(int k, vector <int> A){
        len = A.size();
        memset(flag,0,sizeof(flag));
        memset(flag2,0,sizeof(flag2));
        sort(A.begin(),A.end());
        for(int i=0;i<len;i++){
            if( flag[A[i]] == 0 ) {
                flag[A[i]] =1 ;
                flag2[i] = 1 ;
            }
        }
        memset(match,0,sizeof(match));
        for(int i=0;i<len;i++){
            if(flag[i+1])
                continue;
            for ( int j=0;j<len;j++ ){
                if(flag2[j])
                    continue;
                if((i+1) >= A[j]   &&  ( (i+1) - A[j] )%k == 0 ){
                    flag[i+1] = 1;
                    flag2[j] = 1;
                    match[i+1][0] ++ ;
                    match[i+1][A[j]] ++;
                    break;
                }
            }
            if( match[i+1][0] == 0  ) {
                return "IMPOSSIBLE";
            }
        }
        return "POSSIBLE";
    }
};


int main(){
    int input[55] = {1,2,2,3,4,4,5,5,6,6,8,9,12,13,13,15,16,18,19,20 };
    vector<int> temp;
    for( int i = 0 ;i<20;i++ ) {
        temp.push_back(input[i]);
    }
    IncrementingSequence t;
    cout << t.canItBeDone(5, temp) ;
    return 0;
}






