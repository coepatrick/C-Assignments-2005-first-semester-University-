//CSC191
//Lab11
//Patrick Coe
//11/04/2005
//


#include <iostream>
#include <string>
using namespace std;
#include "rational.h"
#include "complexn.h"

class Mystring
{
private: 
	string s;
	bool dup();
public:
	friend istream& operator >> (istream& cin, Mystring& S);
	friend ostream& operator << (ostream& cout, const Mystring& S);
	friend Rational operator + (const Mystring& S1, const Mystring& S2);
	friend Rational operator - (const Mystring& S1, const Mystring& S2);
};

istream& operator >> (istream& cin, Mystring& S)
{
	cin >> S.s;
	return cin;
}

ostream& operator << (ostream& cout, const Mystring& S);
{
	cout << S.s
	return cout;
}



template <class T>
class Num
{
private:
	T n;
public:
	Num(){};
	Num(T nn) {n=nn;}
	friend istream& operator >> <T>(istream& cin, Num<T>& n);
	friend ostream& operator << <T>(ostream& cout, const Num<T>& N);
	friend Num operator + <T>(const Num<T>& N1, const Num<T>& N2);
	friend Num operator - <T>(const Num<T>& N1, const Num<T>& N2);

};

template <class T>
istream& operator >> (istream& cin, Num<T>& N)
{
	cout << "Enter a number:" ;
	cin >> N.n;

	return cin;
}

template <class T>
ostream& operator << (ostream& cout, const Num<T>& N)
{
	cout << N.n << endl;
	return cout;
}

template <class T>
Num<T> operator + (const Num<T>& N1, const Num<T>& N2)
{
	Num<T> N;
	N.n = N1.n + N2.n;
	return N;
}

template <class T>
Num<T> operator - (const Num<T>& N1, const Num<T>& N2)
{
	Num<T> N;
	N.n = N1.n - N2.n;
	return N;
}


void main()
{
	Num<int> I1(1), I2(2);
	cout << "n1= " << I1 << "n2= " << I2 << "n1+n2 = " << I1 + I2 << endl;
	cout << "n1= " << I1 << "n2= " << I2 << "n1-n2 = " << I1 - I2 << endl;

	Num<float> F1(1.2), F2(2.3);
	cout << "n1= " << F1 << "n2= " << F2 << "n1+n2 = " << F1 + F2 << endl;
	cout << "n1= " << F1 << "n2= " << F2 << "n1-n2 = " << F1 - F2 << endl;

	Num<Rational> R1(Rational(1,2)), R2(2);
	cout << "n1= " << R1 << "n2= " << R2 << "n1+n2 = " << R1 + R2 << endl;
	cout << "n1= " << R1 << "n2= " << R2 << "n1-n2 = " << R1 - R2 << endl;


	Poly P1, P2;
	cin >> P1 >> P2;
	cout << "n1= " << P1 << "n2= " << P2 << "n1+n2 = " << P1 + P2 << endl;
	cout << "n1= " << P1 << "n2= " << P2 << "n1-n2 = " << P1 - P2 << endl;
	
}
