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
const int MAXN = 100005;
int a[MAXN] ;
map<int,vector<int>> x;
class
Node
{
	private:
	public:
		int x,px;
};

vector<Node> ans;
int main(int argc,char** argv)
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) 
	{
		vector<int>temp;
		scanf("%d" ,&a[i]);
		x[a[i]].push_back(i) ;
	}
	int m =x.size();
	for( auto &i :x) 
	{
		int mm = i.second.size();
		int d =0 ;
		bool state =true;
		for(int j=0;j<mm ;j++) 
		{
			if(j==0 )
				continue;
			if( d == 0) 
				d = i.second[j] - i.second[j-1] ;
			else if( i.second[j] - i.second[j-1] !=d ) 
			{
				state = false;
				break;
			}
		}
		if(state) 
		{
			Node temp;
			temp.x = i.first;
			temp.px =d;
			ans.push_back(temp);
		}
	}
	cout<<ans.size()<<endl;
	for( auto &i: ans) 
		cout<<i.x<<" "<< i.px<<endl;

	return 0;
}

