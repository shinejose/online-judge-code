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
const int MAXN = 2005;
int p[MAXN] ;
int main(int argc,char** argv)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>> p[i];
		if(p[i] < 0 )
			p[i] = - p[i] ;
	}
	int ans =0 ;
	for(int i=0;i<n;i++) 
	{
		int a,b; 
		a =b = 0;
	   for(int j=0;j<n;j++) 
		   if(p[i] > p[j]) 
		   {
			   if(i < j) 
				   b++;  //  p[i] sign is + : b is all the inversions starting with p[i]
			   else if (j <i ) 
				   a++; // p[i] sign is - : a is all the inversions ending with -p[i]
		   }
	   ans += min(a,b) ; 
	}
	cout<< ans<<endl;
	return 0;
}

