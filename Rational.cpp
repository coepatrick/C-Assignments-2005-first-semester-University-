//CSC191
//lab assignment #8
//10/14/2005
//Patrick Coe

#include <iostream>
using namespace std;

class Rational
{
private:
	int num, den;
public:
	Rational(int = 0, int = 1);
	Rational(float);
	friend istream& operator >> (istream& cin, Rational& r);
	friend ostream& operator << (ostream& cout, const Rational r);
	friend Rational operator * (const Rational& r1, const Rational& r2);
	friend Rational operator / (const Rational& r1, const Rational& r2);
	friend Rational operator + (const Rational& r1, const Rational& r2);
	friend Rational operator - (const Rational& r1, const Rational& r2);

};

Rational::Rational(int n,int d)
{
	num = n;
	den = d;
}

Rational::Rational(float f)
{
}

istream& operator >> (istream& cin, Rational& r)
{
	cout << "Enter numerator:";
	cin >> r.num;
	cout << "Enter denominator:";
	cin >> r.den;
	return cin;

}

ostream& operator << (ostream& cout, const Rational r)
{
	cout << r.num << '/' << r.den;
	return cout;
}

Rational operator * (const Rational& r1, const Rational& r2)
{
	Rational r;
	r.num = r1.num*r2.num;
	r.den = r1.den*r2.den;
	return r;
}

Rational operator / (const Rational& r1, const Rational& r2)
{
	Rational r;
	r.num = r1.num*r2.den;
	r.den = r1.den*r2.num;
	return r;
}

Rational operator + (const Rational& r1, const Rational& r2)
{
	Rational r;
	r.num = (r1.num*r2.den) + (r2.num*r1.den);
	r.den = (r1.den * r2.den);
	return r;
}

Rational operator - (const Rational& r1, const Rational& r2)
{
	Rational r;
	r.num = (r1.num*r2.den) - (r2.num*r1.den);
	r.den = (r1.den * r2.den);
	return r;
}


void main()
{
	Rational R1(1,2), R2(2,3), R3;
	char option;
	do
	{
		cout << "1. Input rational numbers." << endl;
		cout << "2. Print the numbers." << endl;
		cout << "3. r1 + r2" << endl;
		cout << "4. r1 - r2" << endl;
		cout << "5. r1 * r2" << endl;
		cout << "6. r1 / r2" << endl;
		cout << "7. Exit." << endl;

		cout << "Select:";
		cin >> option;

		switch (option)
		{
			case '1':
				cin >> R1 >> R2;
				break;

			case '2':
				cout << R1 << ' ' << R2 << endl;
				break;
			case '3':
				cout << (R1 + R2) << endl;
				break;
			case '4':
				cout << (R1 - R2) << endl;
				break;
			case '5':
				cout << (R1 * R2) << endl;
				break;
			case '6':
				cout << (R1 / R2) << endl;
				break;
			case '7':
				break;
		}
	} while (option != '7');
}

