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
 int main(int argc,char** argv)
{
	string  str;
	cin >> str;
	int count =0;
	int n =str.size();
	int ans =0 ;
	int first =n ;
	for(int i=0 ;i<n;i++) 
		if( str [i] =='M') 
		{
			first =i;
			break;
		}
	for(int i=first;i< n;i++) 
		if( str[i] == 'F' ) 
		{
			if( i-first -count > ans) 
				ans = i-first -count ;
			else 
				ans = ans +1;
			count++ ;
		}
	cout<< ans<<endl;
	return 0;
}

