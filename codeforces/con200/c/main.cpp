#include <iostream>
using namespace std;
int main()
{
	long long a , b ;
	while(cin >>a  >>b )
	{
		long long count =0;
		while(a!=b && b!=1 )
		{
			if( a>b) 
			{
				long long num = a /b ;
				count+=num ;
				if( a % b == 0 ) 
					break;
				a = a-num*b ;
			}
			else
			{
				long long num = (b-a) /a ;
				if( (b-a) %a != 0 ) 
					num ++ ;
				count +=  num ;
				a= a ;
				b = b - num * a ;
			}
		}
		if( b==1 ) 
			count += a ;
		else 
			count ++;
		cout << count<<endl;
	}
	return 0;
}

