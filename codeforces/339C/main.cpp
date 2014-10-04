#include <string>
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
#define mset(x,val) memset(x,val,sizeof(x));

int main() 
{
	string in;
	while(cin>>in) 
	{
		int m;
		vector<int> ans;
		cin>> m ; 
		int left,right;
		int sum[2] ;
		mset(sum,0);
		int turn =0 ;
		int flag =0 ;
		int mark =-1 ;
		int flagans =0 ;
		for(int j=0;j<m;j++)
		{
			if(j==0 ) 
			{
				int pre = -1;
				int minit= 20;
				for(int i=0;i<in.size();i++)
				{
						if(in[i] == '0') 
							continue;
					if(pre ==-1) 
						pre = i;
					else 
					{

						if(i - pre <= minit) 
						{
							minit = i - pre;
							sum[turn] = pre+ 1;
							sum[turn^1] = i +1 ;
						}
						pre = i;
					}
				}
				if(pre==-1) 
				{
					flagans =1 ;
					break;
				}

				if( minit == 20) 
				{
					mark = pre + 1 ;
					sum[turn] =  pre +1;
					turn ^=1 ;
					ans.push_back(pre+1) ;
				}
				else
				{
					mark =  sum[turn^1] -1 ;
					ans.push_back(sum[turn]);
					ans.push_back(sum[turn^1]) ;
					j++;
				}
			}
			else 
			{
				flag =0 ;
				for(int i=0;i<in.size();i++)
				{
					if(i == mark ) 
						continue ;
					if(in[i] == '1'  && sum[turn] +i +1 > sum[turn^1])
					{
						ans.push_back(i+1) ;
						sum[turn] +=i+1 ;
						turn ^=1;
						flag =1;
						mark = i;
						break;
					}
				}
				if(!flag) 
				{
					flagans =1;
					break;
				}
			}
		}

		if( flagans)
			cout <<"NO"<<endl;
		else 
		{
			cout<<"YES"<<endl;
			for(int i=0;i<ans.size()-1;i++)
				cout << ans[i] <<" " ;
			cout<<ans[ans.size()-1]<<endl;
		}

	}
	return 0 ;
}


