//CSC191
//Lab6
//Patrick Coe
//9/30/05
//This program uses recursive functions to solve exponents and to add or subtract a string of numbers.


#include <iostream>
#include <string>
using namespace std;



class Exp
{
private:
	int n;  // n - 0, 1, 2, ...
	float a;
public:
	int getN() {return n;}
	void read();
	float pow1(int n); //a^n = a^(n-1)'a
	float pow2(int n); //a^n = a^(n/2)*a^(n/2) or a^(n/2)*a^(n/2)*a

};

void Exp::read()
{
	cout << "enter n value:";
	cin >> n;
	cout << "enter a value:";
	cin >> a;
}

float Exp::pow1(int n)
{
	if (n == 0)
		return 1;
	return (pow1(n-1)*a);
}

float Exp::pow2(int n)
{
	if (n == 0)
		return 1;
	float t = pow2(n/2);
	if (n%2 == 0)
		return t*t;
	return t*t*a;
}

class Arith
{
private:
	string E; //1+2+4-3+7
	//int('7') - int('0')
public:
	int getL() {return E.length();}
	void read();
	void print(int n);
	void printR(int n);
	float eval(int n);
};

void Arith::read()
{
	cout << "Enter a expression:";
	cin >> E;
}

void Arith::print(int n)
{
	if (n > 0)
	{
		print(n-1);
		cout << E[n-1];
	}
}

void Arith::printR(int n)
{
	if (n > 0)
	{
		cout << E[n-1];
		printR(n-1);
	}
}

float Arith::eval(int n)
{
	if (n == 1)
	{
		return (int(E[0]) - int('0'));
	}

	else
	{
			if (E[n-2] == '+')
			{
				E[n-3] += E[n-1] - int('0');
				return(eval(n - 2));
			}
			else
			{
				E[n-3] -= E[n-1] - int('0');
				return(eval(n - 2));
			}
	}

}

void main()
{
	Exp E;
	E.read();
	cout << E.pow1(E.getN()) << " " << E.pow2(E.getN()) << endl;

	Arith A;
	A.read();
	A.print(A.getL());
	cout << endl;
	A.printR(A.getL());
	cout << endl;
	cout << A.eval(A.getL()) << endl;
}