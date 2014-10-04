#include <iostream>
using namespace std;
long long ans ;
void f(long long a ,long long b )
{
	if( a==0 ||b== 0) 
		return ;
	if( a>b) 
	{
		ans += a/b;
		f(a%b,b) ;
	}
	else if (a< b ) 
	{
		ans += b/a;
		f(a,b%a) ;
	}
	else 
	{
		ans ++;
		return ;
	}
}
int main()
{
	long long a,b;
	while(cin >> a>>b) 
	{
		ans = 0;
		f(a,b);
		cout<< ans<<endl;	
	}
	return 0;
}
