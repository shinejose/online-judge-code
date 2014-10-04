/* 数论 (一次不定方程之解）
 * d = gcd(xi) , xi / d ,至少存在a,b (a,b) ==1 
 * 任意两个数gcd(a,b) == 1 | n ( 1<=n<max(xi) ) 
 * ax+by = n 当(a,b) | n 解存在
 * 所以最后必定构造出{d,2d,3d...max(xi)}的集合
 */
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

int gcd(int  a,int b) 
{
	return b==0?a:gcd(b,a%b) ;
} 

 int main(int argc,char** argv)
{

	int n ;
	int a[101];
	while(cin >> n) 
	{
		int d ; 
		cin >>  a[0];
		d = a[0];
		int max = d ;
		for(int i=1;i<n;i++)
		{
			cin>> a[i]; 
			d=gcd(d,a[i]) ;
			if( a[i] >max)
				max = a[i] ;
		}

		if((max/d -n ) %2 == 1 )
			cout<<"Alice"<<endl;
		else 
			cout <<"Bob"<<endl;
	}
	return 0;
}

