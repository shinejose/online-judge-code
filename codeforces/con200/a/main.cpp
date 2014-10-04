#include <iostream>
#include <string>
#include <vector> 
using namespace std ;
int main()
{
	int n;
	vector<string> m;

    while(cin>>n)
	{
		int count =0 ;
		for(int i=0;i<n;i++)
		{
			string temp;
			cin>> temp;
			m . push_back(temp);
		}
		for(int i=0;i<n;i++)
		{
			if(i==0) 
				count++;
			else 
			{
				 if(m[i] == m[i-1] )
					 continue;
				 else 
					 count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;

}

