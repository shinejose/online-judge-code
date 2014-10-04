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
const int MAXN = 1005 ;
int a[MAXN];
int main(int argc,char** argv)
{
	int n;
	cin  >> n;
	int count5 =0 ;
	int count0 =0 ;
	for( int i=0;i <n;i++) 
	{
		scanf("%d",&a[i]);
		if(a[i] == 0) 
			count0 ++;
		else 
			count5 ++;
	}
	int ans =0; 
	for(int i=count5;i>=0;i--) 
		if( (i*5) %9 ==0 ) 
		{
			ans =i;
			break;
		}
	if(ans == 0 ) 
	{
		if( count0 == 0 ) 
			cout<<"-1"<<endl;
		else 
    	  cout << "0" <<endl;
	}
	else if( count0 ==0) 
	{
		cout<<"-1"<<endl;
	}
	else  
	{
		for(int i=0;i<ans;i++) 
			cout<<'5'; 
		for(int i=0;i<count0;i++) 
				cout<<'0';
		cout<<endl;
	}

	return 0;
}

