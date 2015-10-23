//inheritance
#include <iostream>
#include <string>
using namespace std;

class Emp
{
protected:
	string name;
public:
	Emp(const string &nam): name(nam){};
	virtual void empinfo()
	{
		cout << "Name: " << name << endl;
	}
};

class SEmp: public Emp
{
private:
	double salary;
public:
	SEmp(const string &nam, double sal): Emp(nam)
	{
		salary = sal;
	}
	void empinfo()
	{
		Emp::empinfo();
		cout << "salary = " << salary << endl;
	}
};

class HEmp: public Emp
{
private:
	double hrate, hworked;
public:
	HEmp(const string &nam, double hr, double hw): Emp(nam), hrate(hr), hworked(hw){};
	void empinfo()
	{
		Emp::empinfo();
		cout << "rate = " << hrate << ", hours worked = " << hworked << endl;
	}
};

void main()
{
	Emp E("Judy");
	SEmp SE("Tom", 70000);
	HEmp HE("Mary", 20.50, 40);
	
	E.empinfo();
	SE.empinfo();
	HE.empinfo();

	SE.Emp::empinfo();
	HE.Emp::empinfo(); 
	//E.SEmp::empinfo(); //error

	Emp *s = &SE;
	s->empinfo();
	s = &E;
	s->empinfo();
	s = &HE;
	s->empinfo();
}




/* output
1. no 'virtual' used in Emp - no difference whether used in other class or not
Name: Judy
Name: Tom
salary = 70000
Name: Mary
rate = 20.5, hours worked = 40
Name: Tom
Name: Mary
Name: Tom
Name: Judy
Name: Mary

2. 'virtual' used in Emp
Name: Judy
Name: Tom
salary = 70000
Name: Mary
rate = 20.5, hours worked = 40
Name: Tom
Name: Mary
Name: Tom
salary = 70000
Name: Judy
Name: Mary
rate = 20.5, hours worked = 40
*/