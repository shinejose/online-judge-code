#include <iostream> 
#include <string>
#include <vector>
using namespace std;

class FoxAndGomoku
{
	public :
		string win(vector <string> board ) 
		{
			string found = "found";
			string noFound = "not found";
		    int n = board.size();
			for(int i =0;i<n;i++)
				for(int j=0; j<n;j++)
				{
					//case 1 
					int count =0 ;
					for(int k=0;k<5;k++)
					{
						if( i+k < n && board[i+k][j] == 'o') 
							count ++ ;
					}
					if(count ==5 ) 
						return found;

					//case 2
					
					count =0 ;
					for(int k=0;k<5;k++)
					{
						if( j+k < n && board[i][j+k] == 'o') 
							count ++ ;
					}
					if(count ==5 ) 
						return found;

					//case 3

					count =0 ;
					for(int k=0;k<5;k++)
					{
						if( i+k < n && j+k <n  && board[i+k][j+k] == 'o') 
							count ++ ;
					}
					if(count ==5 ) 
						return found;

					//case 4

					count =0 ;
					for(int k=0;k<5;k++)
					{
						if( i+k < n && j-k >=0 && board[i+k][j-k] == 'o') 
							count ++ ;
					}
					if(count ==5 ) 
						return found;
				}	

			return noFound;

		}
};
int main()
{
	return 0;
}
