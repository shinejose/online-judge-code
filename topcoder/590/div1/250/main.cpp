#include <iostream>
#include <string>
#include <vector>

using namespace std ;

class FoxAndChess
{
	public : 
		string ableToMove(string begin ,string target)
		{
		    string x,y;
			int lx,ly;
			int rx,ry;
			lx=rx=ly=ry =0;
			vector<int> px,py;
			int n = target .size();

			string no = "Impossible";
			string yes= "Possible";
			for(int i =0;i<n;i++)
			{
			   if(begin[i] !='.') 
			   {
				   x.push_back(begin[i]);
				   px.push_back(i);
			   }
			   if(target[i] != '.') 
			   {
				   y.push_back(target[i]);
				   py.push_back(i) ;
			   }
			   if(begin[i] == 'L') 
				   lx ++;
			   if(begin[i] == 'R') 
				   rx ++ ;
			   if(target[i] =='L') 
				   ly ++ ;
			   if(target[i] =='R') 
				   ry ++ ;
			}

			if( !(lx==ly && rx ==ry) ) 
					return no ;
			int t = y.size();
			for(int i =0;i<t;i++)
			{
				if(y[i] != x[i]) 
					return no;
				if(y[i] == 'L' && py[i] > px[i]) 
					return no;
				if(y[i] == 'R' && py[i] <px[i]) 
					return no;
			}
			return yes;
		}

};
