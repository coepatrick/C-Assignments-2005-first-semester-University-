//CSC191
//Lab
//9/23/05
//Patrick Coe
//This program allows the user to generate an array, and then transpose or rotate it by 90 degrees, print out the highest number, and display the array.

#include <iostream>
using namespace std;


class Arr2
{
private:
	int A[10][10], size;
public:
	void generateA();
	void printA();
	int maxA();
	void transposeA();
	void rotate90();
	void showmaxA();
};

void Arr2::generateA()
{
	size = rand()%10+1;

	for(int r = 0; r < size; r++)
		for (int c = 0; c < size; c++)
			A[r][c] = rand()%10;

}

void Arr2::printA()
{
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
			cout << A[r][c] << " ";
		cout << endl;
	}
}

int Arr2::maxA()
{
	int max = A[0][0];
	for (int r = 0; r < size; r++)
		for (int c = 0; c < size; c++)
			if (A[r][c] > max)
				max = A[r][c];
	return max;
}

void Arr2::showmaxA()
{
	cout << "The max is: " << maxA() << endl;
}

void Arr2::transposeA()
{
	for (int r = 0; r < size; r++)
		for (int c = r+1; c < size; c++)
			//switch A[r][c] with A[c][r]
		{
			int t = A[r][c];
			A[r][c] = A[c][r];
			A[c][r] = t;
		}
}

void Arr2::rotate90()
{
	int t;
	transposeA();

	for(int r = 0; r < size; r++)
	{
		for(int c = size - 1; c >= size/2; c--)
		{

			t = A[r][size - c - 1];
			A[r][size - c - 1] = A[r][c];
			A[r][c] = t;

		}
	}
}		
		
void main()
{
	Arr2 A2;
	int res;

		do
	{

		cout << endl;
		cout << "Please make a selection" << endl;
		cout << "1. Generate array" << endl;
		cout << "2. Print array" << endl;
		cout << "3. Display Max" << endl;
		cout << "4. Transpose" << endl;
		cout << "5. Rotate 90 degrees" << endl;
		cout << "6. Exit" << endl; 

		cout << "select:";

		cin >> res;

		cout << endl;

		switch (res)
		{
		case 1:
			A2.generateA();
			break;
		case 2:
			A2.printA();
			break;
		case 3:
			A2.showmaxA();
			break;
		case 4:
			A2.transposeA();
			break;
		case 5:
			A2.rotate90();
			break;
		case 6:
			break;
		default:
			cout << "Invalid!, try again" << endl;
		}
	} while (res != 6);



}

