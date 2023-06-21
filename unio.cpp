#include<iostream>
#include<vector>
#include<sstream>
#define MAX 10
using namespace std;
class Customer
{
	public:
		char name[20];
		char dob[20];
		
};
int main()
{
	Customer c;
	cout<<"Enter name:";
	cin>>c.name;
	cout<<"Enter Date of birth in dd/mm/yyyy format:";
	cin>>c.dob;
	stringstream ss(c.dob);
	vector<string>tokens;
	string temp_str;
	cout<<"Name is:"<<c.name<<"\n";
	while(getline(ss,temp_str,'/'))
	{
		tokens.push_back(temp_str);
	}
	for(int i=0;i<tokens.size();i++)
	{
		cout<<tokens[i];
		if(i<(tokens.size()-1))
		{
			cout<<"\n";
		}
	}
}
