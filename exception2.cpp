#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cout<<"enter two numbers:";
	cin>>a>>b;
	try
	{
		if(b==0)
		throw b;
		else
		{
			c=a/b;
			cout<<"result"<<c;
		}
	}
	catch(int x)
	{
		cout<<"cannot divide by zero"<<x;
	}
	return 0;
}
