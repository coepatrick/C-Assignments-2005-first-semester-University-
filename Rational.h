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