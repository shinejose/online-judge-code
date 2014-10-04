#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<memory.h>
using namespace std;
class 
TheArithmeticProgression
{
	public: 
double minimumChange(int a, int b, int c)
{
	double ans = ((2.0*b-a-c)/2.0);
	if( ans>0) 
		return ans;
	else 
		return -ans;
}
};

int main(int argc,char** argv)
{
	return 0;
}

