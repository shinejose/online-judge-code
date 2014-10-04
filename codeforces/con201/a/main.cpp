#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<memory.h>
#include<algorithm>
#include<functional>
using namespace std;
#define mmset(x,y) memset(x,y,sizeof(x));
int main(int argc,char** argv)
{
	int x[101];
	int n ;
	while(cin>>n) 
	{

		for(int i=0;i<n;i++) 
			cin >>x[i];
	
		sort(x,x+n);

		cout << x[n-1] <<" ";
		for(int i=1;i<n-1;i++) 
			cout <<x[i]<< " ";
		cout<< x[0 ] <<endl;
		
	}
	return 0;
}

