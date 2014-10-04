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
        string fail = "IMPOSSIBLE";
        string sucess = "POSSIBLE";
        len = A.size();
        sort(A.begin(),A.end(),[](int a ,int b ) {
                return a > b ;
            });
        vector<int>::iterator it;
        for(int i=1;i<=len;i++){
            for(it = A.begin(); it!=A.end()  ; it++ ) {
                if( i >= *it && (i-*it)%k == 0 )
                    break;
            }
            if( it != A.end() && *it<=i ){
                A.erase(it);
                continue;
            }
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






