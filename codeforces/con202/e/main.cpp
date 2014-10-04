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
class
Node
{
	private:
	public:
		Node(){}
		Node(vector<int> in,int iindex)
		{
			for( auto &i: in) 
				elem.push_back(i);
			index = iindex ;
		}
		~Node() 
		{
			elem.clear() ;
		}
		vector<int> elem;
		int index ;
		int size()
		{
			return this->elem.size();
		}
		bool operator <( Node b) 
		{
			if(elem.size() < b.size()) 
				return true;
		}
};

vector<long long > a;
vector<Node> s;
vector<long long >sum;
vector<long long >add;
vector<vector<int>> intlh;
vector<vector<int>> inthh;
vector<int> smap;

int main(int argc,char** argv)
{
	int m,n,q;
	cin >> n >> m >>q;
	a.assign(n+10,0);
	sum.assign(m+10 ,0);
	add.assign(m+10,0);
	smap.assign(m+10,0) ;
	for(int i=0;i< n ;i++) 
		cin >> a[i] ;
	for(int i=0;i<m;i++) 
	{
		int sm;
		vector<int> tm;
		cin>>sm;
		for(int j=0;j<sm;j++) 
		{
			int temp;
			cin >>temp;
			tm.push_back(temp);
		}
		sort(tm.begin(),tm.end() ) ;
		s.push_back(Node(tm,i));
	}

	sort(s.begin(),s.end(),[]
			(Node  a,Node  b )
			{
			return  a<b;
			} ) ;
	for(int i=0;i<m;i++) 
		smap[s[i].index] = i;
	int sqrtn = (int) sqrt((double) n) ;
	int sizeMaxSqrtn =m;
	for(int i =0;i<m ;i++) 
		if(s[i].size() > sqrtn) 
		{
			sizeMaxSqrtn = i;
			break;
		} 
	for(int i = sizeMaxSqrtn ; i<m;i++) 
	{
		int leni = s[i].size();
		for(int j=0 ;j< leni;j++) 
			sum[i] += a[s[i].elem[j]-1] ;
	}
	for(int i=0;i<sizeMaxSqrtn;i++) 
	{
		int leni= s[i].size();
		vector<int> temp;
		for(int k=sizeMaxSqrtn;k<m;k++) 
		{
			int count =0;
			for(int j =0 ;j<leni;j++ ) 
			{
				if(binary_search(s[k].elem.begin(),s[k].elem.end(),s[i].elem[j])  )
					count++;
			}
			temp.push_back(count) ;
		}
		intlh.push_back(temp);
	}
	for(int i = sizeMaxSqrtn; i<m;i++) 
	{
		vector<int> temp;
		int leni = s[i].size();
		for(int j = sizeMaxSqrtn;j<m;j++ )
			if( i !=j ) 
			{
				int count =0 ;
				for(int k=0;k<leni;k++) 
					if( binary_search(s[j].elem.begin(),s[j].elem.end() , s[i].elem[k]) ) 
						count++;
				temp.push_back(count);
			}
			else 
				temp.push_back(0);
		inthh.push_back(temp);
	}

	for(int o=0;o<q;o++) 
	{
		char op ;
		cin >>op;
		if( op =='?') 
		{
			int opm;
			cin >> opm;
			int index = smap[opm-1]  ;
			long long ans;
			if(index >= sizeMaxSqrtn) 
			{
				ans = sum[index];
				ans += add[index] * s[index].size();
				for(int k=sizeMaxSqrtn;k<m;k++) 
					if( index!=k ) 
						ans += add[k] * inthh[k-sizeMaxSqrtn][index-sizeMaxSqrtn];
			}
			else 
			{
				ans=0;
				for(int i=0;i<s[index].size();i++) 
					ans+= a[s[index].elem[i] -1 ]  ;
				for(int i=sizeMaxSqrtn;i<m;i++) 
					ans += add[i] * intlh[index][i-sizeMaxSqrtn] ;
			}
			cout<< ans<<endl ;
		}
		else if( op =='+') 
		{
			int opm,opa;
			cin>> opm>> opa;
			int index = smap[opm-1];
			if(index >= sizeMaxSqrtn) 
				add [index] += opa;
			else 
			{
				for(int i = s[index].size () -1  ;i>=0;i--) 
					a[s[index].elem[i] - 1] += opa;
				for(int i= sizeMaxSqrtn;i<m;i++) 
					sum[i] += opa*intlh[index][i-sizeMaxSqrtn];
			}
		}
	}
	return 0;
}

