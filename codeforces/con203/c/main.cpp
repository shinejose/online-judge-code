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
plant
{
	private:
	public:
		int x,y;
		int dist;
		int flag;
};
const int MAXN = 100005;

plant p[MAXN];
vector<string> sans;

bool cmp(plant a,plant b ) 
{
	if(abs(a.x) <abs (b.x)) 
		return true ;
	else if( abs(a. x) ==abs(b.x)) 
		return abs(a.y ) <abs(b.y);
	else 
		return false;
}

int main(int argc,char** argv)
{
	int n;
	cin >>n ;
	int count =0;
	for(int i=0;i<n;i++) 
	{
		scanf("%d%d",&p[i].x,&p[i].y) ;
		if(p[i].x ==0 || p[i].y == 0) 
			count ++;
		p[i].dist = p[i].x+p[i].y;
		p[i] .flag =1 ;
	}
	int ans = 4*count + 6*(n-count) ;

	sort( p ,p+n,cmp);
	cout<< ans<<endl;
	for(int i=0;i<n;i++) 
	{
		string dir ;
		string rdir;
		if(p[i].x ==0 ) 
		{
			if(p[i].y> 0) 
			{
				dir ='U' ; 
				rdir= 'D';
			}
			else 
			{
				dir= 'D';
				rdir='U';
			}
			cout<<'1' <<" " << abs (p[i].y ) <<" "<<dir<<endl;
			cout<<'2'<<endl;
			cout<<'1' <<" "<<  abs (p[i].y ) <<" "<<rdir<<endl;
			cout<<'3'<<endl;
			p[i].flag =0 ;
		}
		else if( p[i].y==0) 
		{
			if(p[i].x>0) 
			{
				dir= 'R';
				rdir='L';
			}
			else
			{
				dir='L';
				rdir= 'R';
			}
			cout<<'1' <<" "<< abs(p[i].x )<<" "<<dir<<endl;
			cout<<'2'<<endl;
			cout<<'1' <<" "<<abs( p[i].x )<<" "<<rdir<<endl;
			cout<<'3'<<endl;
			p[i].flag =0 ;
		}
	}
	int size= n;
	for(int i=0;i<n && i<size;i++) 
		if(p[i].flag ==0 ) 
		{
			swap(p[i],p[size-1]) ;
			size-- ;
			i--;
		}
	if(size ==0 )
		return 0 ;
	sort( p ,p+size,cmp );
	for(int i=0;i<size;i++) 
	{
		if(p[i].x>0 && p[i].y>0 ) 
		{
			cout<<'1' <<" "<< p[i].x <<" " <<'R'<<endl;
			cout<<'1' <<" "<< p[i].y <<" "<<'U'<<endl;
			cout<<'2'<<endl;
			cout<<'1' <<" "<< p[i].x <<" "<<'L'<<endl;
			cout<<'1' <<" "<< p[i].y <<" "<<'D'<<endl;
			cout<<'3'<<endl;
		}
		else if( p[i].x>0 && p[i] .y<0) 
		{
			cout<<'1' <<" "<< p[i].x <<" "<<'R'<<endl;
			cout<<'1' <<" "<<-p[i].y <<" "<<'D'<<endl;
			cout<<'2'<<endl;
			cout<<'1' <<" "<< p[i].x <<" "<<'L'<<endl;
			cout<<'1' <<" "<< -p[i].y <<" "<<'U'<<endl;
			cout<<'3'<<endl;
		}
		else if( p[i].x<0 && p[i] .y> 0) 
		{
			cout<<'1' <<" "<< -p[i].x <<" "<<'L'<<endl;
			cout<<'1' <<" "<< p[i].y <<" "<<'U'<<endl;
			cout<<'2'<<endl;
			cout<<'1' <<" "<< -p[i].x <<" "<<'R'<<endl;
			cout<<'1' <<" "<< p[i].y <<" "<<'D'<<endl;
			cout<<'3'<<endl;
		}
		else 
		{
			cout<<'1' <<" "<< -p[i].x <<" "<<'L'<<endl;
			cout<<'1' <<" "<<-p[i].y <<" "<<'D'<<endl;
			cout<<'2'<<endl;
			cout<<'1' <<" "<< -p[i].x <<" "<<'R'<<endl;
			cout<<'1' <<" "<< -p[i].y <<" "<<'U'<<endl;
			cout<<'3'<<endl;
		}
	}
	return 0;
}

