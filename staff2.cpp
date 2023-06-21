#include <iostream>
#include <string>
using namespace std;

class Staff 
{
  public:
    Staff(int staffId, string name, string phone, float salary) :
      staffId(staffId), name(name), phone(phone), salary(salary) {}
    int staffId;
    string name;
    string phone;
    float salary;
};

class Teaching : public Staff {
  public:
    Teaching(int staffId, string name, string phone, float salary, string domain, int publications) :
      Staff(staffId, name, phone, salary), domain(domain), publications(publications) {}
    string domain;
    int publications;
};

class Technical : public Staff
{
  public:
    Technical(int staffId, string name, string phone, float salary, string skills) :
      Staff(staffId, name, phone, salary), skills(skills) {}
    string skills;
};

class Contract : public Staff {
  public:
    Contract(int staffId, string name, string phone, float salary, int period) :
      Staff(staffId, name, phone, salary), period(period) {}
    int period;
};

int main() {
  Teaching t1(01, "radha", "970965", 50000, "CSE", 5);
  Technical t2(02, "sai", "897650", 60000, "C++");
  Contract t3(03,"abhi", "670997", 70000, 3);

  cout << "Teaching Staff 1:" <<endl;
  cout << "Staff ID: " << t1.staffId <<endl;
  cout << "Name: " << t1.name <<endl;
  cout << "Phone: " << t1.phone << endl;
  cout << "Salary: " << t1.salary << endl;
  cout << "Domain: " << t1.domain << endl;
  cout << "Publications: " << t1.publications << endl;
  cout << std::endl;

  cout << "Technical Staff 2:" << endl;
  cout << "Staff ID: " << t2.staffId << endl;
  cout << "Name: " << t2.name << endl;
  cout << "Phone: " << t2.phone << endl;
  cout << "Salary: " << t2.salary << endl;
  cout << "Skills: " << t2.skills << endl;
  cout << endl;

  cout << "Contract Staff 3:" <<endl;
  cout << "Staff ID: " << t3.staffId <<endl;
  cout << "Name: " << t3.name <<endl;
  cout << "Phone: " << t3.phone << endl;
  cout << "Salary: " << t3.salary << endl;
  cout << "Period: " << t3.period << endl;
}
