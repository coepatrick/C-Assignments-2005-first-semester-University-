//CSC191
//Lab 12
//11/18/2005
//Patrick Coe
//This program fills in an array with numbers in a sequence, forwards and backwards.


#include <iostream>
using namespace std;

void main()
{

int A[10][10], n;

n = 4;

//----------------------------------------

cout << "Part a: " << endl;

for (int r =0; r < n; r++)
	for (int c = 0; c < n; c++)
		A[r][c] = (r*n)+(c+1);

for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
			cout << A[r][c] << " ";
		cout << endl;
	}


	cout << endl << endl;
//------------------------------------------

cout << "Part b: " << endl;
for (int r =0; r < n; r++)
	for (int c = 0; c < n; c++)
		A[r][c] = (n*n) - ((r*n)+c);

for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
			cout << A[r][c] << " ";
		cout << endl;
	}

//----------------------------------------------

}
