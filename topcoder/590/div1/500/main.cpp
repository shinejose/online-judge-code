#include <iostream> 
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

class XorCards
{
	public :
		static const int maxBit=60;
		int Rank(int a[][maxBit],int b[],int n ,int p) 
		{
			int flag[maxBit];
			memset(flag,0,sizeof(flag));
			int count=0 ;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<maxBit;j++)
				{
					if(a[j][i]!=0  && !flag[j] ) 
					{
						flag[j] = ++count;

						for(int k=0; k<maxBit;k++)
							if(!flag[k] && a[k][i] ) 
							{
								for(int l =i;l<n;l++)
								{
									a[k][l] = ( a[k][l] + a[j][l] ) % p ;
								}
								b[k] = ( b[k] + b[j] ) % p;
							}
						break;
					}
				}

			}

			for(int i=0;i<maxBit;i++) 
				if(!flag[i] && b[i] !=0 )
					return -1;
			return count;


		}
		long long countEqual(vector<long long>number,long long limit)
		{
			int a[maxBit][maxBit];
			int b[maxBit];
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));

			int m = number.size();
			for(int i=0;i<maxBit;i++)
			{
				for(int j=0;j<m;j++)
					a[i][j] = (number[j] & ( (long long)1<< i)  )? 1:0 ;
				b[i] = ( limit&((long long )1<<i) )?1:0 ;
			}
			int r= Rank(a,b,number.size(),2);
			if(r == -1) 
				return 0;
			return  (long long)1<< (number.size() - r) ;

		}
		long long numberOfWays(vector<long long > number,long long limit) 
		{
			long long ans =0 ;
			ans += countEqual(number,limit);
			for(int i=0;i<maxBit;i++)
			{
				if(!( limit & ((long long) 1 << i) ) ) 
					continue;
				long long cut = (limit >> (i+1)) ;
				cut = (cut<<1) ;
				vector<long long > tnumber; 
				for(int j=0;j<number.size();j++)
				{
					tnumber.push_back(number[j]>>i);
				}
				ans += countEqual(tnumber,cut);

			}
			return ans;

		}
};

int main(int argc,char ** argv) 
{
	XorCards test;
	vector<long long>in;
	long long limit;
	FILE * fp = fopen( argv[1] ,"r") ;
	int n ;
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++)
	{
		long long temp;
		fscanf(fp,"%lld",&temp);
		in.push_back(temp);
	}
	fscanf(fp,"%lld",&limit);
	cout<<test.numberOfWays(in,limit)<<endl;
	fclose(fp);

	return 0;
}


