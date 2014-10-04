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
const int maxn = 100005; 
int a[maxn];
 int main(int argc,char** argv)
{
	int n ;
	while(cin >> n) 
	{
		for(int i=0;i<n;i++) 
			cin>>a[i]; 
		int count =0 ;
		int swap =0 ;
		for(int i=0;i<n;i++) 
		{
			if(a[i] == i) 
			{
				count ++;
				continue;
			}
			if(!swap && a[a[i]] ==i) 
			{
				swap ++ ;
				count +=2;
			}
		}
		if(count!= n && !swap) 
			count ++;
		cout<<count;
	}

	return 0;
}

