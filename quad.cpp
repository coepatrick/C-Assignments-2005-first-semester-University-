//CSC191
//lab #1
//8/10/05
//Patrick Coe
//This program reads a quadratic equation and solves the equation.

#include <iostream>
#include <math.h>
using namespace std;


void main()
{
	float A, B, C;

	cout << "Enter the equation:" << endl;
	cin  >> A >> B >> C;

	if (A == 0)
		if (B == 0)
			cout << "Invalid! Try again." << endl;
		else
			cout << "Equation is linear x = " << -C/B << endl;
	else
	{
		float dis = B*B - 4*A*C;
		if (dis < 0)
			cout << "Solutions are imaginary." << endl;
		else if (dis == 0)
			cout << "repeated root, x = " << -B/(2*A) << endl;
		else
		{
			cout << "x1 = " << (-B + sqrt(dis)) / (2*A) << endl;
			cout << "x2 = " << (-B - sqrt(dis)) / (2*A) << endl;
		}

	}

	cout << 7%7 << 6 % 7 << 5 % 7 << 4 % 7 << 3 % 7 << 2 % 7 << 1 % 7; 



}