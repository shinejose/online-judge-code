#include <iostream>
#include <vector>
using namespace std;



class AddMultiply{
public:
vector<int> makeExpression(int y){
vector<int> result;
int x0,x1,x2;
for (x0 =-1000;x0<= 1000;x0++ ){
if(x0 == 0 || x0 ==1 )
    continue;
for(x1 = -1000 ; x1 <=1000; x1++){
if(x1 ==0 || x1 ==1  )
    continue;
x2 = y - x0* x1 ;
if( x2 >=-1000 && x2 <=1000 && x2 != 0 && x2 !=1 ){
result.push_back(x0);
result.push_back(x1);
result.push_back(x2);
return result;
}
}
}

}
};

int main(int argc,char** argv)
{
return 0;
}
    
