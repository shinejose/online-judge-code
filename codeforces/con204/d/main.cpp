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
#define fill(x,y) (memset(x,y,sizeof(x)))
#define sz(x) ((int) (x).size())
const int MAXN= 3005;
int p[MAXN]; 
int main(int argc,char** argv)
{
	int n;
	cin >> n;
	for(int i=0;i< n;i++) 
		cin >> p[i]; 
	int count =0 ;
	for(int i=0;i<n;i++) 
		for(int j=i+1;j<n;j++) 
			if(p[i] > p[j]) 
				count ++;
	cout<<(count/2)*4 + (count % 2 != 0)<<endl;
	return 0;
}

