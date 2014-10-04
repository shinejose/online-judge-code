
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;


class 
IncrementingSequence{
    public :
    string canItBeDone(int k, vector <int> A){
        string fail = "IMPOSSIBLE";
        string sucess = "POSSIBLE";
        int len = A.size();
        vector<int> flag(len,0);
        for(int i=1;i<=len;i++){
            int m = i ;
            bool ans =false;
            for (int j=0;j<len;j++){
                if( !flag[j]  && A[j] <= m && (m-A[j])%k == 0  ){
                    flag [j] = 1;
                    ans = true;
                    break;
                }
            }
            if(!ans) 
                return fail;
        }
        return sucess;
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






