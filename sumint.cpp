//CSC191
//lab assignment #2 lab 2
//9/2/05
//Patrick Coe
//This program takes the sum of all digits in the number input, and displays them to the user.

#include <iostream>
using namespace std;

void main()
{
	int n(0), temp(0), c(0), l(0), d(1);


	cout << "please enter a positive integer: ";
	cin  >> n;

	temp = n;


	while (temp > 0)
	{
		c += (temp % 10);
		temp = temp/10;
	}



	cout << endl << "The sum of the digits of " << n << " is: " << c << endl;

}

		
		
