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
vector<int> a;
int n,k;
int main(int argc,char** argv)
{
	cin >> n >> k;
	a.assign(n,0) ;
	for( int i =0;i<n;i++) 
		scanf("%d",&a[i]);
	sort(a.begin() ,a.end()) ;
	a.resize(unique(a.begin(),a.end())-a.begin());
	n = a.size();
	if( k>= a[0] ) 
		cout<<a[0] <<endl;
	else 
	{
		vector<int>::iterator last;
		for(int i=a[0]  ; i>k ;i--) 
		{
			bool isOk =true;
			last = a.begin();
			for(int j = 0; j <= a[n-1] ; j+=i) 
			{
				auto lower= lower_bound(a.begin() ,a.end() ,j);
				auto upper=upper_bound( a.begin() ,a.end(),j+k) ;
				if( lower != last  ) 
				{
					isOk = false;
					break;
				}
				else
					last = upper ;
				if(last==a.end())
					break;
			}
			if(isOk  && last ==a.end() ) 
			{
					cout<< i<<endl;
					break;
			}
		}
	}
	return 0;
}

