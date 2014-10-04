#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
vector<long long > h,p; 
int right(long long mid)
{
	int n = h.size();
	int m = p.size();
	int j =0 ;
	for(int i=0;i<n;i++)
	{
		if(h[i]<=p[j] ) 
		{
			for(int k=j;k<m;k++) 
				if(h[i]+mid>=p[k]) 
					j++;
				else 
					break;
		}
		else 
		{
			if(h[i] -mid > p[j] ) 
				return 0;
			else
			{
				long long rest=  mid - 2*(h[i]-p[j] )  ;
				long long cur2 =  mid - (h[i] -p[j] ) ;
				cur2 = cur2 /2 + h[i];
				j++ ;
				long long cur ;
				if( rest>0 ) 
					cur = h[i] +rest;
				else 
					cur = h[i] ;
				cur = max(cur,cur2) ;
				for(int k=j;k<m;k++ )
				{
					if(cur>=p[k]) 
						j++;
					else 
						break;
				}
			}
		}
		if( j>=m) 
			return 1 ;
	}
	return 0 ;
}
int main(int argc,char** argv)
{
	int n,m;
	while(cin >> n >> m)
	{
		h.clear();
		p.clear( );
		for(int i=0;i<n;i++)
		{
			long long temp ;
			cin >> temp;
			h . push_back( temp ) ;
		}
		for(int i=0;i<m;i++)
		{
			long long temp;
			cin >> temp;
			p. push_back(temp) ;
		}

		long long l,r;
		l=0 ;
		r= max(h[n-1],p[m-1] ) - min(h[0], p[0]) +1;
		r *=2 ;
		long long ans = -1 ;
		while(l<=r)
		{
			long long mid = (l+r) /2;
			if(right(mid) ) 
			{
				r = mid  -1 ;
				ans = mid;
			}
			else 
				l = mid +1  ;
		}
		cout << ans<<endl;
	}
	return 0;
}

