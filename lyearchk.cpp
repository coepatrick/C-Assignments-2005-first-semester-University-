//CSC191
//lab assignment #2
//9/2/05
//Patrick Coe

#include <iostream>
using namespace std;

void main()
{
	int y;
	bool isleap;
	char res;

	do
	{
		cout << "Enter a year:" << endl;
		cin  >> y;

		isleap = false;

		if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
			isleap = true;

		if (isleap)
			cout << "year " << y << " is a leap year." << endl;
		else
			cout << "year " << y << " is not a leap year." << endl;

		cout << "Would you like to continue?(y or n)";
		cin  >> res;
	}
	while (res == 'y' || res == 'Y');

		cout << "Thanks for using my program" << endl;
}

		