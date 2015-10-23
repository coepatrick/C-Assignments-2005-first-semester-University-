//CSC191
//Assignment#7 in lab
//Patrick Coe
//11/3/2005
//This program uses recursive functions to add, or subtract polynomials

#include <iostream>
#include <string>
using namespace std;


class Poly
{
private:
	int deg;
	float *p;
	float evalP(int deg, float x);
public:
	Poly(int d = -1) {deg = d;}
	friend istream& operator >>(istream& cin, Poly& P);
	friend ostream& operator <<(ostream& cout, Poly& P);
	friend Poly operator + (const Poly& P1, const Poly& Pr);
	friend Poly operator - (const Poly& P1, const Poly& Pr);
	float evaluate(float x);
	float* getP() {return p;}
};

istream& operator >>(istream& cin, Poly& P)
{
	delete [] P.p; //clear old array
	cout << "Enter the degree:";
	cin >> P.deg;

	P.p = new float[P.deg + 1];

	for(int i = 0; i <=  P.deg; i++)
	{
		cout << "Enter the coefficient of x^" << P.deg-i << ":";
		cin >> P.p[i];
	}

	return cin;
}

ostream& operator <<(ostream& cout, Poly& P)
{
	for (int i = P.deg; i > 0; i--)
		cout << P.p[P.deg-i] << "x^" << i << " + ";
	cout << P.p[P.deg] << endl;
	return cout;
}

Poly operator -(const Poly& P1,const Poly& Pr)
{
	Poly P;
	if (P1.deg >= Pr.deg)
	{
		P.deg = P1.deg;
		P.p = new float[P.deg];
		for (int i=0; i <= P.deg; i++)
			P.p[i] = P1.p[i];

		for (int i = 0; i <= Pr.deg; i++)
			P.p[i+(P1.deg-Pr.deg)] -= Pr.p[i];
	}
	else
	{
		P.deg = Pr.deg;
		P.p = new float[P.deg];
		for (int i=0; i <= Pr.deg; i++)
			P.p[i] = Pr.p[i];

		for (int i = 0; i <= Pr.deg; i++)
			if(i > P1.deg)
				P.p[i-P1.deg-1] = 0 - Pr.p[i-P1.deg-1];
			else
				P.p[i+(Pr.deg-P1.deg)] -= P1.p[i];
	}
	delete [] P1.p;
	delete [] Pr.p;
	return P;
}

Poly operator +(const Poly& P1,const Poly& Pr)
{
	Poly P;
	if (P1.deg >= Pr.deg)
	{
		P.deg = P1.deg;
		P.p = new float[P.deg];
		for (int i=0; i <= P.deg; i++)
			P.p[i] = P1.p[i];

		for (int i = 0; i <= Pr.deg; i++)
			P.p[i+(P1.deg-Pr.deg)] += Pr.p[i];
	}
	else
	{
		P.deg = Pr.deg;
		P.p = new float[P.deg];
		for (int i=0; i <= P.deg; i++)
			P.p[i] = Pr.p[i];

		for (int i = 0; i <= Pr.deg; i++)
			P.p[i+(Pr.deg-P1.deg)] += P1.p[i];
	}
	delete [] P1.p;
	delete [] Pr.p;
	return P;
}

float Poly::evaluate(float x)
{
	return evalP(deg, x); //recursive function
}

float Poly::evalP(int deg,float x)
{
	if (deg == 0)
		return p[0];
	return evalP(deg - 1, x)*x + p[deg];
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
		cout << " Multiply polynomial (not implemented)" <<endl;
		cout << "5. Evaluate polynomial" <<endl;
		cout << "6. Exit" << endl;


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
			cout << "Enter a value for x: ";
			cin  >> x;
			cout << P1.evaluate(x);
			break;
		case '6':
			//delete[] Poly.p;
			delete[] P1.getP();
			break;
		default:
			cout << "Invalid!, try again" << endl;
		}
	} while (res != '6');
}

