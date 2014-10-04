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
int a[205 ] ;
int p[205];
map<int,int> mycnt;
map <int,int> res;
vector<int> temp;
int main(int argc,char** argv)
{
	int n;
	cin >> n;
	for (int i =0;i<2*n;i++) 
	{
		int tempin;
		cin>> tempin;
		a[i] = tempin;
		mycnt[tempin] = mycnt[tempin] +1 ;
		temp.push_back(tempin);
	}
	sort(temp.begin(),temp.end());
	temp.resize(unique(temp.begin(),temp.end()) -temp.begin() );
	sort(temp.begin(),temp.end () ,[=](int a,int b){ return mycnt[a] > mycnt[b] ; } ) ;
	int m = temp.size();
	int index =0 ;
	int ans = -1 ;
	for(int i=0;i<m && i<n ;i++) 
	{
		int h2= 0;
		int h1 =i+1 ;
		for(int j=0;j<m;j++) 
		{
			if(j<=i && mycnt[temp[j]] >=2 ) 
			{
				h2++ ;
				h1+= mycnt[temp[j]] -2 ;
			}
			else if( j>i)  
			{
				h2 ++;
				if(mycnt[temp[j]] >1 ) 
					h1+= mycnt[temp[j]] -1 ;
			}
		}
		if (ans <= (i+1) *h2  && h1 >= n) 
		{
			ans = (i+1) *h2 ;
			index = i;
		}
	}
	for(int i=0 ;i<=index;i++) 
		res[temp[i]] = 1;
	cout<<ans<<endl;
   
	fill(p,0) ;
	for(int i=0;i<2*n;i++) 
		if(res[a[i]] ==1 ) 
		{
			p[i] =1 ;
			res[a[i]]++ ;
		}

	int count = index+1;
	if(count  < n) 
	{
		for(int i=0;i<2*n;i++) 
			if( mycnt[a[i]]>2   &&res[a[i]] ==2  && p[i] ==0) 
			{
				mycnt[a[i]] -- ;
				p[i] =1 ;
				count ++ ;
				if(count == n) 
					break;
			}
	}
	for(int i=0;i<2*n;i++) 
		if(p[i] ==0 ) 
			p[i] =2 ;
	for(int i=0;i<2*n;i++) 
		cout<< p[i]<<" " ;
	cout<< endl;
	return 0;
}

