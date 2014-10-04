#include <iostream>
#include <memory.h> 
#include <vector>
#include <string>
using namespace std;


class FoxAndGo
{
	public: 
		int flag[20][20] ;
		int n ;
		void search(int i,int j,vector<string>board) 
		{
			int dir[4][2] ={ {0,1},{0,-1},{1,0},{-1,0}};
			if(flag[i][j] ) 
				return ;
			flag[i][j] =1 ;
			for(int k=0;k<4;k++)
			{
				int x = i +dir[k][0 ] ;
				int y = j+ dir[k][1] ;
				if( x< 0 || y< 0 || x>=n ||y>=n) 
					continue;
				if(board[x][y] =='.' || board[x][y] =='o') 
				search(x,y,board);
			}

		}

		int sorce(vector<string> board) 
		{
			memset(flag,0,sizeof(flag)) ;

			for(int i=0 ;i<n;i++)
				for(int j=0;j<n;j++)
					if( board[i][j] =='.') 
					{
						search(i,j,board);
					}

			int xcount =0;
			int flagcount =0 ;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					if(board[i][j] =='x') 
						xcount ++ ;
					if(flag[i][j] ==1) 
						flagcount ++ ;
				}
			return n*n - xcount -flagcount;


		}
		int maxKill(vector <string> board) 
		{
			n = board.size();
			int max = -1 ;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					if(board[i][j]=='.') 
					{
						board[i][j] ='x' ;
						int resorce =sorce(board) ;
						if(resorce >max) 
							max=  resorce;
						board[i][j] = '.';
					}
				}

			return max ;
		}
};
int main()
{
	return 0;
}
