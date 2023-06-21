#include<iostream>
using namespace std;
#define MAX 10
class student
{
	private:
		char name[30];
		long long rollno;
		char branch[30];
		char pname[100];
		long long phno;
		public:
			void getDetails(void);
			void putDetails(void);
		};
		void student::getDetails(void) { 
			cout<<"enter roll number:";
			cin>>rollno;
			cout<<"enter name:";
			cin>>name;
			cout<<"enter branch:";
			cin>>branch;
			cout<<"enter program name:";
			cin>>pname;
			cout<<"enter phone number:";
			cin>>phno;
		}
		void student::putDetails(void) {
			cout<<rollno<<"\t"<<name<<"\t\t"<<branch<<"\t\t"<<pname<<"\t\t"<<phno;
		}
		int main()
        {
        	student std[MAX];
        	int n,loop;
        	cout<<"enter total number of students:";
        	cin>>n;
        	for(loop=0;loop<n;loop++) {
        		cout<<"enter details of student"<<loop+1<<"\n";
        		std[loop].getDetails();
        	}
        	cout<<endl;
        	cout<<"details of student:\n";
        	cout<<"rollnumber\tname\t\tbranch\tprogram name\t\tphone number\n";
        	for(loop=0;loop<n;loop++) {
        		std[loop].putDetails();
        	}
        	return 0;
        }
