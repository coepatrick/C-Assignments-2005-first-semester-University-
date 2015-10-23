//CSC191
//Assignment#7
//Patrick Coe
//10/27/2005
//This program uses recursive functions to add, subtract, divide or multiply polynomials

#include <iostream>
#include <string>
using namespace std;


class Poly
{
private:
	int coef[11]; //holds eleven values, the last value is always -999 for checking purposes.
public:
	Poly() //sets all values in coef to -999
	{
		for(int cnt=0; cnt <  11; cnt++)
			coef[cnt]=-999;
	}
	Poly::min(Poly s);
	int evaluate(const Poly& s1,int x); //used to evaluate for x
	friend istream& operator >> (istream& cin, Poly& s);
	friend ostream& operator << (ostream& cout, const Poly s);
	friend Poly operator + (const Poly& s1, const Poly& s2);
	friend Poly operator - (const Poly& s1, const Poly& s2);
};


istream& operator >> (istream& cin, Poly& s)
{

	for(int cnt=0; cnt <  10; cnt++)
	{
		cout << "Enter the Coefficient for X^" << cnt << " (-999 to quit): ";
		cin >> s.coef[cnt];
		if(s.coef[cnt] == -999)
			return cin;
	}

	return cin;
}

ostream& operator << (ostream& cout, const Poly s)
{
	
	cout << s.coef[0];

	for(int cnt = 1; cnt <  10; cnt++)
			if(s.coef[cnt] != -999)
				if (s.coef[cnt] >= 0)
					cout << '+' << s.coef[cnt] << "x^" << cnt;
				else
					cout << s.coef[cnt] << "x^" << cnt;

	return cout;

}

Poly operator + (const Poly& s1, const Poly& s2)
{

	Poly s3 = s1;

	for(int cnt = 0; cnt <  10; cnt++)
		if((s1.coef[cnt] != -999) && (s2.coef[cnt] != -999))
			s3.coef[cnt] += s2.coef[cnt];
		else if((s1.coef[cnt] == -999) && (s2.coef[cnt] != -999))
			s3.coef[cnt] = s2.coef[cnt];

	return s3;

}

Poly operator - (const Poly& s1, const Poly& s2)
{

	Poly s3 = s1;

	for(int cnt = 0; cnt <  10; cnt++)
		if((s1.coef[cnt] != -999) && (s2.coef[cnt] != -999))
			s3.coef[cnt] -= s2.coef[cnt];
		else if((s1.coef[cnt] == -999) && (s2.coef[cnt] != -999))
			s3.coef[cnt] = 0 - s2.coef[cnt];

	return s3;


}

int Poly::evaluate(const Poly& s1, int x)
{
	Poly s3 = s1;

	if(s1.coef[1] == -999)
		return s1.coef[0];

	for(int cnt = 0; cnt < 11; cnt++)
		s3.coef[cnt] = s1.coef[cnt+1];

	return(s1.coef[0]+(x * evaluate(s3, x)));
}

void main()
{
	Poly P1, P2, s3;;
	int x;
	char res;

	do
	{

		cout << endl;
		cout << "1. Read polynomial." << endl;
		cout << "2. Print polynomial" << endl;
		cout << "3. Add polynomial" << endl;
		cout << "4. Subtract polynomial" << endl; 
		cout << "5. Multiply polynomial (not implemented)" <<endl;
		cout << "6. Evaluate polynomial" <<endl;
		cout << "7. Exit" << endl;


		cout << "select:";

		cin >> res;

		cout << endl;

		switch (res)
		{
		case '1':
			cin >> P1;
			break;
		case '2':
			cout << P1;
			break;
		case '3':
			cin >> P2;
			P1 = P1 + P2;
			break;
		case '4':
			cin >> P2;
			P1 = P1 - P2;
			break;
		case '5':
		//	cin >> P2;
		//	P1 = P1 * P2;
			cout << "This feature is not available yet" << endl;
			break;
		case '6':
			cout << "Enter a value for x: ";
			cin  >> x;
			cout << P1.evaluate(P1, x);
			break;
		case '7':
			break;
		default:
			cout << "Invalid!, try again" << endl;
		}
	} while (res != '7');
}

