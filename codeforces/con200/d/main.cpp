#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main()
{
	string state;
	while(cin>>state) 
	{
		stack<char> s ; 
		while(!s.empty())
		s.pop();
		int n = state.size();
		for(int i=0;i<n;i++)
		{
			if(!s.empty() && state[i] == s.top())
			{
				s.pop();
				continue;
			}
			else 
				s.push(state[i]) ;
		}

		if(s.empty() )
			cout<<"Yes"<<endl;
		else 
			cout <<"No"<<endl;
	}
	return 0;
}
