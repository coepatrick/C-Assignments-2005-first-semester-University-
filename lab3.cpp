//CSC191
//Lab4
//9/16/05
//Patrick Coe
//This program diplays, reverses, sorts, searches and finds the maximum value of an array input by the user.


#include <iostream>
using namespace std;

class Arr
{
private:
	int A[100], n;
	void rotateR();
	void rotateL();
	void bubble();
	void selection();
	void insertion();

public:
	void readA();
	void printA();
	int maxA();
	void reverseA();
	void rotate();
	void sort();
	void search();
};



void Arr::insertion()
{
}

void Arr::selection()
{
	int i;
	int ti;

	for (int i = n-1; i > 0; i--)
		{
			ti = maxA();
			swap(ti, A[i]);
		}
}

void Arr::bubble()
{
	int cnt, cnt1, temp;
	bool swapped = true;

	while(swapped)
	{
	  swapped = false;

	  for(cnt=0; cnt < (n-1);cnt++)
	   {
	      if(A[cnt] > A[cnt+1])
			{
				swapped = true;
				swap(A[cnt], A[cnt+1]);
			}
	   }
	 }
}


void Arr::rotateR()
{
	int t = A[n-1];
	for (int i = n-2; i >= 0; i--)
	{
		A[i+1] = A[i];
	}
	A[0] = t;
}

void Arr::rotateL()
{

	int t = A[0];
	for (int i = 0; i <= n-2; i++)
	{
		A[i] = A[i+1];
	}
	A[n-1] = t;
}
void Arr::readA()
{
	int val;
	cout << "Enter an integer(-999 to stop):";
	cin >> val;
	n = 0;
	while ((val != -999) && (n < 100))
	{
		A[n++] = val;   //A[++n] = val;
		cout << "Enter an integer(-999 to stop):";
		cin >> val;
	}
}

void Arr::printA()
{
	for(int i = 0; i < n; i++)
		cout << A[i] << ' ';
	cout << endl;
}

int Arr::maxA()
{
	int m = A[0];
	for (int i = 1; i < n; i++)
		if (A[i] > m)
			m = A[i];
	return m;
}

void Arr::reverseA()
{
	for (int i = 0; i < n/2; i++)
	{
		int t = A[i];
		A[i] = A[n-1-i];
		A[n-1-i];
	}
}

void Arr::rotate()
{
	int res;


	cout << "1. rotate right" << endl;
	cout << "2. rotate left"  << endl;
	cout << "select:";

	cin >> res;

	if (res == 1)
		rotateR();
	else if (res == 2)
		rotateL();
	else
		cout << "invalid!";
}

void Arr::sort()
{
	int res;

	do
	{
		cout << "1. bubble" << endl;
		cout << "2. selection" << endl;
		cout << "3. insertion" << endl;
		cout << "4. exit" << endl;

		cout << "select:";

		cin >> res;

		switch (res)
		{
		case 1:
			bubble();
			break;
		case 2:
			selection();
			break;
		case 3:
			insertion();
			break;
		case 4:
			break;
		default:
			cout << "Invalid!, try again" << endl;
		}
	} while (res != 4);
}

void Arr::search()
{
}

void main()
{
Arr A;
int res;

	do
	{
		cout << "1. read array"  << endl;
		cout << "2. print array" << endl;
		cout << "3. find max"    << endl;
		cout << "4. reverse array"<<endl;
		cout << "5. rotate array"<< endl;
		cout << "6. sort array"  << endl;
		cout << "7. search array"<< endl;
		cout << "8. exit" << endl;

		cout << "select:";
		cin >> res;

		
		switch (res)
		{
		case 1:
			A.readA();
			break;
		case 2:
			A.printA();
			break;
		case 3:
			cout << "The max is " << A.maxA() << "." << endl;
			break;
		case 4:
			A.reverseA();
			break;
		case 5:
			A.rotate();
			break;
		case 6:
			A.sort();
			break;
		case 7:
			A.search();
			break;
		case 8:
			cout << "Thanks for using my program." << endl;
			break;
		default:
			cout << "Invalid!, try again" << endl;
		}
	} while (res != 8);
}

