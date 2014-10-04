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
const int MAXN = 500005*2 ;
int dp[MAXN] ; 
int md[MAXN] ;
class
MayTheBestPetWin
{
	private:
	public:
		int maxdiff(int sa,int sb ,int ta,int tb) 
		{
			if( sa > sb )
				swap(sa,sb) ;
			if(ta > tb) 
				swap(ta,tb);
			return  max(abs(sa-tb) ,abs(sb-ta))   ;
		}
		int calc(vector <int> A, vector <int> B)
		{
			int _max =0 ;
			fill(dp,0) ;
			fill(md,0);
			dp[0] =1;
			int n =A.size();
			int suma =0 ;
			int sumb =0 ;
			for(int i=0;i<n;i++) 
			{
				suma += A[i];
				sumb += B[i];
			}
			for(int i=0;i<n;i++) 
			{
				for(int j=_max;j>=0;j--) 
				{
					if(dp[j]) 
					{
						dp[j+A[i] + B[i] ] =1 ;
						_max = max(_max,j+A[i]+B[i]);
					}
				}
			}
			int ans =  MAXN*10;
			for(int i=1;i<MAXN;i++) 
				if(dp[i]) 
				{
					ans =min(ans,max(abs(i-suma),abs(i-sumb))) ;
				}
			return ans;
		}
};

vector<int> A ;
vector<int> B;
int main(int argc,char** argv)
{
	int n ; 
	cin >> n;
	A.assign(n,0) ;
	B.assign(n,0);
	for(int i=0;i<n;i++) 
		scanf("%d,",&A[i]);
	for(int i=0;i<n;i++) 
		scanf("%d,",&B[i]);

	MayTheBestPetWin test;
	cout << test.calc(A,B) <<endl;
	return 0;
}

