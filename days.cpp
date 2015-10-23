//CSC191
//lab #1
//8/10/05
//Patrick Coe
//This program will take the month and date from a user, and display the day of the week

#include <iostream>
#include <math.h>
using namespace std;


void main()
{
	int month, date, total_days;
	char dayofweek; // L is sunday P is thursday


	cout << "Please enter the month and date(M D): " << endl;
	cin  >> month >> date;





		if ((date == 0) || (month > 12) || (month <= 0))

			cout << "invalid date" << endl;

		else
		{
			switch (month)
			{
				case 1:
					total_days = date - 1;
					break;
				case 2:
					total_days = 31 + date - 1;
					break;
				case 3:
					total_days = 31 + 28 + date - 1;
					break;
				case 4:
					total_days = 31 + 28 + 31 + date -1;
					break;
				case 5:
					total_days = 31 + 28 + 31 + 30 + date -1;
					break;
				case 6:
					total_days = 31 + 28 + 31 + 30 + 31 + date -1;
					break;
				case 7:
					total_days = 31 + 28 + 31 + 30 + 31 + 30 + date -1;
					break;
				case 8:
					total_days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + date -1;
					break;
				case 9:
					total_days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + date -1;
					break;
				case 10:
					total_days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + date -1;
					break;
				case 11:
					total_days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + date -1;
					break;
				case 12:
					total_days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + date -1;
					break;
				default:
					total_days = 0;
			}
		}
		

			total_days = total_days % 7;
			if(total_days == 0)
				dayofweek = 'S';
			else if(total_days == 6)
				dayofweek = 'F';
			else if(total_days == 5)
				dayofweek = 'P';
			else if(total_days == 4)
				dayofweek = 'W';
			else if(total_days == 3)
				dayofweek = 'T';
			else if(total_days == 2)
				dayofweek = 'M';
			else if(total_days == 1)
				dayofweek = 'L';
		


		if(dayofweek == 'M')
			cout << endl << " Today is Monday"    << endl;
		else if(dayofweek == 'T')
			cout << endl << " Today is Tuesday"   << endl;
		else if(dayofweek == 'W')
			cout << endl << " Today is Wednesday" << endl;
		else if(dayofweek == 'P')
			cout << endl << " Today is Thursday"  << endl;
		else if(dayofweek == 'F')
			cout << endl << " Today is Friday"    << endl;
		else if(dayofweek == 'S')
			cout << endl << " Today is Saturday"  << endl;
		else if(dayofweek == 'L')
			cout << endl << " Today is Sunday"    << endl;








}