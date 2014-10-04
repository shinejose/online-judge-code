#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		int flag =0;
		for(int i =0;i<=a;i++)
		{
			int cutb = b-i;
			if(cutb >=0 && cutb + a-i == c) 
			{
				cout<<i<<" "<<cutb<<" "<<a-i<<endl;
				flag =1;
				break;
			}
		}
		if(!flag) 
			cout<<"Impossible"<<endl;

	}
	return 0;
}
